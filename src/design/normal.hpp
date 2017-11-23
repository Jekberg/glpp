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
    //Typedefs.
    /**
     *
     */
    typedef vector_base<3, float_type> normal3;
    //==========================================================================
    //Functions.
    /**
     * @param
     */
    void normal(const normal3& nml) noexcept;
    /**
     * @param
     */
    void normal(const normal3&& nml) noexcept;
}

#endif //GLPP_SRC_DESIGN_NORMAL_HPP
