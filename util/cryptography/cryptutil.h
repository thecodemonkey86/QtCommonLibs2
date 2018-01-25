#ifndef CRYPTUTIL_H
#define CRYPTUTIL_H
#include <QString>
#include "qtcommon2_global.h"
namespace QtCommon2 {
    class QTCOMMON2SHARED_EXPORT CryptUtil
    {
    public:
        CryptUtil();
       static QString getRandomString(int length);

    };
}
#endif // CRYPTUTIL_H
