#include "cancelexception.h"

QtCommon2::CancelException::CancelException()
{

}

QtCommon2::CancelException::CancelException(const QString &message) : QtException(message)
{

}

