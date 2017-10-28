#include "../vertex.hpp"

namespace glpp
{
    //==========================================================================
    //Constructors.
    /**
     * Initialise a vertex
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
    //==========================================================================
    //Destructors.
    /**
     * 
     */
    vertex::~vertex()
            noexcept
    {
    }
    //==========================================================================
    //Operators.
    /**
     * 
     * @param orig
     * @return 
     */
    vertex & vertex::operator = (const vertex & orig)
            noexcept
    {
        x_ = orig.x_;
        y_ = orig.y_;
        z_ = orig.z_;
        w_ = orig.w_;
        return *this;
    }
    /**
     * 
     * @param orig
     * @return 
     */
    vertex & vertex::operator = (const vertex && orig)
            noexcept
    {
        x_ = orig.x_;
        y_ = orig.y_;
        z_ = orig.z_;
        w_ = orig.w_;
        return *this;
    }
    /**
     * Get the raw pointer which is pointing at the first element of the vertex,
     * which represents the x axis.
     * 
     * 
     * 
     * @return The pointer to the array of the elements.
     */
    vertex::value_type_ptr vertex::operator * ()
            noexcept
    {
        return &x_;
    }
    /**
     * 
     * @return 
     */
    vertex::const_value_type_ptr vertex::operator * () const
            noexcept
    {
        return &x_;
    }
    //==========================================================================
    //Functions.
    /**
     * 
     * @param vert
     */
    void submit(const vertex & vert) noexcept
    {
        glVertex4d(vert.x_, vert.y_, vert.z_, vert.z_);
    }
    /**
     * Submit the vertex of 
     * 
     * @param vert The rvalue refference to a vertex.
     */
    void submit(const vertex && vert) noexcept
    {
        glVertex4d(vert.x_, vert.y_, vert.z_, vert.z_);
    }
} //glpp