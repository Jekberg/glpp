#include "../vertex.hpp"

//==============================================================================
//Using.
using glpp::get;
//==============================================================================
//Functions.
void glpp::vertex(const glpp::float_vector2& vtx) noexcept
{
    glVertex2f(get<0>(vtx), get<1>(vtx));
}
void glpp::vertex(const glpp::float_vector2&& vtx) noexcept
{
    glVertex2f(get<0>(vtx), get<1>(vtx));
}
void glpp::vertex(const glpp::float_vector3& vtx) noexcept
{
    glVertex3f(get<0>(vtx), get<1>(vtx), get<2>(vtx));
}
void glpp::vertex(const glpp::float_vector3&& vtx) noexcept
{
    glVertex3f(get<0>(vtx), get<1>(vtx), get<2>(vtx));
}
void glpp::vertex(const glpp::float_vector4& vtx) noexcept
{
    glVertex4f(get<0>(vtx), get<1>(vtx), get<2>(vtx), get<3>(vtx));
}
void glpp::vertex(const glpp::float_vector4&& vtx) noexcept
{
    glVertex4f(get<0>(vtx), get<1>(vtx), get<2>(vtx), get<3>(vtx));
}
