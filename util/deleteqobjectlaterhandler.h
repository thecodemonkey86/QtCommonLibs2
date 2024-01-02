
#pragma once

#include <qtcommon2_global.h>


#include "qobject.h"
class QTCOMMON2SHARED_EXPORT DeleteQObjectLaterHandler
{
    QObject * o;
public:
    DeleteQObjectLaterHandler(QObject * o);
    ~DeleteQObjectLaterHandler();
};

