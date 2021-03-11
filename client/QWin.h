/*
 * QDigiDocClient
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#pragma once

#include "QCryptoBackend.h"

#include <qt_windows.h>
#include <ncrypt.h>

class QWin: public QCryptoBackend
{
	Q_OBJECT
public:
	explicit QWin(QObject *parent = nullptr): QCryptoBackend(parent) {}

	void logout() override {};

protected:
	int derive(NCRYPT_PROV_HANDLE prov, NCRYPT_KEY_HANDLE key, const QByteArray &publicKey, const QString &digest, int keySize,
		const QByteArray &algorithmID, const QByteArray &partyUInfo, const QByteArray &partyVInfo, QByteArray &derived) const;

	NCRYPT_HANDLE keyProvider(NCRYPT_HANDLE key) const;
	static QByteArray prop(NCRYPT_HANDLE handle, LPCWSTR param, DWORD flags = 0);
};
