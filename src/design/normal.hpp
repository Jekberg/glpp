/*
 * File:    normal.hpp
 * Author:  John Berg
 * Date:    03/11/2017
 */

#ifndef GLPP_SRC_DESIGN_NORMAL_HPP
#define GLPP_SRC_DESIGN_NORMAL_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Functions.
    /**
     * @brief Submit a normal.
     * @param nml The reference to a normal to be submitted.
     */
    void normal(const float_vector3& nml) noexcept;
    /**
     * @brief Submit a normal.
     * @param nml THe rvalue reference to be submitted.
     */
    void normal(const float_vector3&& nml) noexcept;
}

#endif //GLPP_SRC_DESIGN_NORMAL_HPP
