#ifndef GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP
#define GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Typedefs.
    typedef vector_base<2, float_type> texture_coordinate2;
    typedef vector_base<3, float_type> texture_coordinate3;
    typedef vector_base<4, float_type> texture_coordinate4;
    //==========================================================================
    //Functions.
    void texture_coordinate(const texture_coordinate2& tex) noexcept;
    void texture_coordinate(const texture_coordinate2&& tex) noexcept;
    void texture_coordinate(const texture_coordinate3& tex) noexcept;
    void texture_coordinate(const texture_coordinate3&& tex) noexcept;
    void texture_coordinate(const texture_coordinate4& tex) noexcept;
    void texture_coordinate(const texture_coordinate4&& tex) noexcept;
    template<std::size_t Size>
    constexpr void texture_coordinate(const vector_base<Size, float_type>& tex)
            noexcept
    {
        //Forward the call to a suitable overload.
        texture_coordinate(std::forward<decltype(tex)>(tex));
    }
    template<std::size_t Size>
    constexpr void texture_coordinate(const vector_base<Size, float_type>&& tex)
            noexcept
    {
        //Forward the call to a suitable overload.
        texture_coordinate(std::forward<decltype(tex)>(tex));
    }
}

#endif // GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP
