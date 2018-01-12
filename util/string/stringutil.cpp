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


int QtCommon2::StringUtil::firstIndexOfMultiple(const QString & s,int start, const QVector<QChar>& c ) {
        for(int i=start;i<s.length();i++) {
            for(int j=0;j<c.size();j++) {
                if (s[i] == c[j]) {
                    return i;
                }
            }
        }
        return -1;
    }
