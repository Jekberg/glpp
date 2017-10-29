#include "../colour.hpp"

namespace glpp
{
    //==========================================================================
    //Static fields.
    rgba_colour rgba_colour::RED      = {0xFF, 0x0, 0x0};
    rgba_colour rgba_colour::GREEN    = {0x0, 0xFF, 0x0};
    rgba_colour rgba_colour::BLUE     = {0x0, 0x0, 0xFF};
    rgba_colour rgba_colour::BLACK    = {0xFF, 0xFF, 0xFF};
    rgba_colour rgba_colour::WHITE    = {0x0, 0x0, 0x0};
    rgba_colour rgba_colour::CYAN     = {0x0, 0xFF, 0xFF};
    rgba_colour rgba_colour::PURPLE   = {0xFF, 0x0, 0xFF};
    rgba_colour rgba_colour::YELLOW   = {0xFF, 0xFF, 0x0};
    //==========================================================================
    //Constructors.
    constexpr rgba_colour::rgba_colour(
            const rgba_colour::value_type r,
            const rgba_colour::value_type g,
            const rgba_colour::value_type b)
            noexcept:
            rgba_colour::rgba_colour(r, g, b, 0xFF)
    {
    }
    constexpr rgba_colour::rgba_colour(
            const rgba_colour::value_type r,
            const rgba_colour::value_type g,
            const rgba_colour::value_type b,
            const rgba_colour::value_type a)
            noexcept:
            r(r),
            b(b),
            g(g),
            a(a)
    {
    }
    //==========================================================================
    //Functions.
    void submit(const rgba_colour & c) noexcept
    {
        glColor4ub(c.r, c.g, c.b, c.a);
    } //submit(const colour &&) noexcept
    void submit(const rgba_colour && c) noexcept
    {
        glColor4ub(c.r, c.g, c.b, c.a);
    } //submit(const colour &&) noexcept
} //glpp