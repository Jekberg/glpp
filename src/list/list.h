/* 
 * File:    list.h
 * Author:  John
 * Date:    27/10/2017
 */

#ifndef LIST_H
#define LIST_H

#include <GL/gl.h>

namespace glpp
{
    typedef class gl_list
    {
    private:
        friend gl_list compile_list(const std::function<void ()>)
                throw(GLenum);
        friend gl_list compile_and_execute_list(const std::function<void ()>)
                throw(GLenum);
        friend void submit(const gl_list &) noexcept;
        static GLuint NO_LIST;
        static GLuint SIZE;
        GLuint handle_;
    public:
        gl_list() noexcept;
    private:
        gl_list(
                const GLenum,
                const std::function<void ()>)
                throw(GLenum);
    public:
        gl_list(const gl_list &) = delete;
        gl_list(gl_list &&) noexcept;
        ~gl_list() noexcept;
        gl_list & operator = (const gl_list &) = delete;
        gl_list & operator = (gl_list &&) noexcept;
    private:
        void release() noexcept;
    } list;
    gl_list compile_list(const std::function<void ()>)
            throw(GLenum);
    gl_list compile_and_execute_list(const std::function<void ()>)
            throw(GLenum);
    void submit(const gl_list &) noexcept;
} //glpp;

#endif //LIST_H