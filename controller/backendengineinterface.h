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

#ifndef BACKENDENGINEINTERFACE_H
#define BACKENDENGINEINTERFACE_H

#include <QObject>

#include "networking/discoveryserver.h"

namespace controller {

	/*!
	 * \brief BackendEngineInterface is a class responsible for interfacing 
	 *        the UI with the backend.
	 *
	 * BackendEngineInterface is a C++ object that is added to the QML root 
	 * context. This way QML UI objects can communicate back with the backend.
	 */
	class BackendEngineInterface : public QObject
	{
	    Q_OBJECT
	public:
	    explicit BackendEngineInterface(QObject *parent = 0);

	    bool initialize();

	    bool startNetworkingServices();

	signals:

	public slots:

	private:
	    Q_DISABLE_COPY(BackendEngineInterface)

	    networking::DiscoveryServer m_discoveryServer;

	};

} // namespace controller

#endif // BACKENDENGINEINTERFACE_H
