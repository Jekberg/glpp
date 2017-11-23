#include "../normal.hpp"

//==============================================================================
//Functions.
void glpp::normal(const glpp::normal3& nml) noexcept
{
    glNormal3f(glpp::get<0>(nml), glpp::get<1>(nml), glpp::get<2>(nml));
}
void glpp::normal(const glpp::normal3&& nml) noexcept
{
    glNormal3f(glpp::get<0>(nml), glpp::get<1>(nml), glpp::get<2>(nml));
}
