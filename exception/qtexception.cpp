#include "qtexception.h"
#include <QDebug>
QtCommon2::QtException::QtException():line(0)
{
}

QtCommon2::QtException::QtException(const QString &msg) : msg(msg),line(0)
{
}

void QtCommon2::QtException::logWarningAndThrow(const QString &displayMsg, const QString &logMsg, const QString &file, int line)
{
  qWarning().noquote() << QStringLiteral("Exception: \"%1\" in file %2, line %3").arg(logMsg).arg(file).arg(line);
  throw QtCommon2::QtException(displayMsg.isNull() ? logMsg : displayMsg);
}

void QtCommon2::QtException::logWarningAndThrow(const QString &logMsg, const QString &file, int line)
{
  qWarning().noquote() << QStringLiteral("Exception: \"%1\" in file %2, line %3").arg(logMsg).arg(file).arg(line);
  throw QtCommon2::QtException(logMsg);
}

void QtCommon2::QtException::logCriticalAndThrow(const QString &displayMsg, const QString &logMsg, const QString &file, int line)
{
  qCritical().noquote() << QStringLiteral("Exception: \"%1\" in file %2, line %3").arg(logMsg).arg(file).arg(line);
  throw QtCommon2::QtException(displayMsg.isNull() ? logMsg : displayMsg);
}

void QtCommon2::QtException::logCriticalAndThrow(const QString &logMsg, const QString &file, int line)
{
  qCritical().noquote() << QStringLiteral("Exception: \"%1\" in file %2, line %3").arg(logMsg).arg(file).arg(line);
  throw QtCommon2::QtException(logMsg);
}
QtCommon2::QtException::QtException(const QString &msg, const QString &file, int line) : msg(msg), file(file),line(line)
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

