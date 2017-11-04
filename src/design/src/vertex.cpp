#include "../vertex.hpp"

namespace glpp
{
    const unsigned int gl_vertex::LENGTH = 4;
    const std::string gl_vertex::OUT_OF_RANGE_MESSAGE = "";
    //==========================================================================
    //Constructors.
    gl_vertex::gl_vertex(const gl_vertex & orig)
            noexcept:
            gl_vertex(
                    orig.x_,
                    orig.y_,
                    orig.z_,
                    orig.w_)
    {
    }
    gl_vertex::gl_vertex(const gl_vertex && orig)
            noexcept:
            gl_vertex(
                    orig.x_,
                    orig.y_,
                    orig.z_,
                    orig.w_)
    {
    }
    //==========================================================================
    //Destructors.
    gl_vertex::~gl_vertex()
            noexcept
    {
    }
    //==========================================================================
    //Member operators.
    gl_vertex & gl_vertex::operator = (const gl_vertex & orig)
            noexcept
    {
        x_ = orig.x_;
        y_ = orig.y_;
        z_ = orig.z_;
        w_ = orig.w_;
        return *this;
    }
    gl_vertex & gl_vertex::operator = (const gl_vertex && orig)
            noexcept
    {
        x_ = orig.x_;
        y_ = orig.y_;
        z_ = orig.z_;
        w_ = orig.w_;
        return *this;
    }
    gl_vertex::value_type_ptr gl_vertex::operator * ()
            noexcept
    {
        return &x_;
    }
    gl_vertex::const_value_type_ptr gl_vertex::operator * () const
            noexcept
    {
        return &x_;
    }
    //==========================================================================
    //Member functions.
    gl_vertex::iterator gl_vertex::begin() noexcept
    {
        return &x_;
    }
    gl_vertex::const_iterator gl_vertex::begin() const noexcept
    {
        return &x_;
    }
    gl_vertex::iterator gl_vertex::end() noexcept
    {
        return begin() + LENGTH;
    }
    gl_vertex::const_iterator gl_vertex::end() const noexcept
    {
        return begin() + LENGTH;
    }
} //glpp