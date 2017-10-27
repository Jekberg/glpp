/* 
 * File:   vertex_table.hpp
 * Author: John
 *
 * Created on 15 October 2017, 21:09
 */

#ifndef VERTEX_TABLE_HPP
#define VERTEX_TABLE_HPP

#include <GL/gl.h>

namespace glpp
{
    //==========================================================================
    //vertex_function
    template<unsigned int, typename>
    struct vertex_table;
    //--------------------------------------------------------------------------
    //double
    template<>
    struct vertex_table<2, GLdouble>
    {
        vertex_table() = delete;
        static constexpr auto function = glVertex2d;
    };
    template<>
    struct vertex_table<3, GLdouble>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex3d;
    };
    template<>
    struct vertex_table<4, GLdouble>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex4d;
    };
    //--------------------------------------------------------------------------
    //float.
    template<>
    struct vertex_table<2, GLfloat>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex2f;
    };
    template<>
    struct vertex_table<3, GLfloat>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex3f;
    };
    template<>
    struct vertex_table<4, GLfloat>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex4d;
    };
    //--------------------------------------------------------------------------
    //int
    template<>
    struct vertex_table<2, GLint>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex2i;
    };
    template<>
    struct vertex_table<3, GLint>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex3i;
    };
    template<>
    struct vertex_table<4, GLint>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex4i;
    };
    //--------------------------------------------------------------------------
    //short
    template<>
    struct vertex_table<2, GLshort>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex2s;
    };
    template<>
    struct vertex_table<3, GLshort>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex3s;
    };
    template<>
    struct vertex_table<4, GLshort>
    {
        vertex_function() = delete;
        static constexpr auto function = glVertex4s;
    };
} //glpp
#endif //VERTEX_TABLE_HPP