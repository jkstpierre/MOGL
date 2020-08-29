/**
 * @file  platform.hpp.
 *
 * Determines the OS this compilation is taking place for
 */

#ifndef __MOGL_PLATFORM_HPP__
#define __MOGL_PLATFORM_HPP__

#if defined(_WIN32)
#define MOGL_OS_WINDOWS
#elif defined(__linux__)
#define MOGL_OS_LINUX
#endif

#endif