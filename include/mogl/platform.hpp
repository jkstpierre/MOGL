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

// Replace gl.h with glad.h
#include <mogl/ext/glad/glad.h>

#if defined(_WIN32)
#define MOGL_OS_WINDOWS
#include <Windows.h>
#include <WindowsX.h>
#include <GL/GL.h>
#elif defined(__linux__)
#define MOGL_OS_LINUX
#include <X11/Xlib.h>
#include <mogl/ext/glad/glad_glx.h>
#include <sys/time.h>
#elif defined(__APPLE__)
#define MOGL_OS_APPLE
#endif

#endif