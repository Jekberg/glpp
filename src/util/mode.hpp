#ifndef GLPP_SRC_UTIL_MODE_HPP
#define GLPP_SRC_UTIL_MODE_HPP

namespace glpp
{
    //==========================================================================
    //Enums.
    /**
     * The compilations modes available for list.
     */
    enum class list_mode: GLenum
    {
        COMPILE             = GL_COMPILE,
        COMPILE_AND_EXECUTE = GL_COMPILE_AND_EXECUTE
    };
    /**
     *
     */
    enum class vertex_mode: GLenum
    {
        POLYGON = GL_POLYGON
    };
    /**
     *
     */
    enum class light_mode: GLenum
    {
        AMBIENT     = GL_AMBIENT,
        DIFFUSE     = GL_DIFFUSE,
        SPECULAR    = GL_SPECULAR
    };
} //glpp

#endif // GLPP_SRC_UTIL_MODE_HPP
