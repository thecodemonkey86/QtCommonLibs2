#include "fileutil.h"

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

QtCommon2::FileUtil::FileUtil()
{

}

QtCommon2::FileUtil::~FileUtil()
{

}
