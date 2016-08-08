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

#ifndef BALOOLISTENER_H
#define BALOOLISTENER_H

#include <QObject>

class BalooListenerPrivate;
class AbstractAlbumModel;

class BalooListener : public QObject
{
    Q_OBJECT

    Q_PROPERTY(AbstractAlbumModel* model
               READ model
               WRITE setModel
               NOTIFY modelChanged)

public:
    explicit BalooListener(QObject *parent = 0);

    virtual ~BalooListener();

    AbstractAlbumModel* model() const;

Q_SIGNALS:

    void refreshContent();

    void modelChanged();

public Q_SLOTS:

void setModel(AbstractAlbumModel* model);

private:

    BalooListenerPrivate *d = nullptr;

};

#endif // BALOOLISTENER_H