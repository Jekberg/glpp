#include "../texture_coordinate.hpp"

//==============================================================================
//Using.
using glpp::get;
//==============================================================================
//Functions.
void glpp::texture_coordinate(const texture_coordinate2& tex) noexcept
{
    glTexCoord2f(get<0>(tex), get<1>(tex));
}
void glpp::texture_coordinate(const texture_coordinate2&& tex) noexcept
{
    glTexCoord2f(get<0>(tex), get<1>(tex));
}
void glpp::texture_coordinate(const texture_coordinate3& tex) noexcept
{
    glTexCoord3f(get<0>(tex), get<1>(tex), get<2>(tex));
}
void glpp::texture_coordinate(const texture_coordinate3&& tex) noexcept
{
    glTexCoord3f(get<0>(tex), get<1>(tex), get<2>(tex));
}
void glpp::texture_coordinate(const texture_coordinate4& tex) noexcept
{
    glTexCoord4f(get<0>(tex), get<1>(tex), get<2>(tex), get<3>(tex));
}
void glpp::texture_coordinate(const texture_coordinate4&& tex) noexcept
{
    glTexCoord4f(get<0>(tex), get<1>(tex), get<2>(tex), get<3>(tex));
}
