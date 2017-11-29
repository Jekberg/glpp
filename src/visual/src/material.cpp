#include "../material.hpp"

//==============================================================================
//Functions.
void glpp::shininess(face p_face, const glpp::float_type shininess_value)
{
    glMaterialf(static_cast<GLenum>(p_face), GL_SHININESS, shininess_value);
}
