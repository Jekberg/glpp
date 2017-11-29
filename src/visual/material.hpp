/*
 * File:   material.hpp
 * Author: John
 *
 * Created on 03 November 2017, 23:45
 */

#ifndef GLPP_SRC_VISUAL_MATERIAL_HPP
#define GLPP_SRC_VISUAL_MATERIAL_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Enums.
    enum class face: GLenum
    {
        FRONT           = GL_FRONT,
        BACK            = GL_BACK,
        FRONT_AND_BACK  = GL_FRONT_AND_BACK
    };
    //==========================================================================
    //Functions.
    void shininess(face p_face, const float_type shininess_value);
    void material(
            face p_face,
            const glpp::vector_base<4, float_type>& v);
}

#endif //GLPP_SRC_VISUAL_MATERIAL_HPP
