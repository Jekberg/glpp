#ifndef GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP
#define GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Functions.
    /**
     * This method is equivalent to glTexCoord(GLfloat, GLfloat).
     *
     * @brief Submit a texture coordinate of length 2.
     * @param tex The reference to a texture_coordinate of length 2.
     */
    void texture_coordinate(const float_vector2& tex) noexcept;
    /**
     * This method is equivalent to glTexCoord(GLfloat, GLfloat).
     *
     * @brief Submit a texture coordinate of length 2.
     * @param tex The rvalue reference to a texture_coordinate of length 2.
     */
    void texture_coordinate(const float_vector2&& tex) noexcept;
    /**
     * This method is equivalent to glTexCoord(GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a texture coordinate of length 3.
     * @param tex The reference to a texture_coordinate of length 3.
     */
    void texture_coordinate(const float_vector3& tex) noexcept;
    /**
     * This method is equivalent to glTexCoord(GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a texture coordinate of length 3.
     * @param tex The rvalue reference to a texture_coordinate of length 3.
     */
    void texture_coordinate(const float_vector3&& tex) noexcept;
    /**
     * This method is equivalent to
     * glTexCoord(GLfloat, GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a texture coordinate of length 4.
     * @param tex The reference to a texture_coordinate of length 4.
     */
    void texture_coordinate(const float_vector4& tex) noexcept;
    /**
     * This method is equivalent to
     * glTexCoord(GLfloat, GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a texture coordinate of length 4.
     * @param tex The rvalue reference to a texture_coordinate of length 4.
     */
    void texture_coordinate(const float_vector4&& tex) noexcept;
    /**
     * Compilation will fail if no existing overload exists.
     *
     * @brief Forward a texture_coordinate to the correct overload.
     * @param tex The reference to a texture_coordinate of varying size.
     */
    template<std::size_t Size>
    constexpr void texture_coordinate(const float_vector<Size>& tex)
            noexcept
    {
        static_assert(2 <= Size && Size <= 4,
                      "No existing texture_coordinate function.");
        //Forward the call to a suitable overload.
        texture_coordinate(std::forward<decltype(tex)>(tex));
    }
    /**
     * Compilation will fail if no existing overload exists.
     *
     * @brief Forward a texture_coordinate to the correct overload.
     * @param tex The rvalue reference to a texture_coordinate of varying size.
     */
    template<std::size_t Size>
    constexpr void texture_coordinate(const float_vector<Size>&& tex)
            noexcept
    {
        static_assert(2 <= Size && Size <= 4,
                      "No existing texture_coordinate function.");
        //Forward the call to a suitable overload.
        texture_coordinate(std::forward<decltype(tex)>(tex));
    }
}

#endif // GLPP_SRC_DESIGN_TEXTURE_COORDINATE_HPP
