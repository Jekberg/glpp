#include "../matrix.hpp"

namespace glpp
{
    void matrix_space(procedure callback)
            noexcept
    {
        glPushMatrix();
        {
            callback();
        }
        glPopMatrix();
    }
} //glpp