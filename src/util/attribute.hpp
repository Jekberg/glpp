/* 
 * File:    attribute.hpp
 * Author:  John Berg
 * Date:    03/11/2017
 */

#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

#include <GL/gl.h>
#include "../error.hpp"
#include "../util.hpp"

namespace glpp
{
    /**
     * 
     * @param   attributes
     * @param   callback
     * @throws  glpp::error 
     */
    void attribute_space(
            GLbitfield attributes,
            procedure callback)
            throw(error)
    {
        glPushAttrib(attributes);
        {
            callback();
        }
        glPopAttrib();
        get_error();
    }
} //glpp

#endif //ATTRIBUTE_HPP