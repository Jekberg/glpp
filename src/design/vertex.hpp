#ifndef GLPP_SRC_DESIGN_VERTEX_HPP
#define GLPP_SRC_DESIGN_VERTEX_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Functions.
    /**
     * This method is equivalent to glVertex2f(GLfloat, GLfloat).
     *
     * @brief Submit a vertex of length 2.
     * @param vtx The reference to a vertex of length 2.
     */
    void vertex(const float_vector2& vtx) noexcept;
    /**
     * This method is equivalent to glVertex2f(GLfloat, GLfloat).
     *
     * @brief Submit a vertex of length 2.
     * @param vtx The rvalue reference to a vertex of length 2.
     */
    void vertex(const float_vector2&& vtx) noexcept;
    /**
     * This method is equivalent to glVertex3f(GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a vertex of length 3.
     * @param vtx The reference to a vertex of length 3.
     */
    void vertex(const float_vector3& vtx) noexcept;
    /**
     * This method is equivalent to glVertex3f(GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a vertex of length 3.
     * @param vtx The rvalue reference to a vertex of length 3.
     */
    void vertex(const float_vector3&& vtx) noexcept;
    /**
     * This method is equivalent to
     * glVertex4f(GLfloat, GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a vertex of length 4.
     * @param vtx The reference to a vertex of length 4.
     */
    void vertex(const float_vector4& vtx) noexcept;
    /**
     * This method is equivalent to
     * glVertex4f(GLfloat, GLfloat, GLfloat, GLfloat).
     *
     * @brief Submit a vertex of length 4.
     * @param vtx The rvalue reference to a vertex of length 4.
     */
    void vertex(const float_vector4&& vtx) noexcept;
    /**
     * Compilation will fail if no existing overload exists.
     *
     * @brief Forward a vertex which size cannot be deduced to the correct
     *          function.
     * @param vtx The reference to a vertex of varying size.
     */
    template<std::size_t Size>
    constexpr void vertex(const float_vector<Size>& vtx) noexcept
    {
        static_assert(2 <= Size && Size <= 4, "No existing vertex function.");
        //Forward the call to the correct overload.
        vertex(std::forward<decltype(vtx)>(vtx));
    }
    /**
     * Compilation will fail if no existing overload exists.
     *
     * @brief Forward a vertex which size cannot be deduced to the correct
     *          function.
     * @param vtx The rvalue reference to a vertex of varying size.
     */
    template<std::size_t Size>
    constexpr void vertex(const float_vector<Size>&& vtx) noexcept
    {
        static_assert(2 <= Size && Size <= 4, "No existing vertex function.");
        //Forward the call to the correct overload.
        vertex(std::forward<decltype(vtx)>(vtx));
    }
} //glpp
#endif //GLPP_SRC_DESIGN_VERTEX_HPP
