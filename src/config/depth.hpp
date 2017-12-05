#ifndef GLPP_SRC_CONFIG_DEPTH_HPP
#define GLPP_SRC_CONFIG_DEPTH_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Functions.
    /**
     * This function is equivalent to glDepthFunc(GLenum).
     *
     * @brief Specify the depth buffer comparison.
     * @param mode The comparison_mode function.
     */
    inline void depth_comparision(comparision_mode mode)
    {
        glDepthFunc(static_cast<GLenum>(mode));
    }
} //glpp

#endif //GLPP_SRC_CONFIG_DEPTH_HPP
