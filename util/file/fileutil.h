#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QDir>
#include <QString>
#include "qtcommon2_global.h"

namespace QtCommon2 {

class QTCOMMON2SHARED_EXPORT FileUtil
{
public:
    static bool isValidFileName(const QString & filename );
    static bool isValidFileNameWin32(const QString & filename );
    static bool isValidFileNameUnix(const QString & filename );
    static uint64_t calcDirSize(const QDir & dir);

    static void open(QFile & file, QIODevice::OpenMode openMode, int maxRetries=100);
    static void removeFile(QFile &file, int maxRetries=100);
    static void removeFile(QFile &&file, int maxRetries=100);
    static void renameFile(QFile &file, const QString &newName, int maxRetries=100);

    static QString getFilteredFileName(QString filename);


private:
    FileUtil();
    ~FileUtil()=default;
};
}
#endif // FILEUTIL_H
