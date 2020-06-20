/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#ifndef NS_APIHANDLER_H
#define NS_APIHANDLER_H

#include <QVariantMap>

#include "config.h"

#if QHTTPENGINE_VERSION_MAJOR < 1
#  include <QHttpEngine/QObjectHandler>
#  include <QHttpEngine/QHttpSocket>
#else
#  include <qhttpengine/qobjecthandler.h>
#  include <qhttpengine/socket.h>
#endif

#if QHTTPENGINE_VERSION_MAJOR < 1
class ApiHandler : public QObjectHandler
#else
class ApiHandler : public QHttpEngine::QObjectHandler
#endif
{
    Q_OBJECT

public:

    ApiHandler(const QString &token);

Q_SIGNALS:

    void itemsQueued(const QStringList &items);

public Q_SLOTS:

#if QHTTPENGINE_VERSION_MAJOR < 1
    QVariantMap version(const QVariantMap &params);
    QVariantMap sendItems(const QVariantMap &params);
#else
    void version(QHttpEngine::Socket *socket);
    void sendItems(QHttpEngine::Socket *socket);
#endif

private:

#if QHTTPENGINE_VERSION_MAJOR < 1
    void process(QHttpSocket *socket, const QString &path);
#endif

    const QString mToken;
};

#endif // NS_APIHANDLER_H
