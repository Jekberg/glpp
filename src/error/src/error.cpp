#include "../error.hpp"

namespace glpp
{
    //==========================================================================
    //Constructors and destructors.
    //--------------------------------------------------------------------------
    //Constructors.
    error::error(const error_code code) noexcept:
            std::exception(),
            code_(code)
    {
    }
    error::error(const error & orig)
            noexcept:
            std::exception(),
            code_(orig.code_)
    {
    }
    error::error(const error && orig)
            noexcept:
            std::exception(),
            code_(orig.code_)
    {
    }
    //--------------------------------------------------------------------------
    //Destructor.
    error::~error()
    {
    }
    //==========================================================================
    //Member functions.
    const char * error::what() const throw()
    {
        return (char *)gluErrorString((GLenum) code_);
    }
} //glpp