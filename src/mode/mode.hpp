/* 
 * File:    mode.hpp
 * Author:  John
 * Date:    28/10/2017
 */

#ifndef MODE_HPP
#define MODE_HPP

#include <GL/gl.h>

namespace glpp
{
    /**
     */
    enum class vertex_mode: GLenum
    {
        POINTS          = GL_POINTS,
        LINES           = GL_LINES,
        LINE_STRIP      = GL_LINE_STRIP,
        LINE_LOOP       = GL_LINE_LOOP,
        TRIANGLES       = GL_TRIANGLES,
        TRIANGLE_STRIP  = GL_TRIANGLE_STRIP,
        TRIANGLE_FAN    = GL_TRIANGLE_FAN,
        QUAD            = GL_QUADS,
        QUAD_STRIP      = GL_QUAD_STRIP,
        POLYGIN         = GL_POLYGON
    };
    /**
     */
    enum class list_mode: GLenum
    {
        COMPILE             = GL_COMPILE,
        COMPILE_AND_EXECUTE = GL_COMPILE_AND_EXECUTE
    };
} //glpp

#endif //MODE_HPP