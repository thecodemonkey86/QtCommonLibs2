
#include "deleteqobjectlaterhandler.h"

DeleteQObjectLaterHandler::DeleteQObjectLaterHandler(QObject *o) : o(o)
{

}

DeleteQObjectLaterHandler::~DeleteQObjectLaterHandler()
{
    o->deleteLater();
}

