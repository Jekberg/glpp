#ifndef GLPP_SRC_UTIL_MODE_HPP
#define GLPP_SRC_UTIL_MODE_HPP

namespace glpp
{
    //==========================================================================
    //Enums.
    /**
     * The compilations modes available for list.
     *
     * @brief The modes which can be used to create a list.
     */
    enum class list_mode: GLenum
    {
        COMPILE             = GL_COMPILE,
        COMPILE_AND_EXECUTE = GL_COMPILE_AND_EXECUTE
    };
    /**
     * @brief The modes which describe how to draw the vertices.
     */
    enum class vertex_mode: GLenum
    {
        POINTES         = GL_POINTS,
        LINES           = GL_LINES,
        LINE_STRIP      = GL_LINE_STRIP,
        LINE_LOOP       = GL_LINE_LOOP,
        TRIANGLES       = GL_TRIANGLES,
        TRIANGLE_STRIP  = GL_TRIANGLE_STRIP,
        TRIANGL_FAN     = GL_TRIANGLE_FAN,
        QUADS           = GL_QUADS,
        QUAD_STIP       = GL_QUAD_STRIP,
        POLYGON         = GL_POLYGON
    };
    /**
     * @brief The lighting modes available in OpenGL.
     */
    enum class light_mode: GLenum
    {
        AMBIENT     = GL_AMBIENT,
        DIFFUSE     = GL_DIFFUSE,
        SPECULAR    = GL_SPECULAR
    };
    /**
     * @brief The texture modes available in OpenGL.
     */
    enum class texture_mode: GLenum
    {
        TEXTURE_2D  = GL_TEXTURE_2D
    };
    /**
     * @brief The material types available in OpenGL.
     */
    enum class material_mode: GLenum
    {
        AMBIENT     = GL_AMBIENT,
        DIFFUSE     = GL_DIFFUSE,
        SPECULAR    = GL_SPECULAR,
        EMISSION    = GL_EMISSION
    };
    /**
     * @brief The depth comparison functions available.
     */
    enum class comparision_mode: GLenum
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
} //glpp

#endif // GLPP_SRC_UTIL_MODE_HPP
