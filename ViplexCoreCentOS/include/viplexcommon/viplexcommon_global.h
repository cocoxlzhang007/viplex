#pragma once
#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(VIPLEXCOMMON_LIB)
#  define VIPLEXCOMMON_EXPORT Q_DECL_EXPORT
# else
#  define VIPLEXCOMMON_EXPORT Q_DECL_IMPORT
# endif
#else
# define VIPLEXCOMMON_EXPORT
#endif