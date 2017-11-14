/*
 * File:    vertex.hpp
 * Author:  John Berg
 * Date:    12/10/2017
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <stdexcept>
#include <utility>
#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Classes.
    template<std::size_t Size = 3>
    class vertex final: public vector_base<Size, float_type>
    {
        //======================================================================
        //Static asserts
    private:
        static_assert(Size < 5, "Unsupported vertex size.");
        static_assert(Size > 1, "Unsupported vertex size.");
    public:
        template<typename... Ts>
        constexpr vertex(Ts&&... elements):
                vector_base<Size, float_type>{std::forward<Ts>(elements)...}
        {
        }
        vertex(const vertex<Size>& orig):
                vector_base<Size, float_type>{orig}
        {
        }
        vertex(const vertex<Size>&&) = delete;
        virtual ~vertex() override final
        {
        }
    };
    //==========================================================================
    //Anon namespace.
    namespace
    {
        template<std::size_t Size>
        struct vertex_function_table;
        template<>
        struct vertex_function_table<2>
        {
            static constexpr const auto function = glVertex2fv;
        };
        template<>
        struct vertex_function_table<3>
        {
            static constexpr const auto function = glVertex3fv;
        };
        template<>
        struct vertex_function_table<4>
        {
            static constexpr const auto function = glVertex4fv;
        };
    } //anon
    /**
     *
     */
    template<std::size_t Size>
    void submit(const vertex<Size>& vert)
    {
        vertex_function_table<Size>::function(vert.begin());
    }
} //glpp
#endif //VERTEX_HPP
