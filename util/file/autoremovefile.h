#include <QString>
#include <qtcommon2_global.h>
#pragma once
class QFile;
namespace QtCommon2 {
class QTCOMMON2SHARED_EXPORT AutoRemoveFile
{
  QString file;
  int maxRetries;
public:
  explicit AutoRemoveFile(const QString & file,int maxRetries=10);
  explicit AutoRemoveFile(const QFile & file,int maxRetries=10);
  explicit AutoRemoveFile(const QFile && file,int maxRetries=10);

  AutoRemoveFile(const AutoRemoveFile&) = delete;
  AutoRemoveFile& operator=(const AutoRemoveFile&) = delete;

  AutoRemoveFile(AutoRemoveFile&& rhs)
      : file(std::move(rhs.file))
      , maxRetries(rhs.maxRetries)
  {
      rhs.file.clear();
  }

  AutoRemoveFile& operator=(AutoRemoveFile&& rhs);

  ~AutoRemoveFile() { remove(); }

  const QString& getFilepath() const { return file; }

private:
  void remove();
};
}


