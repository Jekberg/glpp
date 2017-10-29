/* 
 * File:    colour.hpp
 * Author:  John
 * Date:    27/10/2017
 */

#ifndef COLOUR_HPP
#define COLOUR_HPP

#include <GL/gl.h>

namespace glpp
{
    //==========================================================================
    //Forward declarations.
    class rgba_colour;
    //==========================================================================
    //Typedefs.
    /**
     * Alias of <code>glpp::rgba_colour</code>.
     */
    typedef rgba_colour colour;
    //==========================================================================
    //Classes.
    /**
     * 
     */
    class rgba_colour
    {
        //======================================================================
        //Typedefs.
    private:
        /**
         * The value type used by the <code>glpp::rgba_colour</code>.
         */
        typedef GLubyte value_type;
        //======================================================================
        //Friends.
        friend void submit(const rgba_colour &) noexcept;
        friend void submit(const rgba_colour &&) noexcept;
    public:
        //======================================================================
        //Static members.
        /**
         * The colour black.
         */
        const static rgba_colour BLACK;
        /**
         * The colour white.
         */
        const static rgba_colour WHITE;
        /**
         * The colour red.
         */
        const static rgba_colour RED;
        /**
         * The colour green.
         */
        const static rgba_colour GREEN;
        /**
         * The colour blue.
         */
        const static rgba_colour BLUE;
        /**
         * The colour cyan.
         */
        const static rgba_colour CYAN;
        /**
         * The colour yellow.
         */
        const static rgba_colour YELLOW;
        /**
         * The colour purple.
         */
        const static rgba_colour PURPLE;
        //======================================================================
        //Members.
    private:
        /**
         * The value representing red.
         */
        const value_type red_;
        /**
         * The value representing green.
         */
        const value_type green_;
        /**
         * The value representing blue.
         */
        const value_type blue_;
        /**
         * The alpha value.
         */
        const value_type alpha_;
        //======================================================================
        //Constructors.
    public:
        /**
         * Deleted.
         */
        rgba_colour() = delete;
        /**
         * Create a <code>glpp::rgba_colour</code> by specifying the values
         * of red, green, blue and alpha.
         * 
         * @param red The red value.
         * @param green The green value.
         * @param blue The blue value.
         * @param alpha The alpha value, 0xFF by default.
         */
        constexpr explicit rgba_colour(
                const value_type red,
                const value_type green,
                const value_type blue,
                const value_type alpha = 0xFF)
                noexcept:
                red_(red),
                green_(green),
                blue_(blue),
                alpha_(alpha)
        {
        }
        //======================================================================
        //Destructors.
        /**
         * Destroy the <code>glpp::rgba_colour</code>.
         */
        ~rgba_colour() noexcept;
    };
    //==========================================================================
    //Functions.
    /**
     * Submit a <code>glpp::rgba_colour</code> to OpenGL.
     * 
     * @param col The reference to the <code>glpp::rgba_colour</code>.
     */
    inline void submit(const rgba_colour & col) noexcept
    {
        glColor4ub(col.red_, col.green_, col.blue_, col.alpha_);
    }
    /**
     * Submit a <code>glpp::rgba_colour</code> to OpenGL.
     * 
     * @param col The rvalue reference to the <code>glpp::rgba_colour</code>.
     */
    inline void submit(const rgba_colour && col) noexcept
    {
        glColor4ub(col.red_, col.green_, col.blue_, col.alpha_);
    }
} //glpp

#endif //COLOUR_HPP