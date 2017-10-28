/* 
 * File:   vertex.hpp
 * Author: John
 *
 * Created on 12 October 2017, 11:42
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <GL/gl.h>

namespace glpp
{
    class vertex
    {
    private:
        friend void submit(const vertex &) noexcept;
        friend void submit(const vertex &&) noexcept;
        typedef double value_type;
        typedef const value_type const_value_type;
        typedef value_type * value_type_ptr;
        typedef const_value_type * const_value_type_ptr;
        value_type x_;
        value_type y_;
        value_type z_;
        value_type w_;
    public:
        vertex(
                const_value_type,
                const_value_type,
                const_value_type,
                const_value_type)
                noexcept;
        ~vertex() noexcept;
        vertex(const vertex &) noexcept;
        vertex(const vertex &&) noexcept;
        vertex & operator = (const vertex &) noexcept;
        vertex & operator = (const vertex &&) noexcept;
        value_type_ptr operator * () noexcept;
        const_value_type_ptr operator * () const noexcept;
    };
    void submit(const vertex &) noexcept;
    void submit(const vertex &) noexcept;
} //glpp
#endif //VERTEX_HPP