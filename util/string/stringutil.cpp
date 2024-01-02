#include "stringutil.h"

#include <QRandomGenerator>
#include <QRegularExpression>
#include <QLocale>
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include <QTextDecoder>
#endif

QString QtCommon2::StringUtil::ucFirst(const QString &str)
{
    return str[0].toUpper() + str.mid(1);
}
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
QString QtCommon2::StringUtil::fromCp1252(const QByteArray &data)
{
    QTextDecoder* decoder = QTextCodec::codecForName("Windows-1252")->makeDecoder();
    return  decoder->toUnicode(data,data.length());
}

QByteArray QtCommon2::StringUtil::toCp1252(const QString &str)
{
  return QTextCodec::codecForName("Windows-1252")->makeEncoder()->fromUnicode(str);
}
#endif

QtCommon2::StringUtil::StringUtil()
{
}

QString& QtCommon2::StringUtil::replaceFirst( QString &subject, const QString & search, const QString & replace)
{
  return replaceFirst(0,subject,search,replace);
}
QString& QtCommon2::StringUtil::replaceFirst( qsizetype i, QString &subject, const QString & search, const QString & replace)
{
    int k=subject.indexOf(search,i);
    if (k>-1) {
        return subject.replace(k, search.size(), replace);
    }
    return subject;
}

int QtCommon2::StringUtil::firstIndexOfMultiple(const QString & s,int start, const QVector<QChar>& c ) {
        for(int i=start;i<s.length();i++) {
            for(int j=0;j<c.size();j++) {
                if (s[i] == c[j]) {
                    return i;
                }
            }
        }
        return -1;
    }

QString QtCommon2::StringUtil::randString( int length,const QString &chars)
{
    QString s(length, QChar('0'));

    for(int i=0;i<length;i++) {
      s[i] = chars[QRandomGenerator::global()->bounded(chars.length())];
    }
    return s;
}

std::unique_ptr<wchar_t[]> QtCommon2::StringUtil::toWCharT(const QString &s)
{

    wchar_t* c_Text = new wchar_t[static_cast<unsigned long long>(s.length()) + 1];
    s.toWCharArray(c_Text);
    c_Text[s.length()] = '\0';
    return std::unique_ptr<wchar_t[]>(c_Text);
}

QString QtCommon2::StringUtil::fileSizeToString(int64_t size)
{
    if(size >= 1024*1024*1024)
    {
       return QLocale::system().toString(size/(1024.0*1024*1024),'f',1)+" GB";
    } else if(size >= 1024*1024)
    {
        return QLocale::system().toString(size/(1024.0*1024),'f',1)+" MB";
    } else if(size >= 1024)
    {
        return QLocale::system().toString(size/1024.0,'f',1)+" KB";
    } else
    {
        return QLocale::system().toString(static_cast<double>(size),'g',1)+" B";
    }



}

