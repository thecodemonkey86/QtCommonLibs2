#pragma once


#include "qtexception.h"

namespace QtCommon2 {

    class QTCOMMON2SHARED_EXPORT CancelException : public QtException
    {
    public:
        CancelException();
        CancelException(const QString &msg);
        virtual ~CancelException()=default;
    };
}
