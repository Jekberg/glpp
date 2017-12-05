#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Enums.
    /**
     * @brief The OpenGL lights.
     */
    enum class light_source: GLenum
    {
        LIGHT0 = GL_LIGHT0,
        LIGHT1 = GL_LIGHT1,
        LIGHT2 = GL_LIGHT2,
        LIGHT3 = GL_LIGHT3,
        LIGHT4 = GL_LIGHT4,
        LIGHT5 = GL_LIGHT5,
        LIGHT6 = GL_LIGHT6,
        LIGHT7 = GL_LIGHT7,
    };
    //==========================================================================
    //Functions.
    /**
     * This function is equivalent to glLightFv(GLenum, GLenum, GLfloat*).
     *
     * @brief Set the light_mode of a light_source to %vector of data.
     * @param src The light_source to modify.
     * @param mode The light_mode of the <code>src</code> to set to some
     *          data from <code>v</code>.
     * @param v The float_vector4 of elements which specify the values to set
     *          the <code>mode</code> of <code>src</code>.
     */
    void light(
            light_source src,
            light_mode mode,
            const float_vector4& v);
    /**
     * This function is equivalent to glLightFv(GLenum, GLenum, GLfloat*).
     *
     * @brief Set the light_mode of a light_source to %vector of data.
     * @param src The light_source to modify.
     * @param mode The light_mode of the <code>src</code> to set to some
     *          data from <code>v</code>.
     * @param v The float_vector4 of elements which specify the values to set
     *          the <code>mode</code> of <code>src</code>.
     */
    void light(
            light_source src,
            light_mode mode,
            const float_vector4&& v);
    /**
     * This function is equivalent to glLightfv(GLenum, GL_POSITION, GLfloat*).
     *
     * @brief Set the light_source to a specified position.
     * @param src The light_source to position.
     * @param v The float_vector4 of the values which specify the position of
     *          <code>src</code>.
     */
    void light_at(
            light_source src,
            const float_vector4& v);
    /**
     * This function is equivalent to glLightfv(GLenum, GL_POSITION, GLfloat*).
     *
     * @brief Set the light_source to a specified position.
     * @param src The light_source to position.
     * @param v The float_vector4 of the values which specify the position of
     *          <code>src</code>.
     */
    void light_at(
            light_source src,
            const float_vector4&& v);
} //glpp

#endif //LIGHT_HPP
