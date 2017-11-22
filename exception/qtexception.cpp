#include "qtexception.h"

QtException::QtException(const QString &msg) : exception()
{
    this->msg = msg;
}

QtException::~QtException()
{

}

const QString &QtException::getMsg() const
{
    return msg;
}
