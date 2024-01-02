#pragma once
#include <qtcommon2_global.h>
#include <QStringList>

class QJsonArray;
namespace QtCommon2 {
class QTCOMMON2SHARED_EXPORT JsonUtil
{
public:
    JsonUtil()=delete;
    static QStringList toStringList(const QJsonArray & arr);
};


}
