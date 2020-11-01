#ifndef QTEXCEPTION_H
#define QTEXCEPTION_H

#include <exception>
#include <QString>
#include "qtcommon2_global.h"
#define throwExceptionWithLine(msg) throw QtCommon2::QtException(msg, __FILE__, __LINE__)
namespace QtCommon2 {
class QTCOMMON2SHARED_EXPORT QtException : public std::exception
{
public:
    QtException();
    QtException(const QString& msg);
    QtException(const QString& msg,const QString & file,int line);
    virtual ~QtException() override =default;



    QString getMsg() const;
    int getLine() const;
    const QString & getFile() const;

    virtual QString getLogString() const;
protected:
    int line;
    QString file;


};

}


#endif // QTEXCEPTION_H
