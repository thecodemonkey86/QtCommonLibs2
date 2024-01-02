#ifndef CANCELEXCEPTION_H
#define CANCELEXCEPTION_H

#include "qtexception.h"

namespace QtCommon2 {

    class QTCOMMON2SHARED_EXPORT CancelException : public QtException
    {
    public:
        CancelException();
        CancelException(const QString &msg);
        virtual ~CancelException();
    };
}
#endif // CANCELEXCEPTION_H
