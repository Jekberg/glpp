#include "../colour.hpp"

namespace glpp
{
    //==========================================================================
    //Static members.
    rgba_colour rgba_colour::RED      = rgba_colour(0xFF,   0x0,    0x0);
    rgba_colour rgba_colour::GREEN    = rgba_colour(0x0,    0xFF,   0x0);
    rgba_colour rgba_colour::BLUE     = rgba_colour(0x0,    0x0,    0xFF);
    rgba_colour rgba_colour::BLACK    = rgba_colour(0xFF,   0xFF,   0xFF);
    rgba_colour rgba_colour::WHITE    = rgba_colour(0x0,    0x0,    0x0);
    rgba_colour rgba_colour::CYAN     = rgba_colour(0x0,    0xFF,   0xFF);
    rgba_colour rgba_colour::PURPLE   = rgba_colour(0xFF,   0x0,    0xFF);
    rgba_colour rgba_colour::YELLOW   = rgba_colour(0xFF,   0xFF,   0x0);
    //==========================================================================
    //Constructors.
    rgba_colour::rgba_colour(
            const rgba_colour::value_type red,
            const rgba_colour::value_type green,
            const rgba_colour::value_type blue,
            const rgba_colour::value_type alpha)
            noexcept:
            red_(red),
            green_(green),
            blue_(blue),
            alpha_(alpha)
    {
    }
    //==========================================================================
    rgba_colour::~rgba_colour()
    {
    }
} //glpp