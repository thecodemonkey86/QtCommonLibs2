#include "fileutil.h"
#include <QLocale>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include "qbytearrayview.h"
#endif
#include <QHash>
#include <exception/qtexception.h>
#include <QDebug>
#include <QThread>
#include <QCryptographicHash>

QString QtCommon2::FileUtil::getFilteredFileName(QString filename)
{
  return filename
      .replace(':','-')
      .replace('?','-')
      .replace('/','_')
      .replace('\\','_')
      .replace('\t','_')
      .remove(QChar('"'))
      .replace('|','_')
      .replace('*','_')
      .replace('<','_')
      .replace('>','_').trimmed();
}

QString QtCommon2::FileUtil::getNumberedFilePath(const QString &filePath)
{
  QString targetFilePath(filePath);
   QFileInfo fi(targetFilePath);
  int counter=1;
  while(QFile(targetFilePath).exists()) {
    targetFilePath = QStringLiteral("%1 (%2).%3").arg(fi.dir().absoluteFilePath(fi.completeBaseName()),QString::number(++counter),fi.suffix());

  }
  return targetFilePath;
}

QByteArray QtCommon2::FileUtil::md5(const QString &filePath)
{
  QCryptographicHash h(QCryptographicHash::Md5);
  QFile f(filePath);
  open(f,QIODevice::ReadOnly)  ;
  char buf[8192];
  int r;
  while((r=f.read(buf,sizeof(buf)))>0)
  {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    h.addData(QByteArrayView(buf,r));
#else
    h.addData(buf,r);
#endif
  }
  return h.result();

}

QByteArray QtCommon2::FileUtil::sha256(const QString &filePath)
{
  QCryptographicHash h(QCryptographicHash::Sha256);
  QFile f(filePath);
  open(f,QIODevice::ReadOnly)  ;
  char buf[8192];
  int r;
  while((r=f.read(buf,sizeof(buf)))>0)
  {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    h.addData(QByteArrayView(buf,r));
#else
    h.addData(buf,r);
#endif
  }
  return h.result();

}

QString QtCommon2::FileUtil::readAllUtf8(const QString &filePath)
{
  QFile f(filePath);
  open(f,QIODevice::ReadOnly);
  return QString::fromUtf8(f.readAll());
}

QByteArray QtCommon2::FileUtil::readAllBytes(const QString &filePath)
{
    QFile f(filePath);
    open(f,QIODevice::ReadOnly);
    return f.readAll();
}

void QtCommon2::FileUtil::saveToFile(const QString &filePath, const QByteArray & bytes)
{
    QFile f(filePath);
    open(f,QIODevice::WriteOnly);
    f.write(bytes);
}

QString QtCommon2::FileUtil::ensureFileExtension(const QString &filePath, const QString &ext)
{
  return filePath.endsWith("."+ext,Qt::CaseInsensitive) ? filePath : filePath+"."+ext;
}

bool QtCommon2::FileUtil::isValidFileName(const QString &filename)
{
#ifdef _WIN32
  return isValidFileNameWin32(filename);
#else
  return isValidFileNameUnix(filename);
#endif
}

bool QtCommon2::FileUtil::isValidFileNameWin32(const QString &filename)
{
  char forbidden[] = {
    0x22,
    0x3c,
    0x3e,
    0x7c,
    0x0,
    0x1,
    0x2,
    0x3,
    0x4,
    0x5,
    0x6,
    0x7,
    0x8,
    0x9,
        0xa,
        0xb,
        0xc,
        0xd,
        0xe,
        0xf,
        0x10,
        0x11,
        0x12,
        0x13,
        0x14,
        0x15,
        0x16,
        0x17,
        0x18,
        0x19,
        0x1a,
        0x1b,
        0x1c,
        0x1d,
        0x1e,
        0x1f,
        0x3a,
        0x2a,
        0x3f,
        0x5c,
        0x2f

    };

    if(filename.length() > 0) {
         for(uint j = 0;j < sizeof (forbidden); j++) {
             if(filename.contains(forbidden[j])) {
                return false;
             }
         }
        if (filename[0] == '.'
                || filename[filename.length()-1] == '.'
                || filename == QStringLiteral("CON")
                || filename == QStringLiteral("PRN")
                || filename == QStringLiteral("AUX")
                || filename == QStringLiteral("NUL")
                || filename == QStringLiteral("COM1")
                || filename == QStringLiteral("COM2")
                || filename == QStringLiteral("COM3")
                || filename == QStringLiteral("COM4")
                || filename == QStringLiteral("COM5")
                || filename == QStringLiteral("COM6")
                || filename == QStringLiteral("COM7")
                || filename == QStringLiteral("COM8")
                || filename == QStringLiteral("COM9")
                || filename == QStringLiteral("COM0")
                || filename == QStringLiteral("LPT1")
                || filename == QStringLiteral("LPT2")
                || filename == QStringLiteral("LPT3")
                || filename == QStringLiteral("LPT4")
                || filename == QStringLiteral("LPT5")
                || filename == QStringLiteral("LPT6")
                || filename == QStringLiteral("LPT7")
                || filename == QStringLiteral("LPT8")
                || filename == QStringLiteral("LPT9")
                || filename == QStringLiteral("LPT0")) {
            return false;
        }


    } else {
        return false;
    }
    return true;
}

