#pragma once
#include "qtcommon2_global.h"
#include <functional>
using std::function;
#include <QList>
namespace QtCommon2 {
    class QTCOMMON2SHARED_EXPORT Finally
    {
        QList<function<void()>> functions;
    public:
        Finally()=default;
        Finally(function<void()> fn);
        ~Finally();
        void add(function<void()> fn);
        void prepend(function<void()> fn);
        void operator += (function<void()> fn);
    };


};
