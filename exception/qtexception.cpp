#include "qtexception.h"

QtCommon2::QtException::QtException()
{
  this->line = 0;
}

QtCommon2::QtException::QtException(const QString &msg)
{
    this->line = 0;
    this->msg = msg;
}

QtCommon2::QtException::QtException(const QString &msg, const QString &file, int line)
{
    this->line = line;
    this->file = file;
    this->msg = msg;
}


const QString & QtCommon2::QtException::getMsg() const
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
    return QLatin1String("%1, file: %2 in line %3").arg(getMsg(),file,QString::number(line));
  }
  return getMsg();
}

int QtCommon2::QtException::getLine() const
{
    return line;
}

