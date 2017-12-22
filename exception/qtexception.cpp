#include "qtexception.h"

QtCommon2::QtException::QtException(const QString &msg) : exception()
{
    this->msg = msg;
}

QtCommon2::QtException::~QtException()
{

}

const QString &QtCommon2::QtException::getMsg() const
{
    return msg;
}
