#ifndef CANCELEXCEPTION_H
#define CANCELEXCEPTION_H

#include "qtexception.h"

using namespace QtCommon2;

class Q_DECL_EXPORT CancelException : public QtException
{
public:
    CancelException();
};

#endif // CANCELEXCEPTION_H