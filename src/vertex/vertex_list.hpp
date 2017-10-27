/* 
 * File:   vertex_list.hpp
 * Author: John
 *
 * Created on 15 October 2017, 21:20
 */

#ifndef VERTEX_LIST_HPP
#define VERTEX_LIST_HPP

#include <algorithm>
#include <initializer_list>
#include "vertex.hpp"

namespace glpp
{
    template<unsigned int Length, typename T>
    class vertex_list
    {
    private:
        typedef vertex<Length, T> value_type;
        typedef const value_type const_value_type;
        typedef value_type * iterator;
        typedef const_value_type * const_iterator;
        const std::size_t size_;
        value_type * elements_;
    public:
        vertex_list() = delete;
        constexpr explicit vertex_list(const std::size_t size)
                throw(std::bad_array_new_length):
                size_(size),
                elements_(new value_type[size])
        {
        }
        constexpr vertex_list(const std::initializer_list<
                vertex<Length, T>> & vertecies)
                throw(std::bad_array_new_length):
                vertex_list(vertecies.size())
        {
            std::copy(vertecies.begin(), vertecies.end(), elements_);
        }
        iterator begin()
        {
            return elements_;
        }
        const_iterator begin() const
        {
            return elements_;
        }
        iterator end()
        {
            return begin() + size_;
        }
        const_iterator end() const
        {
            return begin() + size_;
        }
    };
    template<unsigned int Length, typename T>
    void submit(const vertex_list<Length, T> & list) noexcept
    {
        std::for_each(list.begin(), list.end(), submit);
    };
} //glpp

#endif //VERTEX_LIST_HPP