#include "cancelexception.h"

CancelException::CancelException()
{

}

CancelException::CancelException(const QString &msg) : QtException(msg)
{

}
