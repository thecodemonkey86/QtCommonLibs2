#pragma once

#include <QString>
#include "qtcommon2_global.h"

#define throwExceptionWithLine(msg) QtCommon2::QtException::logWarningAndThrow(msg,__FILE__,__LINE__);

#define throwExceptionWarningWithLine( logMsg ) QtCommon2::QtException::logWarningAndThrow(logMsg,__FILE__,__LINE__);
#define throwExceptionWarningWithDisplayAndLine( displayMsg, logMsg )  QtCommon2::QtException::logWarningAndThrow(displayMsg, logMsg,__FILE__,__LINE__);

#define throwExceptionCriticalWithLine( logMsg ) QtCommon2::QtException::logCriticalAndThrow(logMsg,__FILE__,__LINE__);
#define throwExceptionCriticalWithDisplayAndLine( displayMsg, logMsg )  QtCommon2::QtException::logCriticalAndThrow(displayMsg, logMsg,__FILE__,__LINE__);

namespace QtCommon2 {
class QTCOMMON2SHARED_EXPORT QtException
{
public:
    QtException();
    QtException(const QString& msg);

    [[noreturn]] static void logWarningAndThrow(const QString & displayMsg, const QString & logMsg,const QString & file,int line);
    [[noreturn]] static void logWarningAndThrow(const QString & logMsg,const QString & file,int line);
    [[noreturn]] static void logCriticalAndThrow(const QString &displayMsg, const QString &logMsg, const QString &file, int line);
    [[noreturn]] static void logCriticalAndThrow(const QString &logMsg, const QString &file, int line);

    QtException(const QString& msg,const QString & file,int line);
    virtual ~QtException()=default;
    const QString & getMsg() const;


    int getLine() const;


    const QString & getFile() const;


    virtual QString getLogString() const;


protected:
    int line;
    QString file;
    QString msg;


};

}


