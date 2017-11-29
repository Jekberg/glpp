#ifndef GLPP_SRC_DESIGN_TRANSFORMATION_HPP
#define GLPP_SRC_DESIGN_TRANSFORMATION_HPP

namespace glpp
{
    //==========================================================================
    //Functions.
    /**
     *
     * The result of this function is equivalent to calling
     * glTranslatef(GLfloat, GLfloat, GLfloat).
     *
     * @brief Translation over a distance in in 3d space.
     * @param delta_x The distance to translate in the x-axis.
     * @param delta_y The distance to translate in the y-axis.
     * @param delta_z The distance to translate in the z-axis, is 0 by
     *          default.
     */
    inline void translate(
            register const GLfloat delta_x,
            register const GLfloat delta_y,
            register const GLfloat delta_z = 0.0)
            noexcept
    {
        glTranslatef(delta_x, delta_y, delta_z);
    }
    /**
     * The result of this function is equivalent to calling
     * glRotatef(GLfloat, GLfloat, GLfloat, GLfloat) with the arguments
     * (<code>angle</code>, <code>1</code>, <code>0</code>, <code>0</code>).
     *
     * @brief Rotation in 3d space around the x-axis.
     * @param angle The angle in degrees of the rotation.
     */
    inline void rotate_x(const GLfloat angle) noexcept
    {
        glRotatef(angle, 1, 0, 0);
    }
    /**
     * The result of this function is equivalent to calling
     * glRotatef(GLfloat, GLfloat, GLfloat, GLfloat) with the arguments
     * (<code>angle</code>, <code>0</code>, <code>1</code>, <code>0</code>).
     *
     * @brief Rotation in 3d space around the y-axis.
     * @param angle The angle in degrees of the rotation.
     */
    inline void rotate_y(register const GLfloat angle) noexcept
    {
        glRotatef(angle, 0, 1, 0);
    }
    /**
     * The result of this function is equivalent to calling
     * glRotatef(GLfloat, GLfloat, GLfloat, GLfloat) with the arguments
     * (<code>angle</code>, <code>0</code>, <code>0</code>, <code>1</code>).
     *
     * @brief Rotation in 3d space around the z-axis.
     * @param angle The angle in degrees of the rotation.
     */
    inline void rotate_z(register const GLfloat angle) noexcept
    {
        glRotatef(angle, 0, 0, 1);
    }
    /**
     * The result of this function is equivalent to calling thr
     * glScalef(GLfloat, GLfloat, GLfloat).
     *
     * @brief Scaling in 3d space.
     * @param scale_factor_x The scaling factor for the x-axis.
     * @param scale_factor_y The scaling factor for the y-axis.
     * @param scale_factor_z The scaling factor for the z-axis.
     */
    inline void scale(
            register const GLfloat scale_factor_x,
            register const GLfloat scale_factor_y,
            register const GLfloat scale_factor_z = 1.0)
            noexcept
    {
        glScalef(scale_factor_x, scale_factor_y, scale_factor_z);
    }
}

#endif // GLPP_SRC_DESIGN_TRANSFORMATION_HPP
