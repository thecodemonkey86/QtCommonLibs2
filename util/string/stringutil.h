#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <QString>
#include <QVector>
namespace QtCommon2 {

    class Q_DECL_EXPORT StringUtil
    {
    public:
        StringUtil();
        static QString& replaceFirst( QString &subject, const QString & search, const QString & replace);
        static int firstIndexOfMultiple(const QString &s, int start, const QVector<QChar> &c);
        static QString ucFirst( const QString &str);
        static bool isValidEmail(const QString & email);
       static QString randString(int length,const QString&chars="abcdefghijklmnoprstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    };


}

#endif // STRINGUTIL_H
