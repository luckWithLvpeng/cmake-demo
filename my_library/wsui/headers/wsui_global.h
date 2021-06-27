#ifndef WSUI_GLOBAL_H
#define WSUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WSUI_LIBRARY)
#  define WSUI_EXPORT Q_DECL_EXPORT
#else
#  define WSUI_EXPORT Q_DECL_IMPORT
#endif

#endif // WSUI_GLOBAL_H
