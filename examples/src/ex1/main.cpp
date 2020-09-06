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
#include "mogl/vertex_array/vertex_array.hpp"
#include "mogl/buffer/buffer.hpp"
#include "mogl/shader_program/program.hpp"
#include "mogl/shader_program/pipeline.hpp"
#include "mogl/texture/texture_1d.hpp"
#include <cstdio>
#include <stdexcept>
#include <string>

#if defined(MOGL_OS_WINDOWS)
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ INT nCmdShow)
#elif defined(MOGL_OS_LINUX)
int main(int argc, char** args)
#endif
{
  try
  {
    HWND window = CreateWindowA("STATIC", "Modern OpenGL Test", WS_POPUP | WS_DISABLED, 0, 0, 1, 1, NULL, NULL, GetModuleHandle(NULL), NULL);
    auto gl = mogl::GLcontext(32, 24, 8, 4, GetDC(window));

    auto vao = gl.hAlloc<mogl::GLvertexArray>();
    auto ebo = gl.sAlloc<mogl::GLbuffer<GLuint>>();

    vao->setElementBuffer(&ebo);

    vao->bind();
    vao->attribute(0).format(4, mogl::GLtype::_FLOAT, GL_FALSE, 0);

    auto vertex_shader = gl.hAlloc<mogl::GLshader>(
      mogl::GLshaderType::_VERTEX,
      R"(
        #version 460 core

        layout (location = 0) in vec3 vPos;
        layout (location = 1) in vec3 vColor;
        
        out vec3 fColor;

        void main() 
        {
          gl_Position = vec4(vPos, 1.0);
          fColor = vColor;
        }
      )");

    auto fragment_shader = gl.hAlloc<mogl::GLshader>(
      mogl::GLshaderType::_FRAGMENT,
      R"(
        #version 460 core
        
        out vec4 fragmentColor;

        in vec3 fColor;

        void main()
        {
          fragmentColor = vec4(fColor, 1.0);
        }
      )"
    );

    auto program = gl.sAlloc<mogl::GLprogram>(GL_FALSE, *vertex_shader, *fragment_shader);
    /*auto pipeline = gl.sAlloc<mogl::GLpipeline>();

    pipeline.attachProgram(program);
    pipeline.use();*/

    auto& viewport = gl.getViewport();
    std::string viewportString = "Viewport = {" + std::to_string(viewport[0]) + ", " + std::to_string(viewport[1]) + ", " + std::to_string(viewport[2]) + ", " + std::to_string(viewport[3]) + "}\n";
    OutputDebugString(viewportString.c_str());

    gl.setActiveBinary(program);
    gl.drawArrays(*vao, mogl::GLdrawMode::_TRIANGLES, 0, 10);

    auto tex = gl.sAlloc<mogl::GLtexture1d>(3, mogl::GLtextureFormat::_RGBA, 250);
    std::string texInfo = "Texture = {" + std::to_string(tex.getID()) + ", " + std::to_string(tex.getDimensions().at(0)) + "}\n";
    OutputDebugString(texInfo.c_str());
  }
  catch ( std::exception& e )
  {
    OutputDebugString(std::string(std::string(e.what()) + "\n").c_str());
  }

  return 0;
}