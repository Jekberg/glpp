#ifndef GLPP_SRC_UTIL_SPACE_HPP
#define GLPP_SRC_UTIL_SPACE_HPP

#include <GL/gl.h>
#include "mode.hpp"

namespace glpp
{
    //==========================================================================
    //Functions.
    /**
     * This function calls a function or function object between glBegin(GLenum)
     * and glEnd(). If the callback object is <code>noexcept</code>, then this
     * function is also <code>noexcept</code>.
     *
     * @brief Call a procedure between to submit vertices using a specific
     *          vertex_mode.
     * @param mode The vertex_mode which is used in glBegin(GLenum).
     * @param callback The function object which takes no arguments.
     */
    template<typename F>
    void vertex_space(
           vertex_mode mode,
           F callback)
           noexcept(noexcept(callback()))
    {
        glBegin(static_cast<GLenum>(mode));
        callback();
        glEnd();
    }
    /**
     * This function calls a function or function object between glPushMatrix()
     * and glPopMatrix(). If the callback object is <code>noexcept</code>, then
     * this function is also <code>noexcept</code>.
     *
     * @brief Call a procedure between a glMatrixPush() and glMatrixPop().
     * @param The function object which takes no arguments.
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
     * This function calls a function or function object between
     * glPushAttribute(GLbitfield) and glPopAttribute(). If the callback object
     * is <code>noexcept</code>, then this function is also
     * <code>noexcept</code>.
     *
     * @brief Call a procedure between a glPushAttribute(GLbitfield) and
     *          glPopAttribute().
     * @param mask The GLbitfield which contains the attributes to push onto the
     *          attribute stack.
     * @param callback The function object which takes no arguments.
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
