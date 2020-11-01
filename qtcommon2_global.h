#pragma once


#include <QtCore/qglobal.h>

#if defined(QTCOMMON2_LIBRARY)
#  define QTCOMMON2SHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTCOMMON2SHARED_EXPORT Q_DECL_IMPORT
#endif

