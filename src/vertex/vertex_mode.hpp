/* 
 * File:   vertex_mode.hpp
 * Author: John
 *
 * Created on 15 October 2017, 20:46
 */

#ifndef VERTEX_MODE_HPP
#define VERTEX_MODE_HPP

#include <functional>
#include <GL/gl.h>

namespace glpp
{
    /**
     * 
     * @param type
     * @param call_back
     */
   inline void vertex_mode(
           const GLenum type,
           const std::function<void ()> callback)
           throw(GLenum)
   {
       glBegin(type); //begin
       {
           //procedure
           callback();
       }
       glEnd(); //end
       GLenum error = glGetError();
       if(error)
           throw error;
   } //vertex_mode(const auto)
} //glpp
#endif //VERTEX_MODE_HPP