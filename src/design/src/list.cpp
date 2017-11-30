#include "../list.hpp"

namespace glpp
{
    //==========================================================================
    //Static members.
    const GLuint list::NO_LIST = 0;
    const GLuint list::SIZE = 1;
    //==========================================================================
    //Constructors.
    list::list() noexcept:
            handle_(NO_LIST)
    {
    }
    list::list(list && orig)
            noexcept:
            handle_(orig.handle_)
    {
        orig.handle_ = NO_LIST;
    } //list(const list &)
    //==========================================================================
    //Destructors.
    list::~list()
            noexcept
    {
        release();
    } //list()
    //==========================================================================
    //Member operators.
    list& list::operator= (list&& orig)
            noexcept
    {
        release();
        handle_ = orig.handle_;
        orig.handle_ = NO_LIST;
        return *this;
    }
} //glpp
