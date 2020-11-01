#include "qtexception.h"

QtCommon2::QtException::QtException()
{
  this->line = 0;
}

QtCommon2::QtException::QtException(const QString &msg) : std::exception(msg.toUtf8().data())
{
    this->line = 0;
}

QtCommon2::QtException::QtException(const QString &msg, const QString &file, int line): std::exception(msg.toUtf8().data())
{
    this->line = line;
    this->file = file;
}


QString QtCommon2::QtException::getMsg() const
{
    return QString(what());
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

