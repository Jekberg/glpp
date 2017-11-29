/*
 * File:    light.hpp
 * Author:  John Berg
 * Date:    02/11/2017
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Enums.
    enum class light_source: GLenum
    {
        LIGHT0 = GL_LIGHT0,
        LIGHT1 = GL_LIGHT1,
        LIGHT2 = GL_LIGHT2,
        LIGHT3 = GL_LIGHT3,
        LIGHT4 = GL_LIGHT4,
        LIGHT5 = GL_LIGHT5,
        LIGHT6 = GL_LIGHT6,
        LIGHT7 = GL_LIGHT7,
    };
    //==========================================================================
    //Functions.
    void light(
            light_source src,
            light_mode mode,
            const vector_base<4, float_type>& v);
    void light(
            light_source src,
            light_mode mode,
            const vector_base<4, float_type>&& v);
    void light_at(
            light_source src,
            const vector_base<4, float_type>& v);
    void light_at(
            light_source src,
            const vector_base<4, float_type>&& v);
} //glpp

#endif //LIGHT_HPP
