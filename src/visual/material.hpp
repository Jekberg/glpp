#ifndef GLPP_SRC_VISUAL_MATERIAL_HPP
#define GLPP_SRC_VISUAL_MATERIAL_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Enums.
    /**
     *
     * @brief
     */
    enum class face: GLenum
    {
        FRONT           = GL_FRONT,
        BACK            = GL_BACK,
        FRONT_AND_BACK  = GL_FRONT_AND_BACK
    };
    //==========================================================================
    //Functions.
    /**
     * This function is equivalent to glMaterialf(GLenum, GL_SHININESS, GLfloat).
     *
     * @brief Set the shininess of a face.
     * @param p_face The face to be set.
     * @param shininess_value The shininess value of the <code>p_face</code>.
     */
    void shininess(face p_face, const GLfloat shininess_value);
    /**
     * This method is equivalent to glMaterialfv(GLenum, GLenum, GLfloat*).
     *
     * @brief Set the material type of a face using a float_vector4.
     * @param p_face The face to be modified.
     * @param type The material_mode of <code>p_face</code> to be set.
     * @param v The float_vector4 of values to use in setting the
     *          <code>type</code>.
     */
    void material(
            face p_face,
            material_mode type,
            const float_vector4& v);
    /**
     * This method is equivalent to glMaterialfv(GLenum, GLenum, GLfloat*).
     *
     * @brief Set the material type of a face using a float_vector4.
     * @param p_face The face to be modified.
     * @param type The material_mode of <code>p_face</code> to be set.
     * @param v The float_vector4 of values to use in setting the
     *          <code>type</code>.
     */
    void material(
            face p_face,
            material_mode type,
            const float_vector4&& v);
}

#endif //GLPP_SRC_VISUAL_MATERIAL_HPP
