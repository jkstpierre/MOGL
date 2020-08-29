/**
 * @file  mogl/loaders.hpp.
 *
 * Declares the loaders for OpenGL depending on the OS
 */

#ifndef __MOGL_LOADERS_HPP__
#define __MOGL_LOADERS_HPP__

#include "mogl/platform.hpp"

#include "mogl/ext/glad/gl.h"
#if defined(MOGL_OS_WINDOWS)
#include <Windows.h>
#include <WindowsX.h>
#include "mogl/ext/glad/wgl.h"
#elif defined(MOGL_OS_LINUX)
#include <X11/Xlib.h>
#include "mogl/ext/glad/glx.h"
#endif

#endif
