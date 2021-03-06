/*
 * Copyright 2016 Matthieu Gallien <matthieu_gallien@yahoo.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef LOCALBALOOFILELISTING_H
#define LOCALBALOOFILELISTING_H

#include "../abstractfile/abstractfilelisting.h"

#include <QObject>
#include <QString>
#include <QUrl>
#include <QHash>
#include <QVector>

#include <memory>

class LocalBalooFileListingPrivate;
class MusicAudioTrack;
class QDBusPendingCallWatcher;

class LocalBalooFileListing : public AbstractFileListing
{

    Q_OBJECT

public:

    explicit LocalBalooFileListing(QObject *parent = nullptr);

    ~LocalBalooFileListing() override;

    void applicationAboutToQuit() override;

Q_SIGNALS:

public Q_SLOTS:

    void renamedFiles(const QString &from, const QString &to, const QStringList &listFiles);

    void serviceOwnerChanged(const QString &serviceName, const QString &oldOwner, const QString &newOwner);

    void serviceRegistered(const QString &serviceName);

    void serviceUnregistered(const QString &serviceName);

    void fixBalooConfiguration();

    void disableBalooIndexer();

private Q_SLOTS:

    void newBalooFile(const QString &fileName);

    void registeredToBaloo(QDBusPendingCallWatcher *watcher);

private:

    void registerToBaloo();

    void executeInit() override;

    void triggerRefreshOfContent() override;

    MusicAudioTrack scanOneFile(const QUrl &scanFile) override;

    bool checkBalooConfiguration();

    std::unique_ptr<LocalBalooFileListingPrivate> d;

};

#endif // LOCALBALOOFILELISTING_H
