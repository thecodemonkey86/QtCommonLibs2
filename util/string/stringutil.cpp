#include "stringutil.h"

#include <QRegularExpression>
#include <QTextDecoder>


QString QtCommon2::StringUtil::ucFirst(const QString &str)
{
    return str[0].toUpper() + str.mid(1);
}

QString QtCommon2::StringUtil::fromCp1252(const QByteArray &data)
{
    QTextDecoder* decoder = QTextCodec::codecForName("Windows-1252")->makeDecoder();
    return  decoder->toUnicode(data,data.length());
}

bool QtCommon2::StringUtil::isValidEmail(const QString &email)
{
    QRegularExpression regex(QStringLiteral("^[0-9a-zA-Z]+([0-9a-zA-Z][-._+])[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)([0-9a-zA-Z][.])[a-zA-Z]{2,6}$"));
    return !regex.match(email).hasMatch();
}

QtCommon2::StringUtil::StringUtil()
{
}

QString& QtCommon2::StringUtil::replaceFirst( QString &subject, const QString & search, const QString & replace)
{
    int k=subject.indexOf(search);
    if (k>-1) {
        return subject.replace(k, search.size(), replace);
    }
    return subject;
}


int QtCommon2::StringUtil::firstIndexOfMultiple(const QString & s,int start, const QVector<QChar>& c ) {
        for(int i=start;i<s.length();i++) {
            for(int j=0;j<c.size();j++) {
                if (s[i] == c[j]) {
                    return i;
                }
            }
        }
        return -1;
    }

QString QtCommon2::StringUtil::randString( int length,const QString &chars)
{
    QString s(length, QChar('0'));

    for(int i=0;i<length;i++) {
        s[i] = chars[rand()%chars.length()];
    }
    return s;
}

