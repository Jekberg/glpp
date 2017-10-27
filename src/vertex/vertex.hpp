/* 
 * File:   vertex.hpp
 * Author: John
 *
 * Created on 12 October 2017, 11:42
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <type_traits>
#include <initializer_list>
#include "vertex_table.hpp"

namespace glpp
{
    //==========================================================================
    //vertex
    template<unsigned int, typename>
    class vertex;
    //--------------------------------------------------------------------------
    //2
    template<typename T>
    class vertex<2, T>
    {
    private:
            template<unsigned int, typename>
            friend class vertex;
            template<typename _T>
            void submit(const vertex<2, _T> &);
    protected:
        /*
         * Only enable if the T is primitive.
         */
        typedef typename std::enable_if<
                std::is_arithmetic<T>::value,
                T>::type value_type;
        typedef const value_type const_value_type;
    public:
        /**
         * The x-coordinate of the vertex representing the first dimension.
         */
        value_type x;
        /**
         * The y-coordinate of the vertex representing the second dimension.
         */
        value_type y;
        vertex() = delete; //No empty constructor.
        /**
         * 
         * @param x
         * @param y
         */
        constexpr vertex(
                const_value_type x,
                const_value_type y)
                noexcept:
                x(x),
                y(y)
        {
        }
        /**
         * Copy constructor.
         */
        constexpr vertex(const vertex<2, T> & orig)
                noexcept:
                vertex(orig.x, orig.y)
        {
        }
        value_type * operator * ()
        {
            return &x;
        }
        const_value_type * operator * () const
        {
            return &x;
        }
    };
    //--------------------------------------------------------------------------
    //2
    template<typename T>
    class vertex<3, T>: protected vertex<2, T>
    {
    private:
        template<unsigned int, typename>
        friend class vertex;
        template<typename _T>
        void submit(const vertex<3, _T> &);
    protected:
        typedef typename vertex<2, T>::value_type value_type;
        typedef typename vertex<2, T>::const_value_type const_value_type;
    public:
        using vertex<2, T>::x;
        using vertex<2, T>::y;
        value_type z;
        vertex() = delete; //No empty constructor.
        /**
         * 
         * @param x
         * @param y
         * @param z
         */
        constexpr vertex(
                const_value_type x,
                const_value_type y,
                const_value_type z)
                noexcept:
                vertex<2, T>::vertex(x, y),
                z(z)
        {
        }
        /**
         * 
         */
        constexpr vertex(const vertex<3, T> & orig)
                noexcept:
                vertex(orig.x, orig.y, orig.z)
        {
        }
        value_type * operator * ()
        {
            return &x;
        }
        const_value_type * operator * () const
        {
            return &x;
        }
    };
    //--------------------------------------------------------------------------
    //3
    template<typename T>
    class vertex<4, T>: protected vertex<3, T>
    {
    private:
        template<unsigned int, typename>
        friend class vertex;
        template<typename _T>
        void submit(const vertex<4, _T> &);
    protected:
        typedef typename vertex<3, T>::value_type value_type;
        typedef typename vertex<3, T>::const_value_type const_value_type;
    public:
        using vertex<3, T>::x;
        using vertex<3, T>::y;
        using vertex<3, T>::z;
        /**
         * The 
         */
        value_type w;
        vertex() = delete; //No empty constructor.
        /**
         * 
         * @param x
         * @param y
         * @param z
         * @param w
         */
        constexpr vertex(
                const_value_type x,
                const_value_type y,
                const_value_type z,
                const_value_type w)
                noexcept:
                vertex<3, T>::vertex(x, y, z),
                w(w)
        {
        }
        /**
         * 
         * @param orig
         */
        constexpr vertex(const vertex<4, T> & orig)
                noexcept:
                vertex(orig.x, orig.y, orig.z, orig.w)
        {
        }
        value_type * operator * ()
        {
            return &x;
        }
        const_value_type * operator * () const
        {
            return &x;
        }
    };
    /**
     * 
     * @param vertex
     */
    template<typename T>
    inline void submit(const vertex<2, T> & vertex) noexcept
    {
        vertex_table<2, T>::function(vertex.x, vertex.y);
    } //submit(const vertex<2, T> &)
    /**
     * 
     * @param vertex
     */
    template<typename T>
    inline void submit(const vertex<3, T> & vertex) noexcept
    {
        vertex_table<3, T>::function(vertex.x, vertex.y, vertex.z);
    } //submit(const vertex<3, T> &)
    /**
     * 
     * @param vertex
     */
    template<typename T>
    inline void submit(const vertex<4, T> & vertex) noexcept
    {
        vertex_table<4, T>::function(vertex.x, vertex.y, vertex.z, vertex.w);
    } //submit(const vertex<4, T> &)
} //glpp
#endif //VERTEX_HPP