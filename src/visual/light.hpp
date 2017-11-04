/* 
 * File:    light.hpp
 * Author:  John Berg
 * Date:    02/11/2017
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <GL/gl.h>

namespace glpp
{
    //==========================================================================
    //Enums.
    /**
     * 
     */
    enum class light_mode: GLenum
    {
        AMBIENT     = GL_AMBIENT,
        DIFFUSE     = GL_DIFFUSE,
        SPECULAR    = GL_SPECULAR
    };
    
    class light
    {
    public:
        
    };
} //glpp

#endif //LIGHT_HPP