#pragma once


#include <QString>


namespace QtCommon2 {
class WideString
{
    wchar_t* chars;
public:
    WideString(const QString&str);
    ~WideString();
    const wchar_t *str() const;
};
}


