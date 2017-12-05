#ifndef COLOUR_HPP
#define COLOUR_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Classes.
    /**
     * The colour class is an abstraction of the RGBA format which is intended
     * for usage in OpenGL.
     *
     * @brief Colour for usage in OpenGL.
     */
    class colour
    {
    private:
        //======================================================================
        //Typedefs.
        /**
         * The value type used by the colour.
         */
        typedef GLubyte value_type;
        //======================================================================
        //Friends.
        friend void submit(const colour&) noexcept;
        friend void submit(const colour&&) noexcept;
    public:
        //======================================================================
        //Static members.
        /**
         * The colour black.
         */
        const static colour BLACK;
        /**
         * The colour white.
         */
        const static colour WHITE;
        /**
         * The colour red.
         */
        const static colour RED;
        /**
         * The colour green.
         */
        const static colour GREEN;
        /**
         * The colour blue.
         */
        const static colour BLUE;
        /**
         * The colour cyan.
         */
        const static colour CYAN;
        /**
         * The colour yellow.
         */
        const static colour YELLOW;
        /**
         * The colour purple.
         */
        const static colour PURPLE;
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
        colour() = delete;
        /**
         * Create a colour by specifying the values of red, green, blue and
         * alpha.
         *
         * @brief Create a colour with a red, green, blue and aplpha value.
         * @param red The red value.
         * @param green The green value.
         * @param blue The blue value.
         * @param alpha The alpha value, 0xFF by default.
         */
        constexpr explicit colour(
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
         * @brief Delete the colour.
         */
        ~colour() noexcept;
    };
    //==========================================================================
    //Functions.
    /**
     * @brief Submit a colour to OpenGL.
     * @param col The reference to the colour.
     */
    inline void submit(const colour& col) noexcept
    {
        glColor4ub(col.red_, col.green_, col.blue_, col.alpha_);
    }
    /**
     * @brief Submit a colour to OpenGL.
     * @param col The rvalue reference to the colour.
     */
    inline void submit(const colour&& col) noexcept
    {
        glColor4ub(col.red_, col.green_, col.blue_, col.alpha_);
    }
} //glpp

#endif //COLOUR_HPP
