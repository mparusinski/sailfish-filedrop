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

namespace networking {

	/*!
	 * \brief NetworkDiscoveryThread is the thread responsible for discovery 
	 *        sailfish devices on the local network. [SINGLETON]
	 *
	 * NetworkDiscoveryThread is a thread that polls the local network for
	 * sailfish devices. It also keeps checking if the devices are available.
	 * The thread also takes care of informing the UI when connecting is lost
	 * or when a connection is made.
	 *
	 * NetworkingDiscoveryThread is a singleton class and should be invoked
	 * using getNetworkDiscoveryThread()
	 */
	class NetworkDiscoveryThread : public QThread
	{
	    Q_OBJECT
	public:
		/*!
		 * \brief getInstance is a function that returns the unique instance of 
		 *        the class.
		 * \warning To get the singleton instance please use 
		 *          getNetworkDiscoveryThread
		 */
		static NetworkDiscoveryThread* getInstance();

	    void run();

	signals:

	public slots:

	private:
		Q_DISABLE_COPY(NetworkDiscoveryThread)
		explicit NetworkDiscoveryThread(QThread *parent = 0);

		static NetworkDiscoveryThread* instance;
	};

	/*!
	 * \brief returns the unique instance of NetworkDiscoverThread
	 */
	NetworkDiscoveryThread* getNetworkDiscoveryThread();							

}

#endif // NETWORKDISCOVERYTHREAD_H
