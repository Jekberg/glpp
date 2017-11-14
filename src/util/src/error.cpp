#include "../error.hpp"

namespace glpp
{
    //==========================================================================
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
    //==========================================================================
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
    //==========================================================================
    //Functions.
    void get_error()
    {
        GLenum err = glGetError();
        if(err)
            throw error((error_code) err);
    }
} //glpp
