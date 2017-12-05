#include "../material.hpp"

//==============================================================================
//Functions.
void glpp::shininess(face p_face, const GLfloat shininess_value)
{
    glMaterialf(static_cast<GLenum>(p_face), GL_SHININESS, shininess_value);
}
void glpp::material(face p_face, material_mode type, const float_vector4& v)
{
    glMaterialfv(
            static_cast<GLenum>(p_face),
            static_cast<GLenum>(type),
            v.begin());
}
void glpp::material(face p_face, material_mode type, const float_vector4&& v)
{
    glMaterialfv(
            static_cast<GLenum>(p_face),
            static_cast<GLenum>(type),
            v.begin());
}
