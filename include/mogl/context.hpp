/**
 * @file  mogl/context.hpp.
 *
 * Declares the context class
 */

#ifndef __MOGL_CONTEXT_HPP__
#define __MOGL_CONTEXT_HPP__

#include "mogl/loaders.hpp"
#include "mogl/allocator.hpp"
#include <cstdint>

namespace mogl
{
/** The context major version */
const unsigned CONTEXT_MAJOR_VERSION = 4U;

/** The context minor version */
const unsigned CONTEXT_MINOR_VERSION = 6U;

/** Forward declaration of the Allocator */
class Allocator;

/**
 * An OS independent OOP compliant OpenGL 4.6 context.
 *
 * @author  jkstpierre
 * @date  8/28/2020
 */
class Context final
{
public:
#if defined(MOGL_OS_WINDOWS)
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  8/28/2020
   *
   * @param   color     The color bits.
   * @param   depth     The depth bits.
   * @param   stencil   The stencil bits.
   * @param   antialias The antialias samples.
   * @param   dc        The Windows device-context.
   */
  Context(uint8_t color, uint8_t depth, uint8_t stencil, uint8_t antialias, HDC dc);

#elif defined(MOGL_OS_LINUX)
  /**
   * Constructor
   *
   * @author  jkstpierre
   * @date  8/28/2020
   *
   * @param   color     The color bits.
   * @param   depth     The depth bits.
   * @param   stencil   The stencil bits.
   * @param   antialias The antialias samples.
   * @param   window    The X11 window.
   */
  Context(uint8_t color, uint8_t depth, uint8_t stencil, uint8_t antialias, Window window);

#endif
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  8/28/2020
   */
  ~Context() noexcept;

  // Delete copy constructor and copy assignment
  Context(const Context&) = delete;
  Context& operator=(const Context&) = delete;

  // TODO: Implement move constructor and assignment, but for now, lets just delete them
  Context(Context&&) noexcept = delete;
  Context& operator=(Context&&) noexcept = delete;

public:
  /**
   * Gets the allocator
   *
   * @author  jkstpierre
   * @date  8/29/2020
   *
   * @returns The allocator.
   */
  Allocator& getAllocator() noexcept;

private:
  /** True if an OpenGL Context is active (prevents multiple contexts from coexisting) */
  static bool sActive;

#if defined(MOGL_OS_WINDOWS)
  /** The device context this OpenGL context is tied to */
  HDC mDeviceContext;

  /** Handle to the active OpenGL context */
  HGLRC mOpenGLContext;

#elif defined(MOGL_OS_LINUX)

#endif

  /** The Allocator for OpenGL objects*/
  Allocator mAllocator;
};
}

#endif

