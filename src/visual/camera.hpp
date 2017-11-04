/* 
 * File:    camera.hpp
 * Author:  John Berg
 * Date:    27/10/2017
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <array>
#include <math.h>
#include <GL/glu.h>
#include <GL/gl.h>

namespace glpp
{
    //==========================================================================
    //Forward declarations.
    class camera;
    //==========================================================================
    //Classes.
    class camera
    {
        //======================================================================
        //Typedefs.
    private:
        typedef double value_type;
        typedef const double const_value_type;
        typedef std::array<value_type> value_vector;
        //======================================================================
        //Friends.
        friend void submit(const camera &);
        //======================================================================
        //Members.
        value_vector eye_;
        value_vector centre_;
        value_vector up_;
        //======================================================================
        //Constructors.
    public:
        camera() = delete;
        camera(
                value_vector eye,
                value_vector centre,
                value_vector up)
                noexcept;
        void strafe(const_value_type distance) noexcept
        {
            eye_[0] += distance;
            centre_[0] += distance;
        }
        void ascend(const_value_type distance) noexcept
        {
            eye_[1] += distance;
            centre_[1] += distance;
        }
        void advance(const_value_type distance) noexcept
        {
            eye_[2] += distance;
            centre_[2] += distance;
        }
        inline void pitch(const_value_type deg) noexcept
        {
            //convert deg to rad.
            register const_value_type rad = 3.14159 * deg / 180;
            //Calculate angles.
            register const_value_type cos_value = cos(rad);
            register const_value_type sin_value = sin(rad);
            
            const value_vector delta = {
                centre_[0] - eye_[0],
                centre_[1] - eye_[1],
                centre_[2] - eye_[2]
            };
            centre_ = eye_ + value_vector
            {
                delta[0],
                delta[1] * cos_value + delta[2] * sin_value,
                delta[2] * sin_value - delta[2] * cos_value
            };
            //up_ = normalize(eye_ * vector<VEC3>{1.0, 0.0, 0.0});
        }
        inline void yaw(const_value_type deg) noexcept
        {
            //convert deg to rad.
            register const_value_type rad = 3.14159 * deg / 180;
            //Calculate angles.
            register const_value_type cos_value = cos(rad);
            register const_value_type sin_value = sin(rad);
        }
        inline void roll(const_value_type deg)
        {
            //convert deg to rad.
            register const_value_type rad = 3.14159 * deg / 180;
            //Calculate angles.
            register const_value_type cos_value = cos(rad);
            register const_value_type sin_value = sin(rad);
            const auto tp_up_x_ = up_[0] * cos_value - up_[1] * sin_value;
            up_[1] = up_[0] * sin_value + up_[1] * cos_value;
            up_[0] = tp_up_x_;
        }
    };
    void submit(const camera & cam)
    {
        gluLookAt(
                cam.eye_[0], cam.eye_[1], cam.eye_[3],
                cam.centre_[0], cam.centre_[1], cam.centre_[2],
                cam.up_[0], cam.up_[1], cam.up_[2]);
    }
} //glpp

#endif //CAMERA_HPP