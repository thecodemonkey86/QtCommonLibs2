#ifndef EXC_H
#define EXC_H

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
};

}


#endif // EXC_H
