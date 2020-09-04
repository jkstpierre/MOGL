/**
 * @file  platform.hpp.
 *
 * Determines the OS this compilation is taking place for
 */

#ifndef __MOGL_PLATFORM_HPP__
#define __MOGL_PLATFORM_HPP__

#include "mogl/ext/glad/gl.h"
#if defined(_WIN32)
#define MOGL_OS_WINDOWS
#include <Windows.h>
#include <WindowsX.h>
#include "mogl/ext/glad/wgl.h"
#elif defined(__linux__)
#define MOGL_OS_LINUX
#include <X11/Xlib.h>
#include "mogl/ext/glad/glx.h"
#endif

#endif