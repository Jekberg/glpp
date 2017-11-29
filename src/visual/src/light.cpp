#include "../light.hpp"

#include <iostream>
#include <algorithm>
//==============================================================================
//Functions.
void glpp::light(
            glpp::light_source src,
            glpp::light_mode mode,
            const glpp::vector_base<4, float_type>& v)
{
    glLightfv(static_cast<GLenum>(src), static_cast<GLenum>(mode), v.begin());
}
void glpp::light(
            glpp::light_source src,
            glpp::light_mode mode,
            const glpp::vector_base<4, float_type>&& v)
{
    glLightfv(static_cast<GLenum>(src), static_cast<GLenum>(mode), v.begin());
}
void glpp::light_at(
            glpp::light_source src,
            const glpp::vector_base<4, float_type>& v)
{
    glLightfv(static_cast<GLenum>(src), GL_POSITION, v.begin());
}
void glpp::light_at(
            glpp::light_source src,
            const glpp::vector_base<4, float_type>&& v)
{
    glLightfv(static_cast<GLenum>(src), GL_POSITION, v.begin());
}
