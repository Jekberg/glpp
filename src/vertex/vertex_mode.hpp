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
#include "../error.hpp"

namespace glpp
{
    enum class vertex_mode: GLenum
    {
        POLYGON = GL_POLYGON
    };
    /**
     * 
     * @param mode
     * @param callback
     */
   inline void vertex_space(
           const vertex_mode mode,
           const std::function<void ()> callback)
           throw(error)
   {
       glBegin((GLenum) mode); //begin
       {
           //procedure
           callback();
       }
       glEnd(); //end
       get_error();
       
   } //vertex_mode(const auto)
} //glpp
#endif //VERTEX_MODE_HPP