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
    typedef class rgba_colour
    {
    private:
        typedef GLubyte value_type;
    public:
        static rgba_colour BLACK;
        static rgba_colour WHITE;
        static rgba_colour RED;
        static rgba_colour GREEN;
        static rgba_colour BLUE;
        static rgba_colour CYAN;
        static rgba_colour YELLOW;
        static rgba_colour PURPLE;
    private:
        const value_type r;
        const value_type g;
        const value_type b;
        const value_type a;
        constexpr rgba_colour(
                const value_type,
                const value_type,
                const value_type)
                noexcept;
        constexpr rgba_colour(
                const value_type,
                const value_type,
                const value_type,
                const value_type)
                noexcept;
    public:
        rgba_colour() = delete;
        //Friends.
        friend void submit(const rgba_colour &) noexcept;
        friend void submit(const rgba_colour &&) noexcept;
    }
    colour,
    color;
    void submit(const rgba_colour &) noexcept;
    void submit(const rgba_colour &&) noexcept;
} //glpp

#endif //COLOUR_HPP