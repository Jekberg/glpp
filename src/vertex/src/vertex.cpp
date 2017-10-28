#include "../vertex.hpp"

namespace glpp
{
    /**
     * 
     * 
     * 
     * @param x The x position.
     * @param y The y position.
     * @param z The z position.
     * @param w The w position.
     */
    vertex::vertex(
            vertex::const_value_type x,
            vertex::const_value_type y,
            vertex::const_value_type z,
            vertex::const_value_type w)
            noexcept:
            x_(x),
            y_(y),
            z_(z),
            w_(w)
    {
    }
    /**
     * 
     * @param orig
     */
    vertex::vertex(const vertex & orig)
            noexcept:
            vertex(
                    orig.x_,
                    orig.y_,
                    orig.z_,
                    orig.w_)
    {
    }
    /**
     * 
     * @param orig
     */
    vertex::vertex(const vertex && orig)
            noexcept:
            vertex(
                    orig.x_,
                    orig.y_,
                    orig.z_,
                    orig.w_)
    {
    }
    /**
     * 
     */
    vertex::~vertex()
            noexcept
    {
    }
    vertex & vertex::operator = (const vertex & orig)
            noexcept
    {
        x_ = orig.x_;
        y_ = orig.y_;
        z_ = orig.z_;
        w_ = orig.w_;
        return *this;
    }
    vertex & vertex::operator = (const vertex && orig)
            noexcept
    {
        x_ = orig.x_;
        y_ = orig.y_;
        z_ = orig.z_;
        w_ = orig.w_;
        return *this;
    }
    vertex::value_type_ptr vertex::operator * ()
            noexcept
    {
        return &x_;
    }
    vertex::const_value_type_ptr vertex::operator * () const
            noexcept
    {
        return &x_;
    }
    /**
     * 
     * @param vert
     */
    void submit(const vertex & vert) noexcept
    {
        glVertex4d(vert.x_, vert.y_, vert.z_, vert.z_);
    }
    /**
     * 
     * @param vert
     */
    void submit(const vertex && vert) noexcept
    {
        glVertex4d(vert.x_, vert.y_, vert.z_, vert.z_);
    }
} //glpp