/* 
 * File:    depth_.hpp
 * Author:  John Berg
 * Date:    29/10/2017
 */

#ifndef DEPTH_HPP
#define DEPTH_HPP

#include <GL/gl.h>

namespace glpp
{
    //==========================================================================
    //Enums.
    /**
     * The depth comparison functions available.
     */
    enum class comparision: GLenum
    {
        NEVER       = GL_NEVER,
        LESS        = GL_LESS,
        EQUAL       = GL_EQUAL,
        LEQUAL      = GL_LEQUAL,
        GREATER     = GL_GREATER,
        NOTEQUAL    = GL_NOTEQUAL,
        GEQUAL      = GL_GEQUAL,
        ALWAYS      = GL_ALWAYS
    };
    //==========================================================================
    //Functions.
    /**
     * Specify the depth buffer comparison.
     * 
     * @param mode The <code>glpp::comparison</code> function.
     */
    inline void depth_comparision(comparision mode)
    {
        glDepthFunc((GLenum) mode);
    }
} //glpp

#endif //DEPTH_HPP