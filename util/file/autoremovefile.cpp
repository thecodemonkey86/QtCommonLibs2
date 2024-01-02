#include "autoremovefile.h"

#include <QFile>
#include <QThread>
#include <QDebug>

QtCommon2::AutoRemoveFile::AutoRemoveFile(const QString &file,int maxRetries):file(file),maxRetries(maxRetries)
{
}

QtCommon2::AutoRemoveFile::AutoRemoveFile(const QFile &file,int maxRetries):file(file.fileName()),maxRetries(maxRetries)
{
}

QtCommon2::AutoRemoveFile::AutoRemoveFile(const QFile &&file,int maxRetries):file(file.fileName()),maxRetries(maxRetries)
{

}

QtCommon2::AutoRemoveFile& QtCommon2::AutoRemoveFile::operator=(QtCommon2::AutoRemoveFile&& rhs)
{
    this->remove();
    this->file = std::move(rhs.file);
    this->maxRetries = rhs.maxRetries;
    rhs.file.clear();
    return *this;
}

void QtCommon2::AutoRemoveFile::remove()
{
    if (this->file.isEmpty()) {
        return;
    }
    QFile file(this->file);
    if (!file.exists()) {
        return;
    }
    int count = 0;
    do {
        if (file.remove()) {
            return;
        } else {
            qWarning().noquote() << QStringLiteral("Failed to remove file %1: %2").arg(file.fileName(), file.errorString());
            QThread::msleep(100);
        }
    } while ((count++) < maxRetries);
}
