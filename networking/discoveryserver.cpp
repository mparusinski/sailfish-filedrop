/*
 * Copyright (c) 2015 Michal Parusinski <mparusinski@gmail.com>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "discoveryserver.h"

#include <QByteArray>
#include <QHostAddress>
#include <QDataStream>

#include "common/sailfish-postbox-defines.h"

namespace networking
{
	DiscoveryServer::DiscoveryServer(QObject * parent) : QObject(parent)
	{
		m_receiverSocket = NULL;
	}

	DiscoveryServer::~DiscoveryServer()
	{
		if (m_receiverSocket != NULL)
		{
			delete m_receiverSocket;
		}
	}

	bool DiscoveryServer::initialize()
	{
		if (m_receiverSocket != NULL)
			return true; // Already initialized

		m_receiverSocket = new QUdpSocket(this);
		if (m_receiverSocket == NULL) {
			// TODO: Report memory allocation error
			return false;
		}

		return true;
	}

	bool DiscoveryServer::startServer() 
	{
		stopAnyRunningServer();
		// TODO: Check we are on a supported network
		if (!m_receiverSocket->bind(DISCOVERY_PORT_NUMBER, QUdpSocket::DontShareAddress))
			return false;
		connect(m_receiverSocket, &QUdpSocket::readyRead, this, &DiscoveryServer::readPendingDatagrams);
		return true;
	}

	void DiscoveryServer::stopAnyRunningServer()
	{
		if (m_receiverSocket->isOpen())
			m_receiverSocket->close();
	}

	void DiscoveryServer::readPendingDatagrams()
	{
		while (m_receiverSocket->hasPendingDatagrams()) {
			QByteArray datagram;
			QHostAddress sender;
			quint16 senderPort;

			datagram.resize(m_receiverSocket->pendingDatagramSize());
			m_receiverSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

			QDataStream packetStream(datagram);
			Device * device = readDevice(sender, packetStream);
			if (device != NULL) {
				Device::DevicePtr devicePointer(device);
				emit foundSailfishDevice(devicePointer);
			}
		}
	}

}
