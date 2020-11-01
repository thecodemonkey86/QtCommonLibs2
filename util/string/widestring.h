#ifndef WIDESTRING_H
#define WIDESTRING_H

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


#endif // WIDESTRING_H
