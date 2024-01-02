#include "finally.h"
#include <QDebug>

namespace QtCommon2 {
    Finally::Finally(function<void ()> fn)
    {
        add(fn);
    }

    Finally::~Finally()
    {
        for(auto fn : functions)
        {
            try {
                 fn();
            } catch (...) {
                 qCritical()<<__FILE__<< ": must not throw exceptions";
            }

        }
    }

    void Finally::add(function<void ()> fn)
    {
        functions += fn;
    }

    void Finally::prepend(function<void ()> fn)
    {
        functions.prepend(fn);
    }

    void Finally::operator +=(function<void ()> fn)
    {
        functions += fn;
    }

}
