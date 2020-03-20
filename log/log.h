#ifndef LOG_H
#define LOG_H
#include "exception/qtexception.h"
namespace  QtCommon2 {
    class QTCOMMON2SHARED_EXPORT Log
    {
    private:
        static QString name;
    public:
        static void init(const QString& name);
        Log();
        ~Log();
    public: static void logException(const QtException &e);
    };
}


#endif // LOG_H
