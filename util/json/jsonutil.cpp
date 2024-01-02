#include "jsonutil.h"
#include <QJsonArray>
namespace QtCommon2 {
QStringList JsonUtil::toStringList(const QJsonArray &arr)
{
    QStringList list;
    list.reserve(arr.size());
    for(const auto & v:arr)
    {
        list += v.toString();
    }
    return list;
}

}
