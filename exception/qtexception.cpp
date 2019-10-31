#include "qtexception.h"

QtCommon2::QtException::QtException()
{
  this->line = 0;
}

QtCommon2::QtException::QtException(const QString &msg) : exception()
{
    this->msg = msg;
    this->line = 0;
}

QtCommon2::QtException::QtException(const QString &msg, const QString &file, int line)
{
    this->msg = msg;
    this->line = line;
    this->file = file;
}

QtCommon2::QtException::~QtException()
{

}

const QString &QtCommon2::QtException::getMsg() const
{
    return msg;
}

const QString & QtCommon2::QtException::getFile() const
{
  return file;
}

QString QtCommon2::QtException::getLogString() const
{
  if(line>0) {
    return QStringLiteral("%1, file: %2 in line %3").arg(msg,file,QString::number(line));
  }
  return msg;
}

int QtCommon2::QtException::getLine() const
{
    return line;
}

const char *QtCommon2::QtException::what() const noexcept
{
    return msg.toUtf8().data();
}
