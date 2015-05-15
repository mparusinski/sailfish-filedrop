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

#ifndef NETWORKDISCOVERYTHREAD_H
#define NETWORKDISCOVERYTHREAD_H

#include <QThread>
#include <QSharedPointer>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QList>
#include <QLinkedList>

#include "devices.h"

namespace networking {

#define DEFAULT_WAITING_TIME 5
#define NO_CONNECTION_WAITING_TIME 1

	/*!
	 * \brief NetworkDiscoveryThread is the thread responsible for discovery 
	 *        sailfish devices on the local network.
	 *
	 * NetworkDiscoveryThread is a thread that polls the local network for
	 * sailfish devices. It also keeps checking if the devices are available.
	 * The thread also takes care of informing the UI when connecting is lost
	 * or when a connection is made.
	 */
	class NetworkDiscoveryThread : public QThread
	{
	    Q_OBJECT
	public:
		typedef QSharedPointer<NetworkDiscoveryThread> NetworkDiscoveryThreadPtr;

		explicit NetworkDiscoveryThread(QThread *parent = 0);

	    void run();

	signals:
		void discoveredNewDevice(Device::DevicePtr& device);

		void lostConnectionToDevice(Device::DevicePtr& device);

	public slots:

	private:
		typedef QLinkedList<Device::DevicePtr> DeviceCollection;
		typedef QMutableLinkedListIterator<Device::DevicePtr> MutableDeviceCollectionIterator;

		Q_DISABLE_COPY(NetworkDiscoveryThread)

		/*!
		 * \brief Check all known Sailfish Postbox devices to see if they are still online
		 * \return Number of devices lost due to timeout
		 */
		unsigned int pingKnownNetworkDevices();

		/*!
		 * \brief Check local network for new Sailfish devices
		 * \return Number of new devices found
		 */
		unsigned int pollNetworkForNewDevices();

		/*!
		 * \brief Force the thread to sleep m_secondsToWait number of seconds
		 */
		void waitInBetweenNetworkPolling() const;

		unsigned long m_secondsToWait;
		DeviceCollection m_devices;
		LocalNetworkProfile m_localNetworkProfile;
	};
}

#endif // NETWORKDISCOVERYTHREAD_H
