#pragma once

#include <QString>
#include "qtcommon2_global.h"
namespace QtCommon2 {
    class QTCOMMON2SHARED_EXPORT CryptUtil
    {
    public:
        CryptUtil();
        static QString md5AsString(const QString & s);
        static QString md5AsString(const QByteArray & data);
        static QByteArray md5(const QByteArray &data);
    };
}
