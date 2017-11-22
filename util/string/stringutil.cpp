#include "stringutil.h"

QtCommon2::StringUtil::StringUtil()
{
}

QString& QtCommon2::StringUtil::replaceFirst( QString &subject, const QString & search, const QString & replace)
{
    int k=subject.indexOf(search);
    if (k>-1) {
        return subject.replace(k, search.size(), replace);
    }
    return subject;
}
