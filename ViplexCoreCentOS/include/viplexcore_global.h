#pragma once

// DARWIN
#if defined(__APPLE__) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__))
#include <QtCore/qcompilerdetection.h>
#ifndef BUILD_STATIC
# if defined(VIPLEXCORE_LIB)
#  define VIPLEX_EXPORT Q_DECL_EXPORT
# else
#  define VIPLEX_EXPORT Q_DECL_IMPORT
# endif
#else
# define VIPLEX_EXPORT
#endif
// ANDROID
#elif defined(__ANDROID__) || defined(ANDROID)
#include <QtCore/qcompilerdetection.h>
#ifndef BUILD_STATIC
# if defined(VIPLEXCORE_LIB)
#  define VIPLEX_EXPORT Q_DECL_EXPORT
# else
#  define VIPLEX_EXPORT Q_DECL_IMPORT
# endif
#else
# define VIPLEX_EXPORT
#endif

// Windows
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <stdint.h>
# if defined(VIPLEXCORE_LIB)
#  define VIPLEX_EXPORT  __declspec(dllexport)
# else
#  define VIPLEX_EXPORT __declspec(dllimport)
#endif
// LINUX
#elif defined(__linux__) || defined(__linux)
#include <stdint.h>
# if defined(VIPLEXCORE_LIB)
#  define VIPLEX_EXPORT __attribute__((visibility("default")))
# else
#  define VIPLEX_EXPORT __attribute__((visibility("default")))
#endif
#else
#  define VIPLEX_EXPORT
#endif





