#include "log.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#ifdef QT_DEBUG
#include <QDebug>
#endif
using namespace QtCommon2;

void Log::init(const QString &name)
{
    Log::name = name;
}

Log::Log()
{

}

Log::~Log()
{

}

void Log::logException(const QtException &e)
{
#ifdef QT_DEBUG
    qDebug()<<e.getMsg();
#endif
    QFile file(Log::name);
    if (!file.open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out <<QDateTime::currentDateTime().toString(QString("dd.MM.yyyy hh:mm:ss"))<<": " << e.getMsg() << '\n';
    file.close();
}

QString Log::name;
