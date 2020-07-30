/**
 * @file platform.hpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOGL_PLATFORM_HPP__
#define __MOGL_PLATFORM_HPP__

// Include OpenGL
#include <mogl/ext/glad/gl.h>

#if defined(_WIN32)
#define MOGL_OS_WINDOWS
#include <Windows.h>
#include <WindowsX.h>
#elif defined(__linux__)
#define MOGL_OS_LINUX
#include <X11/Xlib.h>
#include <mogl/ext/glad/glx.h>
#elif defined(__APPLE__)
#define MOGL_OS_APPLE
#endif

#endif