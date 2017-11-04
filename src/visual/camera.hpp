/* 
 * File:    camera.hpp
 * Author:  John Berg
 * Date:    27/10/2017
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glu.h>
#include <GL/gl.h>
#include "../util.hpp"

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
        typedef const value_type const_value_type;
        //======================================================================
        //Friends.
        friend void submit(const camera &);
        //======================================================================
        //Members.
        vector_3 eye_;
        vector_3 centre_;
        vector_3 up_;
        //======================================================================
        //Constructors.
    public:
        camera() = delete;
        camera(
                vector_3 eye,
                vector_3 centre,
                vector_3 up)
                noexcept
        {
            
        }
        void strafe(const_value_type distance) noexcept
        {
            eye_[AXIS_X] += distance;
            centre_[AXIS_X] += distance;
        }
        void ascend(const_value_type distance) noexcept
        {
            eye_[AXIS_Y] += distance;
            centre_[AXIS_Y] += distance;
        }
        void advance(const_value_type distance) noexcept
        {
            eye_[AXIS_Z] += distance;
            centre_[AXIS_Z] += distance;
        }
    };
    void submit(const camera & cam)
    {
        gluLookAt(
                cam.eye_[AXIS_X], cam.eye_[AXIS_Y], cam.eye_[AXIS_Z],
                cam.centre_[AXIS_X], cam.centre_[AXIS_Y], cam.centre_[AXIS_Z],
                cam.up_[AXIS_X], cam.up_[AXIS_Y], cam.up_[AXIS_Z]);
    }
} //glpp

#endif //CAMERA_HPP
    
    