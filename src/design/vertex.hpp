/*
 * File:    vertex.hpp
 * Author:  John Berg
 * Date:    12/10/2017
 */

#ifndef GLPP_SRC_DESIGN_VERTEX_HPP
#define GLPP_SRC_DESIGN_VERTEX_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Typedefs.
    /**
     * The type which represents an OpenGL vertex of type float which is using 2
     * coordinates.
     */
    typedef vector_base<2, float_type> vertex2;
    /**
     * The type which represents an OpenGL vertex of type float, which is using
     * 3 coordinates.
     */
    typedef vector_base<3, float_type> vertex3;
    /**
     * The type which represents an OpenGL vertex of type float which is using 4
     * coordinates.
     */
    typedef vector_base<4, float_type> vertex4;
    //==========================================================================
    //Functions.
    /**
     *
     *
     *
     * @param vtx The <code>const</code> reference to a ...
     */
    void vertex(const vertex2& vtx) noexcept;
    /**
     *
     * @param
     * @return
     */
    void vertex(const vertex2&& vtx) noexcept;
    /**
     *
     * @param
     * @return
     */
    void vertex(const vertex3& vtx) noexcept;
    /**
     *
     * @param
     * @return
     */
    void vertex(const vertex3&& vtx) noexcept;
    /**
     *
     *
     *
     * @param
     * @return
     */
    void vertex(const vertex4& vtx) noexcept;
    /**
     *
     * @param
     * @return
     */
    void vertex(const vertex4&& vtx) noexcept;
    /**
     *
     * @param
     * @return
     */
    template<std::size_t Size>
    constexpr void vertex(const vector_base<Size, float_type>& vtx) noexcept
    {
        //Forward the call to the correct overload.
        vertex(std::forward<decltype(vtx)>(vtx));
    }
    /**
     *
     * @param
     * @return
     */
    template<std::size_t Size>
    constexpr void vertex(const vector_base<Size, float_type>&& vtx) noexcept
    {
        //Forward the call to the correct overload.
        vertex(std::forward<decltype(vtx)>(vtx));
    }
} //glpp
#endif //GLPP_SRC_DESIGN_VERTEX_HPP
