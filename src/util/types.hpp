#ifndef GLPP_SRC_UTIL_TYPES_HPP
#define GLPP_SRC_UTIL_TYPES_HPP

#include <GL/gl.h>
#include "vector.hpp"

namespace glpp
{
    //==========================================================================
    //Using.
    /**
     * @brief The vector_base of a specified size containing <code>float</code>.
     * @param Size The number of elements in the %vector container.
     */
    template<std::size_t Size>
    using float_vector = vector_base<Size, GLfloat>;
    //==========================================================================
    //Typedefs.
    /**
     * The float_vector of length 2.
     *
     * @brief %vector of length 2.
     */
    typedef float_vector<2> float_vector2;
    /**
     * The float_vector of length 3.
     *
     * @brief %vector of length 3.
     */
    typedef float_vector<3> float_vector3;
    /**
     * The float_vector of length 4.
     *
     * @brief %vector of length 4.
     */
    typedef float_vector<4> float_vector4;
} //glpp

#endif //GLPP_SRC_UTIL_TYPES_HPP
