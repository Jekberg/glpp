#ifndef GLPP_SRC_UTIL_TYPES_HPP
#define GLPP_SRC_UTIL_TYPES_HPP

#include <GL/gl.h>
#include "vector.hpp"

namespace glpp
{
    //==========================================================================
    template<std::size_t Size>
    using float_vector = vector_base<Size, GLfloat>;
    //==========================================================================
    //Typedefs.
    typedef float_vector<2> float_vector2;
    typedef float_vector<3> float_vector3;
    typedef float_vector<4> float_vector4;
} //glpp

#endif //GLPP_SRC_UTIL_TYPES_HPP
