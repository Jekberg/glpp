#include "../colour.hpp"

namespace glpp
{
    //==========================================================================
    //Static fields.
    const rgba_colour rgba_colour::RED      = rgba_colour(0xFF, 0x0,  0x0);
    const rgba_colour rgba_colour::GREEN    = rgba_colour(0x0,  0xFF, 0x0);
    const rgba_colour rgba_colour::BLUE     = rgba_colour(0x0,  0x0,  0xFF);
    const rgba_colour rgba_colour::BLACK    = rgba_colour(0xFF, 0xFF, 0xFF);
    const rgba_colour rgba_colour::WHITE    = rgba_colour(0x0,  0x0,  0x0);
    const rgba_colour rgba_colour::CYAN     = rgba_colour(0x0,  0xFF, 0xFF);
    const rgba_colour rgba_colour::PURPLE   = rgba_colour(0xFF, 0x0,  0xFF);
    const rgba_colour rgba_colour::YELLOW   = rgba_colour(0xFF, 0xFF, 0x0);
    //==========================================================================
    //Destructors.
    rgba_colour::~rgba_colour() noexcept
    {
    }
} //glpp