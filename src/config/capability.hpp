/*
 * File:    capability.hpp
 * Author:  John Berg
 * Date:    29/10/2017
 */

#ifndef CAPABILITY_HPP
#define CAPABILITY_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Enums.
    /**
     * The available capabilities.
     */
    enum class capability: GLenum
    {
        ALPHA_TEST              = GL_ALPHA_TEST,
        AUTO_NORMAL             = GL_AUTO_NORMAL,
        BLEND                   = GL_BLEND,
        CLIP_PLANE0             = GL_CLIP_PLANE0,
        CLIP_PLANE1             = GL_CLIP_PLANE1,
        CLIP_PLANE2             = GL_CLIP_PLANE2,
        CLIP_PLANE3             = GL_CLIP_PLANE3,
        CLIP_PLANE4             = GL_CLIP_PLANE4,
        CLIP_PLANE5             = GL_CLIP_PLANE5,
        COLOUR_LOGIC_OP         = GL_COLOR_LOGIC_OP,
        COLOUR_MATERIAL         = GL_COLOR_MATERIAL,
        CULL_FACE               = GL_CULL_FACE,
        DEPTH_TEST              = GL_DEPTH_TEST,
        DITHER                  = GL_DITHER,
        FOG                     = GL_FOG,
        INDEX_LOGIC_OP          = GL_INDEX_LOGIC_OP,
        LIGHT0                  = GL_LIGHT0,
        LIGHT1                  = GL_LIGHT1,
        LIGHT2                  = GL_LIGHT2,
        LIGHT3                  = GL_LIGHT3,
        LIGHT4                  = GL_LIGHT4,
        LIGHT5                  = GL_LIGHT5,
        LIGHT6                  = GL_LIGHT6,
        LIGHT7                  = GL_LIGHT7,
        LIGHTING                = GL_LIGHTING,
        LINE_SMOOTH             = GL_LINE_SMOOTH,
        LINE_STRIPPLE           = GL_LINE_STIPPLE,
        MAP1_COLOUR_4           = GL_MAP1_COLOR_4,
        MAP1_INDEX              = GL_MAP1_INDEX,
        MAP1_NORMAL             = GL_MAP1_NORMAL,
        MAP1_TEXTURE_COORD_1    = GL_MAP1_TEXTURE_COORD_1,
        MAP1_TEXTURE_COORD_2    = GL_MAP1_TEXTURE_COORD_2,
        MAP1_TEXTURE_COORD_3    = GL_MAP1_TEXTURE_COORD_3,
        MAP1_TEXTURE_COORD_4    = GL_MAP1_TEXTURE_COORD_4,
        MAP1_VERTEX_3           = GL_MAP2_VERTEX_3,
        MAP1_VERTEX_4           = GL_MAP2_VERTEX_4,
        MAP2_COLOUR_4           = GL_MAP2_COLOR_4,
        MAP2_INDEX              = GL_MAP2_INDEX,
        MAP2_NORMAL             = GL_MAP2_NORMAL,
        MAP2_TEXTURE_COORD_1    = GL_MAP2_TEXTURE_COORD_1,
        MAP2_TEXTURE_COORD_2    = GL_MAP2_TEXTURE_COORD_2,
        MAP2_TEXTURE_COORD_3    = GL_MAP2_TEXTURE_COORD_3,
        MAP2_TEXTURE_COORD_4    = GL_MAP2_TEXTURE_COORD_4,
        MAP2_VERTEX_3           = GL_MAP2_VERTEX_3,
        MAP2_VERTEX_4           = GL_MAP2_VERTEX_4,
        NORMALIZE               = GL_NORMALIZE,
        POINT_SMOOTH            = GL_POINT_SMOOTH,
        POLYGON_OFFSET_FILL     = GL_POLYGON_OFFSET_FILL,
        POLYGON_OFFSET_LINE     = GL_POLYGON_OFFSET_LINE,
        POLYGON_OFFSER_POINT    = GL_POLYGON_OFFSET_POINT,
        POLYGON_SMOOTH          = GL_POLYGON_SMOOTH,
        POLYGON_STIPPLE         = GL_POLYGON_STIPPLE,
        SCISSOR_TEST            = GL_SCISSOR_TEST,
        STENCIL_TEST            = GL_STENCIL_TEST,
        TEXTURE_1D              = GL_TEXTURE_1D,
        TEXTURE_2D              = GL_TEXTURE_2D,
        TEXTURE_GEN_Q           = GL_TEXTURE_GEN_Q,
        TEXTURE_GEN_R           = GL_TEXTURE_GEN_R,
        TEXTURE_GEN_S           = GL_TEXTURE_GEN_S,
        TEXTURE_GEN_T           = GL_TEXTURE_GEN_T,
    };
    //==========================================================================
    //Functions.
    /**
     * Enable a <code>glpp::capability</code>.
     *
     * @param cap The capability to be enabled.
     * @throw glpp::error If OpenGL raises an error.
     */
    inline void enable(capability cap) throw(error)
    {
        glEnable((GLenum) cap);
        get_error();
    }
    /**
     * Disable a <code>glpp::capability</code>.
     *
     * @param cap The capability to be disabled.
     * @throw glpp::error If OpenGL raises an error.
     */
    inline void disable(capability cap) throw(error)
    {
        glDisable((GLenum) cap);
        get_error();
    }
} //glpp

#endif //CAPABILITY_HPP
