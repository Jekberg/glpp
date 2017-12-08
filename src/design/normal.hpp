#ifndef GLPP_SRC_DESIGN_NORMAL_HPP
#define GLPP_SRC_DESIGN_NORMAL_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Functions.
    /**
     * This methods is equivelant to glNormal3f(GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a normal.
     * @param nml The reference to a normal to be submitted.
     */
    void normal(const float_vector3& nml) noexcept;
    /**
     * This methods is equivelant to glNormal3f(GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a normal.
     * @param nml THe rvalue reference to be submitted.
     */
    void normal(const float_vector3&& nml) noexcept;
}

#endif //GLPP_SRC_DESIGN_NORMAL_HPP
