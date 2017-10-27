/* 
 * File:   camera.hpp
 * Author: John
 *
 * Date: 27/10/2017
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glu.h>
#include <GL/gl.h>

namespace glpp
{
    typedef class gl_camera
    {
    private:
        typedef double value_type;
        typedef const double const_value_type;
        friend void submit(const gl_camera &);
        value_type pos_x_;
        value_type pos_y_;
        value_type pos_z_;
        value_type at_x_;
        value_type at_y_;
        value_type at_z_;
        value_type up_x_;
        value_type up_y_;
        value_type up_z_;
    public:
        gl_camera(
                const_value_type,
                const_value_type,
                const_value_type,
                const_value_type,
                const_value_type,
                const_value_type,
                const_value_type,
                const_value_type,
                const_value_type)
                noexcept;
        void strafe(
                const_value_type,
                const_value_type,
                const_value_type)
                noexcept;
        void zoom(const_value_type)
                noexcept;
        void move(
                const_value_type,
                const_value_type,
                const_value_type)
                noexcept;
        void view(
                const_value_type,
                const_value_type,
                const_value_type)
                noexcept;
        void turn(
                const_value_type,
                const_value_type,
                const_value_type)
                noexcept;
    } camera;
} //glpp

#endif //CAMERA_HPP