#include "../matrix.hpp"

namespace glpp
{
    void matrix_space(const procedure callback)
            noexcept
    {
        glPushMatrix();
        {
            callback();
        }
        glPopMatrix();
    }
} //glpp