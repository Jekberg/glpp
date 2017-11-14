#include "../list.hpp"

namespace glpp
{
    //==========================================================================
    //Static members.
    const GLuint gl_list::NO_LIST = 0;
    const GLuint gl_list::SIZE = 1;
    //==========================================================================
    //Constructors.
    gl_list::gl_list() noexcept:
            handle_(NO_LIST)
    {
    }
    gl_list::gl_list(gl_list && orig)
            noexcept:
            handle_(orig.handle_)
    {
        orig.handle_ = NO_LIST;
    } //gl_list(const gl_list &)
    //==========================================================================
    //Destructors.
    gl_list::~gl_list()
            noexcept
    {
        release();
    } //gl_list()
    //==========================================================================
    //Member operators.
    gl_list & gl_list::operator = (gl_list && orig)
            noexcept
    {
        release();
        handle_ = orig.handle_;
        orig.handle_ = NO_LIST;
        return *this;
    }
} //glpp
