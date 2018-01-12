#ifndef QTEXCEPTION_H
#define QTEXCEPTION_H

#include <exception>
#include <QString>
namespace QtCommon2 {
class Q_DECL_EXPORT QtException : public std::exception
{
public:
    QtException(const QString& msg);

    virtual ~QtException() ;



    const QString & getMsg() const;

private:
    QString msg;

    // exception interface
public:
    virtual const char *what() const noexcept  override;
};

}


#endif // QTEXCEPTION_H
