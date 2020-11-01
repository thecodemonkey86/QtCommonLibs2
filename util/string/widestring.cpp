#include "widestring.h"


QtCommon2::WideString::WideString(const QString &str)
{

    this->chars = new wchar_t[static_cast<unsigned long long>(str.length()) + 1];
    str.toWCharArray(this->chars);
    this->chars[str.length()] = '\0';
}

QtCommon2::WideString::~WideString()
{
    delete [] this->chars;
}

const wchar_t *QtCommon2::WideString::str() const
{
    return chars;
}
