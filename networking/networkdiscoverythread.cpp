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

#include "networkdiscoverythread.h"

#include <QHostAddress>

namespace networking {

	NetworkDiscoveryThread::NetworkDiscoveryThread(QThread *parent) : QThread(parent)
	{
		m_secondsToWait = DEFAULT_WAITING_TIME; // Starting value is 5 seconds
	}

	void NetworkDiscoveryThread::run()
	{	
		forever {
			m_localNetworkProfile.acquireNetworkingInterfaceInformation();
			if (m_localNetworkProfile.anyValidNetworkInterface()) {
				pingKnownNetworkDevices();
				pollNetworkForNewDevices();
				m_secondsToWait = DEFAULT_WAITING_TIME;
			} else { 
				// Will check network connectivity more often because
				// 1 - There is no new devices to find
				// 2 - There are no addresses to poll
				m_secondsToWait = NO_CONNECTION_WAITING_TIME;
			}
			waitInBetweenNetworkPolling();
		}
	}

	unsigned int NetworkDiscoveryThread::pingKnownNetworkDevices() 
	{
		int countLost = 0;
		MutableDeviceCollectionIterator iter(m_devices);
		while (m_devices.hasNext()) {
			Device::DevicePtr device = iter.next();
			if (!device->pingDevice()) {
				countLost++;
				iter.remove();
			}
		}
		return countLost;
	}

	unsigned int NetworkDiscoveryThread::pollNetworkForNewDevices()
	{

	}

	void NetworkDiscoveryThread::waitInBetweenNetworkPolling() const
	{
		sleep(m_secondsToWait);
	}

} // namespace networking
