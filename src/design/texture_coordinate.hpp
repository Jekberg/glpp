#ifndef GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP
#define GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Functions.
    void texture_coordinate(const float_vector2& tex) noexcept;
    void texture_coordinate(const float_vector2&& tex) noexcept;
    void texture_coordinate(const float_vector3& tex) noexcept;
    void texture_coordinate(const float_vector3&& tex) noexcept;
    void texture_coordinate(const float_vector4& tex) noexcept;
    void texture_coordinate(const float_vector4&& tex) noexcept;
    template<std::size_t Size>
    constexpr void texture_coordinate(const float_vector<Size>& tex)
            noexcept
    {
        //Forward the call to a suitable overload.
        texture_coordinate(std::forward<decltype(tex)>(tex));
    }
    template<std::size_t Size>
    constexpr void texture_coordinate(const float_vector<Size>&& tex)
            noexcept
    {
        //Forward the call to a suitable overload.
        texture_coordinate(std::forward<decltype(tex)>(tex));
    }
}

#endif // GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP
