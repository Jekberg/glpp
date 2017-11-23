#ifndef GLPP_SRC_DESIGN_TRANSFORMATION_HPP
#define GLPP_SRC_DESIGN_TRANSFORMATION_HPP

namespace glpp
{
    //==========================================================================
    //Functions.
    inline void translate(
            const GLfloat delta_x,
            const GLfloat delta_y,
            const GLfloat delta_z = 0.0)
            noexcept
    {
        glTranslatef(delta_x, delta_y, delta_z);
    }
    inline void rotate_x(const GLfloat angle) noexcept
    {
        glRotatef(angle, 1, 0, 0);
    }
    inline void rotate_y(const GLfloat angle) noexcept
    {
        glRotatef(angle, 0, 1, 0);
    }
    inline void rotate_z(const GLfloat angle) noexcept
    {
        glRotatef(angle, 0, 0, 1);
    }
    inline void scale(
            const GLfloat scale_factor_x,
            const GLfloat scale_factor_y,
            const GLfloat scale_factor_z = 1.0)
            noexcept
    {
        glScalef(scale_factor_x, scale_factor_y, scale_factor_z);
    }
}

#endif // GLPP_SRC_DESIGN_TRANSFORMATION_HPP
