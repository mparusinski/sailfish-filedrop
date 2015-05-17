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

#include "devices.h"

#include "common/sailfish-postbox-defines.h"

namespace networking {

	Device::Device(
		const QHostAddress& deviceAddress,
		const QString& deviceName,
		quint16 postboxVersion,
		QObject *parent
	) : QObject(parent)
	{
		m_deviceAddress = deviceAddress;
		m_deviceName = deviceName;
		m_postboxVersion = postboxVersion;
	}

	Device::~Device()
	{

	}

	Device * readDevice(const QHostAddress& address, QDataStream& stream)
	{
		quint16 postboxVersion = 0;
		char deviceName[DEVICE_NAME_STRING_SIZE];
		stream.readRawData(deviceName, DEVICE_NAME_STRING_SIZE);

		// TODO: Put this in a separate function
		// ------------------------------------------------
		// Check the device name character array is valid
		bool valid = false;
		for (int i = 0; i < DEVICE_NAME_STRING_SIZE; i++) {
			if (deviceName[i] == '\0') {
				valid = true;
				break;
			}
		}
		// ------------------------------------------------

		if (!valid)
			return NULL;

		QString qDeviceName(deviceName);
		stream >> postboxVersion;

		if (postboxVersion < DEVICE_MIN_VERSION_SUPPORTED || postboxVersion > DEVICE_MAX_VERSION_SUPPORTED)
			return NULL;

		Device * newDevice = new Device(address, qDeviceName, postboxVersion);
		return newDevice;
	}

} // namespace networking
