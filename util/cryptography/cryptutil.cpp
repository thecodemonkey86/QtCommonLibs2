#include "cryptutil.h"

#include <QCryptographicHash>
using namespace QtCommon2;

CryptUtil::CryptUtil()
{

}

QString CryptUtil::md5AsString(const QString &s)
{
  return QString::fromLatin1(QCryptographicHash::hash(s.toUtf8(),QCryptographicHash::Md5).toHex());
}

QString CryptUtil::md5AsString(const QByteArray &data)
{
  return QString::fromLatin1(QCryptographicHash::hash(data,QCryptographicHash::Md5).toHex());
}

QByteArray CryptUtil::md5(const QByteArray &data)
{
  return QCryptographicHash::hash(data,QCryptographicHash::Md5).toHex();
}
