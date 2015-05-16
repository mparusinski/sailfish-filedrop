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

#ifndef DEVICES_H
#define DEVICES_H

#include <QObject>
#include <QSharedPointer>
#include <QHostAddress>
#include <QString>
#include <QDataStream>

namespace networking {

	/*!
	 * \brief Device is an object representing a device which we can talk to
	 *
	 * Device provide all the information describing a device on the network and 
	 * offers the ability to interact with it remotely
	 */
	class Device : public QObject
	{
	    Q_OBJECT
	public:
		typedef QSharedPointer<Device> DevicePtr;

		explicit Device(
			const QHostAddress& deviceAddress,
			const QString& deviceName,
			quint16 postboxVersion,
			QObject *parent = 0
		);

		virtual ~Device();

	signals:

	public slots:

	private:
		Q_DISABLE_COPY(Device)

		QHostAddress m_deviceAddress;
		QString m_deviceName;
		quint16 m_postboxVersion;
	};

	/*!
	 * \ brief Function takes a datastream as input and returns an newly allocated
	 *         device. Function does not take ownership of the pointer
	 * \returns null if device could not be allocated, newly allocated device if possibly
	 */
	Device * readDevice(const QHostAddress& address, QDataStream& stream);

}

#endif // DEVICES_H
