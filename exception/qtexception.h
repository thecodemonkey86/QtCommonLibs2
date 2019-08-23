#ifndef QTEXCEPTION_H
#define QTEXCEPTION_H

#include <exception>
#include <QString>
#include "qtcommon2_global.h"
#define throwExceptionWithLine(msg) throw QtCommon2::QtException(msg, __FILE__, __LINE__)
namespace QtCommon2 {
class Q_DECL_EXPORT QtException : public std::exception
{
public:
    QtException();
    QtException(const QString& msg);
    QtException(const QString& msg,const QString & file,int line);
    virtual ~QtException() override ;



    const QString & getMsg() const;
    int getLine() const;
    const QString & getFile() const;

    QString getLogString() const;
private:
    int line;
    QString file;
    QString msg;

    // exception interface
public:
    virtual const char *what() const noexcept  override;

};

}


#endif // QTEXCEPTION_H
