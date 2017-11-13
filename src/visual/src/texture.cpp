#include "../texture.hpp"

namespace glpp
{
    //==========================================================================
    //Static members.
    const GLuint texture::SIZE = 1;
    const std::string texture::NO_VALID_TEXTURE = "No valid texture.";
    //==========================================================================
    //Destructor.
    texture::~texture() noexcept
    {
        release();
    }
    //==========================================================================
    //Member operators.
    texture& texture::operator= (texture&& orig) noexcept
    {
        release();
        target_ = orig.target_;
        handle_ = orig.handle_;
        orig.handle_ = NO_TEXTURE;
        return *this;
    }
} //glpp
