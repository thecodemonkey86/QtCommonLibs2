#include "cryptutil.h"

#include <QCryptographicHash>
using namespace QtCommon2;

CryptUtil::CryptUtil()
{

}

QString CryptUtil::getRandomString(int length) {
    QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

    QString randomString;
    for(int i=0; i<length; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

QString CryptUtil::md5(const QString &s)
{
  return QString::fromLatin1(QCryptographicHash::hash(s.toUtf8(),QCryptographicHash::Md5).toHex());
}
