#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QString>
#include "qtcommon2_global.h"

namespace QtCommon2 {

class QTCOMMON2SHARED_EXPORT FileUtil
{
public:
  static QString getFilteredFileName(const QString & filename);
    static bool isValidFileName(const QString & filename );
    static bool isValidFileNameWin32(const QString & filename );
    static bool isValidFileNameUnix(const QString & filename );
private:
    FileUtil();
    ~FileUtil();
};
}
#endif // FILEUTIL_H
