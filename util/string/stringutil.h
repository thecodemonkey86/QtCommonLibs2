#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <QRandomGenerator>
#include <QString>
#include <QVector>
#include "qtcommon2_global.h"

namespace QtCommon2 {

    class QTCOMMON2SHARED_EXPORT StringUtil
    {
    public:
        StringUtil();
        static QString& replaceFirst( QString &subject, const QString & search, const QString & replace);
        static int firstIndexOfMultiple(const QString &s, int start, const QVector<QChar> &c);
        static QString ucFirst( const QString &str);
        static QString fromCp1252( const QByteArray &data);
        static QByteArray toCp1252( const QString &str);
        static bool isValidEmail(const QString & email);
       static QString randString(int length,const QString&chars="abcdefghijklmnoprstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
       static wchar_t * toWCharT(const QString &s);
    };


}

#endif // STRINGUTIL_H
