/**
 * @file  buffer/buffer.hpp.
 *
 * Declares the buffer class
 */

#ifndef __MOGL_BUFFER_GL_BUFFER_HPP__
#define __MOGL_BUFFER_GL_BUFFER_HPP__

#include "mogl/base/object.hpp"
#include "mogl/buffer/buffer_access.hpp"
#include "mogl/buffer/buffer_usage.hpp"
#include <stdexcept>

namespace mogl
{
template <typename T>
class GLbuffer final : public GLobject<GLbuffer<T>>
{
  friend class GLcontext;
public:
  /**
   * Destructor
   *
   * @author  jkstpierre
   * @date  8/30/2020
   */
  ~GLbuffer() noexcept
  {
    glDeleteBuffers(1, &mID);
  }

  /**
   * Fill data
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   pData The data.
   * @param   size  The size.
   * @param   usage The usage.
   */
  void fillData(const T* pData, GLsizeiptr size, GLbufferUsage usage) noexcept
  {
    glNamedBufferData(mID, size, pData, usage);
  }

  /**
   * Fill subdata
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   pData   The data.
   * @param   offset  The offset.
   * @param   size    The size.
   */
  void fillSubdata(const T* pData, GLintptr offset, GLsizeiptr size) noexcept
  {
    glNamedBufferSubData(mID, offset, size, pData);
  }
  
  /**
   * Returns a raw pointer to the Buffer's address space.
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @param   access  The access.
   *
   * @returns Null if it fails, else a pointer to a T.
   */
  T* map(GLbufferAccess access) noexcept
  {
    return glMapNamedBuffer(mID, access);
  }

  /**
   * Unmaps this 
   *
   * @author  jkstpierre
   * @date  8/31/2020
   *
   * @returns True if it succeeds, false if it fails.
   */
  bool unmap() noexcept
  {
    return glUnmapNamedBuffer(mID);
  }

private:
  /**
   * Default constructor
   *
   * @author  jkstpierre
   * @date  8/30/2020
   */
  GLbuffer()
  {
    glCreateBuffers(1, &mID);
    if ( !mID )
    {
      throw std::runtime_error("Failed to create GLbuffer.");
    }
  }
};
}

#endif