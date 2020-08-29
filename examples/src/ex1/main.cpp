/**
 * @file main.cpp
 * @author jkstpierre (jkstpierre@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2020-07-26
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <mogl/context.hpp>
#include <cstdio>
#include <stdexcept>

#if defined(MOGL_OS_WINDOWS)

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ INT nCmdShow)
{
  try
  {
    HWND window = CreateWindowEx(0, "Window Class", "Modern OpenGL Example", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hInstance, nullptr);
    mogl::Context gl = mogl::Context(32, 24, 8, 1, GetDC(window));

    OutputDebugString("Context created successfully.\n");
  }
  catch ( std::exception& e )
  {
    OutputDebugString(e.what());
  }

  return 0;
}

#elif defined(MOGL_OS_LINUX)

int main()
{
  return 0;
}

#endif