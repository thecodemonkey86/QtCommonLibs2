#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QDir>
#include <QString>
#include "qtcommon2_global.h"
#include <memory>
namespace QtCommon2 {

class QTCOMMON2SHARED_EXPORT FileUtil
{
public:
  static QString ensureFileExtension(const QString & filePath, const QString&ext);
    static bool isValidFileName(const QString & filename );
    static bool isValidFileNameWin32(const QString & filename );
    static bool isValidFileNameUnix(const QString & filename );
    static uint64_t calcDirSize(const QDir & dir);

    static void open(QFile & file, QIODevice::OpenMode openMode, int maxRetries=10);
    static void removeFile(QFile &file, int maxRetries=10);
    static void removeFile(QFile &&file, int maxRetries=10);
    static void renameFile(QFile &file, const QString &newName, int maxRetries=10, bool forceOverwrite=false);
    static QString getFilteredFileName(QString filename);

    static QString  getNumberedFilePath(const QString & filePath);
    static QByteArray md5(const QString & filePath );

    static QByteArray sha256(const QString &filePath);
    static QString readAllUtf8(const QString & filePath);
    static QByteArray readAllBytes(const QString & filePath);
    static void saveToFile(const QString &filePath, const QByteArray &bytes);

    static void renameFile(const QString &file, const QString &newName, int maxRetries=10, bool forceOverwrite=false);
    static void copyFile(QFile &file, const QString &newName, int maxRetries=10, bool forceOverwrite=false);
  private:
    FileUtil();
    ~FileUtil();
};
}
#endif // FILEUTIL_H
