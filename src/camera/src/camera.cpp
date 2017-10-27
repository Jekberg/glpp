#include "../camera.hpp"


namespace glpp
{
    /**
     * 
     * @param pos_x
     * @param pos_y
     * @param pos_z
     * @param at_x
     * @param at_y
     * @param at_z
     * @param up_x
     * @param up_y
     * @param up_z
     */
    gl_camera::gl_camera(
            gl_camera::const_value_type pos_x,
            gl_camera::const_value_type pos_y,
            gl_camera::const_value_type pos_z,
            gl_camera::const_value_type at_x,
            gl_camera::const_value_type at_y,
            gl_camera::const_value_type at_z,
            gl_camera::const_value_type up_x,
            gl_camera::const_value_type up_y,
            gl_camera::const_value_type up_z)
            noexcept:
            pos_x_(pos_x),
            pos_y_(pos_y),
            pos_z_(pos_z),
            at_x_(at_x),
            at_y_(at_y),
            at_z_(at_z),
            up_x_(up_x),
            up_y_(up_y),
            up_z_(up_z)
    {
    }
    /**
     * 
     * @param delta_x
     * @param delta_y
     * @param delta_z
     */
    void gl_camera::strafe(
            gl_camera::const_value_type delta_x,
            gl_camera::const_value_type delta_y,
            gl_camera::const_value_type delta_z = 0.0)
            noexcept
    {
       pos_x_   += delta_x;
       at_x_    += delta_x; 
       pos_y_   +=delta_y;
       at_y_    += delta_y;
       pos_z_   += delta_z;
       at_z_    += delta_z; 
    }
    void gl_camera::zoom(gl_camera::const_value_type zoom_z)
            noexcept
    {
        pos_z_ += zoom_z;
    }
    /**
     * 
     * @param delta_x
     * @param delta_y
     * @param delta_z
     */
    void gl_camera::move(
            gl_camera::const_value_type delta_x,
            gl_camera::const_value_type delta_y,
            gl_camera::const_value_type delta_z)
            noexcept
    {
        pos_x_ += delta_x;
        pos_y_ += delta_y;
        pos_z_ += delta_z;
    }
    void gl_camera::view(
            gl_camera::const_value_type x,
            gl_camera::const_value_type y,
            gl_camera::const_value_type z)
            noexcept
    {
        at_x_ = x;
        at_y_ = y;
        at_z_ = z;
    }
    void gl_camera::turn(
            gl_camera::const_value_type deg_x,
            gl_camera::const_value_type deg_y,
            gl_camera::const_value_type deg_z)
            noexcept
    {
        
    }
    /**
     * 
     * @param cam
     */
    void submit(const gl_camera & cam)
    {
        gluLookAt(
                cam.pos_x_,cam.pos_y_, cam.pos_z_,
                cam.at_x_, cam.at_y_, cam.at_z_,
                cam.up_x_, cam.up_y_, cam.up_z_);
    }
}