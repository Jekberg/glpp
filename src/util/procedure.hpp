/* 
 * File:    procedure.hpp
 * Author:  John Berg
 * Date:    29/10/2017
 */

#ifndef PROCEDURE_HPP
#define PROCEDURE_HPP

namespace glpp
{
    //==========================================================================
    /**
     * Alias for a functor which takes no arguments, and returns
     * <code>void</code>.
     */
    typedef const std::function<void ()> procedure;
} //glpp

#endif //PROCEDURE_HPP

