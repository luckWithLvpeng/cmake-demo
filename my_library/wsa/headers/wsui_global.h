#ifndef WSA_GLOBAL_H
#define WSA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WSA_LIBRARY)
#  define WSA_EXPORT Q_DECL_EXPORT
#else
#  define WSA_EXPORT Q_DECL_IMPORT
#endif

#endif // WSA_GLOBAL_H
