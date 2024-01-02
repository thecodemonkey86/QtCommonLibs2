#include "autoremovedir.h"

#include <qdebug.h>

AutoRemoveDir::AutoRemoveDir(const QDir &d, int maxRetries) : d(d),maxRetries(maxRetries)
{}

AutoRemoveDir::~AutoRemoveDir()
{
    int count=0;
    do {
        if(d.removeRecursively())
        {
           return;
        } else {
            qCritical()<<"failed to remove "<<d.absolutePath();
        }

    } while( (count++) < maxRetries);
}
