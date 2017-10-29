/* 
 * File:    colour.hpp
 * Author:  John Berg
 * Date:    27/10/2017
 */

#ifndef COLOUR_HPP
#define COLOUR_HPP

#include <GL/gl.h>

namespace glpp
{
    //==========================================================================
    //Classes.
    /**
     * <code>rgba_colour</code> class is an abstraction of the byte colours used
     * by OpenGL.
     */
    typedef class rgba_colour
    {
    private:
        //======================================================================
        //Typedefs.
        /**
         * The type used within the <code>rgba_colour</code> class.
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
         * The <code>rgba_colour</code> representing the colour black.
         */
        static rgba_colour BLACK;
        /**
         * The <code>rgba_colour</code> representing the colour white.
         */
        static rgba_colour WHITE;
        /**
         * The <code>rgba_colour</code> representing the colour red.
         */
        static rgba_colour RED;
        /**
         * The <code>rgba_colour</code> representing the colour green.
         */
        static rgba_colour GREEN;
        /**
         * The <code>rgba_colour</code> representing the colour blue.
         */
        static rgba_colour BLUE;
        /**
         * The <code>rgba_colour</code> representing the colour cyan.
         */
        static rgba_colour CYAN;
        /**
         * The <code>rgba_colour</code> representing the colour yellow.
         */
        static rgba_colour YELLOW;
        /**
         * The <code>rgba_colour</code> representing the colour purple.
         */
        static rgba_colour PURPLE;
    private:
        //======================================================================
        //Members
        /**
         * The byte which represent the value of red.
         */
        const value_type red_;
        /**
         * The byte which represents the value of green.
         */
        const value_type green_;
        /**
         * The byte which represents the value of blue.
         */
        const value_type blue_;
        /**
         * The byte which represents the alpha value.
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
         * Create a colour for a given colour by specifying the 3 to 4 bytes
         * which represent the colour channels.
         * 
         * @param red The hex-code for the colour channel red.
         * @param green The hex-code for the colour channel green.
         * @param blue The hex-colour for the colour channel blue.
         * @param alpha The hex-code for the alpha channel. Is <code>0xFF</code>
         *          by default.
         */
        explicit rgba_colour(
                const value_type red,
                const value_type green,
                const value_type blue,
                const value_type alpha = 0xFF)
                noexcept;
        //======================================================================
        //Destructors.
        /**
         * Destroy the <code>rgba_colour</code>.
         */
        ~rgba_colour() noexcept;
    }
    colour,
    color;
    /**
     * Submit a <code>rgba_colour</code> colour to OpenGL.
     * 
     * @param col The reference to the <code>rgba_colour</code> to be submitted.
     */
    inline void submit(const rgba_colour & col) noexcept
    {
        glColor4ub(col.red_, col.green_, col.blue_, col.alpha_);
    }
    /**
     * Submit a <code>rgba_colour</code> colour to OpenGL.
     * 
     * @param col The rvalue reference to the <code>rgba_colour</code> to be
     *          submitted.
     */
    inline void submit(const rgba_colour && col) noexcept
    {
        glColor4ub(col.red_, col.green_, col.blue_, col.alpha_);
    }
} //glpp

#endif //COLOUR_HPP