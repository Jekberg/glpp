#include "../colour.hpp"

namespace glpp
{
    //==========================================================================
    //Static fields.
    const colour colour::RED      = colour(0xFF, 0x0,  0x0);
    const colour colour::GREEN    = colour(0x0,  0xFF, 0x0);
    const colour colour::BLUE     = colour(0x0,  0x0,  0xFF);
    const colour colour::BLACK    = colour(0x0,  0x0,  0x0);;
    const colour colour::WHITE    = colour(0xFF, 0xFF, 0xFF);
    const colour colour::CYAN     = colour(0x0,  0xFF, 0xFF);
    const colour colour::PURPLE   = colour(0xFF, 0x0,  0xFF);
    const colour colour::YELLOW   = colour(0xFF, 0xFF, 0x0);
    //==========================================================================
    //Destructors.
    colour::~colour() noexcept
    {
    }
} //glpp
