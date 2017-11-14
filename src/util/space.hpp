#ifndef GLPP_SRC_UTIL_SPACE_HPP
#define GLPP_SRC_UTIL_SPACE_HPP

#include <GL/gl.h>

namespace glpp
{
    /**
     *
     */
    template<typename F>
    void matrix_space(F callback)
    noexcept(noexcept(callback()))
    {
        glPushMatrix();
        callback();
        glPopMatrix();
    }
    /**
     *
     */
    template<typename F>
    void attribute_space(
            const GLbitfield mask,
            F callback)
            noexcept(noexcept(callback()))
    {
        glPushAttrib(mask);
        callback();
        glPopAttrib();
    }
} //glpp

#endif // GLPP_SRC_UTIL_SPACE_HPP
