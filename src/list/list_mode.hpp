/* 
 * File:    list_mode.hpp
 * Author:  John
 * Date:    28/10/2017
 */

#ifndef LIST_MODE_HPP
#define LIST_MODE_HPP

#include <GL/gl.h>

namespace glpp
{
    enum class list_mode: GLenum
    {
        COMPILE             = GL_COMPILE,
        COMPILE_AND_EXECUTE = GL_COMPILE_AND_EXECUTE
    };
} //glpp

#endif //LIST_MODE_HPP