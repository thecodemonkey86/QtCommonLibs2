#include <QDir>
#include <qtcommon2_global.h>
#pragma once


class QTCOMMON2SHARED_EXPORT AutoRemoveDir
{
    QDir d;
    int maxRetries;
public:
    explicit AutoRemoveDir(const QDir &d,int maxRetries=10);
    ~AutoRemoveDir();
};

