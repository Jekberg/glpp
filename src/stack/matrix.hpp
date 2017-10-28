/* 
 * File:   matrix.hpp
 * Author: John
 *
 * Created on 28 October 2017, 17:17
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <GL/gl.h>
#include <functional>

namespace glpp
{
    typedef std::function<void ()> procedure;
    void matrix_space(const procedure) noexcept;
} //glpp

#endif //MATRIX_HPP