bool QtCommon2::FileUtil::isValidFileNameUnix(const QString &filename)
{
    char forbidden[] = {
        '/',
        '\\',
        '>',
        '<',
        0x0,
        '|'
    };
    if(filename.length() > 0) {
         for(uint j = 0;j < sizeof (forbidden); j++) {
             if(filename.contains(forbidden[j])) {
                return false;
             }
         }
         if (filename[0] == '.') {
             return false;
         }
    } else {
        return false;
    }
    return true;
}

uint64_t QtCommon2::FileUtil::calcDirSize(const QDir & dir) {
  uint64_t size = 0;
  //calculate total size of current directories' files
  QDir::Filters fileFilters = QDir::Files|QDir::System|QDir::Hidden;
  for(QString filePath : dir.entryList(fileFilters)) {
    QFileInfo fi(dir, filePath);
    size+= static_cast<uint64_t>(fi.size());
  }
  //add size of child directories recursively
  QDir::Filters dirFilters = QDir::Dirs|QDir::NoDotAndDotDot|QDir::System|QDir::Hidden;
  for(QString childDirPath : dir.entryList(dirFilters))
    size+= calcDirSize(dir.path() + QDir::separator() + childDirPath);
  return size;
}

void QtCommon2::FileUtil::open(QFile &file, QIODevice::OpenMode openMode, int maxRetries)
{
  int count=0;
  do {
    if(file.open(openMode))
    {
      return;
    } else {
      qWarning().noquote() <<QStringLiteral("Failed to open file %1: %2").arg(file.fileName(), file.errorString());
      QThread::msleep(100);
    }
  } while( (count++) < maxRetries);
  throwExceptionWithLine(QStringLiteral("Finally failed to open file %1: %2").arg(file.fileName(), file.errorString()));
}


void QtCommon2::FileUtil::removeFile(QFile &file, int maxRetries)
{
  if(!file.exists())
  {
    return;
  }
  int count=0;
  do {
    if(file.remove())
    {
      return;
    } else {
      qWarning().noquote() <<QStringLiteral("Failed to remove file %1: %2").arg(file.fileName(), file.errorString());
      QThread::msleep(100);
    }
  } while( (count++) < maxRetries);
  throwExceptionWithLine(QStringLiteral("Finally failed to remove file %1: %2").arg(file.fileName(), file.errorString()));
}

void QtCommon2::FileUtil::removeFile(QFile &&file, int maxRetries)
{
  if(!file.exists()) {
    return;
  }
  int count=0;
  do {
    if(file.remove())
    {
      return;
    } else {
      qWarning().noquote() <<QStringLiteral("Failed to remove file %1: %2").arg(file.fileName(), file.errorString());
      QThread::msleep(100);
    }
  } while( (count++) < maxRetries);
  throwExceptionWithLine(QStringLiteral("Finally failed to remove file %1: %2").arg(file.fileName(), file.errorString()));
}

void QtCommon2::FileUtil::renameFile(QFile &file, const QString&newName, int maxRetries, bool forceOverwrite)
{
  int count=0;
  do {
    if(forceOverwrite)
    {
       QFile newFile(newName);
      if(newFile.exists())
      {
        removeFile(newFile);
      }
    }

    if(file.rename(newName))
    {
      return;
    } else {
      qWarning().noquote() <<QStringLiteral("Failed to rename file %1 to %2: %3").arg(file.fileName(),newName, file.errorString());
      QThread::msleep(100);
    }
  } while( (count++) < maxRetries);
  throwExceptionWithLine(QStringLiteral("Finally failed to rename file %1 to %2: %3").arg(file.fileName(),newName, file.errorString()));
}


void QtCommon2::FileUtil::renameFile(const QString &file,const QString&newName, int maxRetries, bool forceOverwrite)
{
  QFile f(file);
  renameFile(f,newName,maxRetries,forceOverwrite);
}

void QtCommon2::FileUtil::copyFile(QFile &file, const QString &newName, int maxRetries, bool forceOverwrite)
{
  int count=0;
  do {
    if(forceOverwrite)
    {
      QFile newFile(newName);
      if(newFile.exists())
      {
        removeFile(newFile);
      }
    }

    if(file.copy(newName))
    {
      return;
    } else {
      qWarning().noquote() <<QStringLiteral("Failed to rename file %1 to %2: %3").arg(file.fileName(),newName, file.errorString());
      QThread::msleep(100);
    }
  } while( (count++) < maxRetries);
  throwExceptionWithLine(QStringLiteral("Finally failed to rename file %1 to %2: %3").arg(file.fileName(),newName, file.errorString()));
}

QtCommon2::FileUtil::FileUtil()
{

}

QtCommon2::FileUtil::~FileUtil()
{

}
