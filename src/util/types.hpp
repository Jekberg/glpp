/*
 * File:    types.hpp
 * Author:  John Berg
 * Date:    29/10/2017
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include <array>
#include <functional>
#include <GL/gl.h>

namespace glpp
{
    //==========================================================================
    //Constants.
    /**
     * The size of a 2 dimensional vector.
     */
    constexpr const auto VECTOR_SIZE_2 = 2;
    /**
     * The size of a 3 dimensional vector.
     */
    constexpr const auto VECTOR_SIZE_3 = 3;
    /**
     * The size of a 4 dimensional vector.
     */
    constexpr const auto VECTOR_SIZE_4 = 4;
    /**
     *
     */
    constexpr const auto AXIS_X = 0;
    /**
     *
     */
    constexpr const auto AXIS_Y = 1;
    /**
     *
     */
    constexpr const auto AXIS_Z = 2;
    /**
     *
     */
    constexpr const auto AXIS_W = 3;
    //==========================================================================
    //Typedefs.
    /**
     * The floating point type.
     */
    typedef GLfloat float_type;
    /**
     * The const floating point type.
     */
    typedef const float_type const_float_type;
    /**
     *
     */
    typedef std::array<float_type, VECTOR_SIZE_2> vector_2;
    /**
     *
     */
    typedef std::array<float_type, VECTOR_SIZE_3> vector_3;
    /**
     *
     */
    typedef std::array<float_type, VECTOR_SIZE_4> vector_4;
    /**
     * Alias for a functor which takes no arguments, and returns
     * <code>void</code>.
     */
    typedef const std::function<void ()> procedure;
    typedef const std::function<void (const GLuint)> strategy;
} //glpp

#endif //TYPES_HPP

