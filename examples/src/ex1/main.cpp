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

#include <mogl/mogl.hpp>
#include <mogl/objects/gl_vertex_array.hpp>
#include <mogl/objects/gl_buffer.hpp>

int main()
{
  Display *dsp = XOpenDisplay(nullptr);
  Window wnd = XCreateSimpleWindow(dsp, DefaultRootWindow(dsp), 0, 0, 800, 600, 0, 0, 0);

  XMapWindow(dsp, wnd);

  mogl::ModernOpenGL gl(32, 24, 8, 4, dsp, wnd);

  gl.setVerticalSync(true);

  auto vao = gl.alloc<mogl::objects::GLvertexArray>();

  printf("GLvertexArray id = %u\n", vao->getID());

  auto vbo = gl.alloc<mogl::objects::GLbuffer<float>>();
  
  gl.free(vao);

  return 0;
}