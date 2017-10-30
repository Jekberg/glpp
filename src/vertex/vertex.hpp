/* 
 * File:    vertex.hpp
 * Author:  John Berg
 * Date:    12/10/2017
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <GL/gl.h>
#include <stdexcept>

namespace glpp
{
    //==========================================================================
    //Forward declarations.
    class gl_vertex;
    //==========================================================================
    //Typedefs.
    /**
     * An alias for the <code>glpp::gl_vertex</code> class.
     */
    typedef gl_vertex vertex;
    //==========================================================================
    //Classes.
    /**
     * The <code>glpp::gl_vertex</code> class is a lightweight abstraction of
     * the vertices used by OpenGL.
     */
    class gl_vertex
    {
    private:
        //======================================================================
        //Typedefs.
        /**
         * The type of value which is used by <code>glpp::gl_vertex</code>.
         */
        typedef double value_type;
        /**
         * The const <code>value_type</code>.
         */
        typedef const value_type const_value_type;
        /**
         * The pointer to the <code>value_type</code>.
         */
        typedef value_type * value_type_ptr;
        /**
         * The pointer to the <code>const_value_type</code>.
         */
        typedef const_value_type * const_value_type_ptr;
        /**
         * The reference to the <code>value_type</code>.
         */
        typedef value_type & value_type_ref;
        /**
         * Alias of <code>value_type_ptr</code>.
         */
        typedef value_type_ptr iterator;
        /**
         * Alias of <code>const_value_type_ptr</code>.
         */
        typedef const_value_type_ptr const_iterator;
        //======================================================================
        //Friends.
        friend void submit(const gl_vertex &) noexcept;
        friend void submit(const gl_vertex &&) noexcept;
        //======================================================================
        //Static members.
    public:
        /**
         * The number of dimensions within the <code>glpp:gl_vertex</code>
         * objects.
         */
        static const unsigned int LENGTH;
    private:
        /**
         * The <code>std::string</code> containing the error message for
         * attempting to access a member of the <code>glpp::gl_vertex</code>
         * object.
         */
        static const std::string OUT_OF_RANGE_MESSAGE;
        //======================================================================
        //Members.
        /**
         * The coordinate of the first dimension.
         */
        value_type x_;
        /**
         * The coordinate of the second dimension.
         */
        value_type y_;
        /**
         * The coordinate of the third dimension.
         */
        value_type z_;
        /**
         * The coordinate of the fourth dimension.
         */
        value_type w_;
    public:
        //======================================================================
        //Constructors.
        /**
         * Initialise a <code>glpp::gl_vertex</code> by specifying the
         * coordinates of the <code>glpp::gl_vertex</code>.
         * 
         * @param x The x position.
         * @param y The y position.
         * @param z The z position.
         * @param w The w position.
         */
        constexpr gl_vertex(
                const_value_type x,
                const_value_type y,
                const_value_type z = 0.0,
                const_value_type w = 1.0)
                noexcept:
                x_(x),
                y_(y),
                z_(z),
                w_(w)
        {
        }
        /**
         * Copy constructor.
         * 
         * <p>
         * Copy the positional value of a <code>glpp::gl_vertex</code>.
         * </p>
         * 
         * @param orig The reference to the original
         *          <code>glpp::gl_vertex</code>.
         */
        gl_vertex(const gl_vertex & orig) noexcept;
        /**
         * Move constructor.
         * 
         * <p>
         * Move the positional value of a <code>glpp::gl_vertex</code> by
         * copying the values into the newly created
         * <code>glpp::gl_vertex</code>.
         * </p>
         * 
         * @param orig
         */
        gl_vertex(const gl_vertex && orig) noexcept;
        //======================================================================
        //Destructors.
        /**
         * Dertroy the <code>glpp::gl_vertex</code>.
         */
        ~gl_vertex() noexcept;
        //======================================================================
        //Member operators.
        /**
         * Copy assignment.
         * 
         * <p>
         * Copy the positional values of the original
         * <code>glpp::gl_vertex</code> into <code>this</code>.
         * </p>
         * 
         * @param The reference to the original <code>glpp::gl_vertex</code>.
         * @return <code>this</code> after the assignment.
         */
        gl_vertex & operator = (const gl_vertex & orig) noexcept;
        /**
         * Move assignment.
         * 
         * <p>
         * Move the positional values of the original
         * <code>glpp::gl_vertex</code> into <code>this</code>.
         * </p>
         * 
         * @param The rvalue reference to the original
         *          <code>glpp::gl_vertex</code>.
         * @return <code>this</code> after the assignment.
         */
        gl_vertex & operator = (const gl_vertex &&) noexcept;
        /**
         * 
         * @return 
         */
        value_type_ptr operator * () noexcept;
        /**
         * Get the pointer to the first coordinate of the
         * <code>glpp::gl_vertex</code>, which can be used to iterate through
         * the coordinates of <code>this</code>.
         * 
         * @return A pointer to the first <code>const_value_type_ptr</code> of
         *          <code>this</code> <code>glpp::gl_vertex</code>.
         */
        const_value_type_ptr operator * () const noexcept;
        /**
         * Get the coordinate which corresponds to the it's dimension.
         * 
         * <p>
         * Dimensions are indexed starting from 0. Therefore dimension 1
         * corresponds to index 0.
         * </p>
         * 
         * @param index The index of the coordinate.
         * @return The <code>value_type_ref</code> at that index.
         * @throws std::out_of_range If <code>index</code> is not less than
         *          <code>LENGTH</code>.
         */
        inline value_type_ref operator [] (unsigned int index)
                throw(std::out_of_range)
        {
            if(index < LENGTH)
                return *(**this + index);
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);
        }
        /**
         * Get the coordinate which corresponds to the it's dimension.
         * 
         * <p>
         * Dimensions are indexed starting from 0. Therefore dimension 1
         * corresponds to index 0.
         * </p>
         * 
         * @param index The index of the coordinate.
         * @return The <code>const_value_type</code> at that index.
         * @throws std::out_of_range If <code>index</code> is not less than
         *          <code>LENGTH</code>.
         */
        inline const_value_type operator [] (unsigned int index) const
                throw(std::out_of_range)
        {
            if(index < LENGTH)
                return *(**this + index);
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);
        }
        //======================================================================
        //Member functions.
        /**
         * Get the beginning of the <code>glpp::gl_vertex</code>.
         * 
         * @return The beginning of the <code>glpp::gl_vertex</code>.
         */
        iterator begin() noexcept;
        /**
         * Get the beginning of the <code>glpp::gl_vertex</code>.
         * 
         * @return The beginning of the <code>glpp::gl_vertex</code>.
         */
        const_iterator begin() const noexcept;
        /**
         * Get the end of the <code>glpp::gl_vertex</code>.
         * 
         * @return The end of the <code>glpp::gl_vertex</code>.
         */
        iterator end() noexcept;
        /**
         * Get the end of the <code>glpp::gl_vertex</code>.
         * 
         * @return The end of the <code>glpp::gl_vertex</code>.
         */
        const_iterator end() const noexcept;
    };
    //==========================================================================
    //Functions.
    /**
     * Submit a <code>glpp::gl_vertex</code> to OpenGL.
     * 
     * @param vert A reference to a <code>glpp::gl_vertex</code>.
     */
    inline void submit(const gl_vertex & vert) noexcept
    {
        glVertex3d(
                vert.x_/vert.w_,
                vert.y_/vert.w_,
                vert.z_/vert.w_);
    }
    /**
     * Submit a <code>glpp::gl_vertex</code> to OpenGL.
     * 
     * @param vert The rvalue reference to a <code>glpp::gl_vertex</code>.
     */
    inline void submit(const gl_vertex && vert) noexcept
    {
        glVertex3d(
                vert.x_/vert.w_,
                vert.y_/vert.w_,
                vert.z_/vert.w_);
    }
} //glpp
#endif //VERTEX_HPP