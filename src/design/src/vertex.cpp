#include "../vertex.hpp"

//==============================================================================
//Using.
using glpp::get;
//==============================================================================
//Functions.
void glpp::vertex(const glpp::vertex2& vtx) noexcept
{
    glVertex2f(get<0>(vtx), get<1>(vtx));
}
void glpp::vertex(const glpp::vertex2&& vtx) noexcept
{
    glVertex2f(get<0>(vtx), get<1>(vtx));
}
void glpp::vertex(const glpp::vertex3& vtx) noexcept
{
    glVertex3f(get<0>(vtx), get<1>(vtx), get<2>(vtx));
}
void glpp::vertex(const glpp::vertex3&& vtx) noexcept
{
    glVertex3f(get<0>(vtx), get<1>(vtx), get<2>(vtx));
}
void glpp::vertex(const glpp::vertex4& vtx) noexcept
{
    glVertex4f(get<0>(vtx), get<1>(vtx), get<2>(vtx), get<3>(vtx));
}
void glpp::vertex(const glpp::vertex4&& vtx) noexcept
{
    glVertex4f(get<0>(vtx), get<1>(vtx), get<2>(vtx), get<3>(vtx));
}
