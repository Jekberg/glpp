#ifndef GLPP_SRC_UTIL_VECTOR_HPP
#define GLPP_SRC_UTIL_VECTOR_HPP

#include <algorithm>
#include <stdexcept>

namespace glpp
{
    //==========================================================================
    //Classes.
    /**
     * The vector_base class provides basic functionality of vector-like
     * data types.
     *
     * <p>
     * vector_base restricts types to only contain fundamental data types.
     * </p>
     *
     * @brief A vector of predefined size which can store fundamental types.
     * @param Size The number of elements which can be held by vector_base.
     * @param T The type of the elements within vector_base.
     */
    template<std::size_t Size, typename T>
    class vector_base final
    {
        //======================================================================
        //Static asserts.
    private:
        static_assert(
                std::is_fundamental<T>::value,
                "vector_base only works with fundamental types.");
        //======================================================================
        //Friends
        template<std::size_t Index, std::size_t _Size, typename _T>
        friend constexpr _T get(const vector_base<_Size, _T>&) noexcept;
        //======================================================================
        //Typedefs.
        /**
         * @brief The value type in the vector_base.
         */
        typedef T value_type;
        /**
         * @brief The const value type in the vector_base.
         */
        typedef const value_type const_value_type;
        /**
         * @brief The pointer to the value type in the vector_base.
         */
        typedef value_type* iterator;
        /**
         * @brief The const pointer to the value type in the vector_base.
         */
        typedef const_value_type* const_iterator;
        /**
         * @brief The reference to the value type in the vector_base.
         */
        typedef value_type& value_type_ref;
        /**
         * @brief The const reference to the value type in the vector_base.
         */
        typedef const_value_type& const_value_type_ref;
        //======================================================================
        //Static members.
        /**
         * The C-string which contains an error message for when attempting to
         * access an element at an index which exceeds the size of the vector.
         *
         * @brief The error message for when accessing an out of range element.
         */
        static constexpr const char* OUT_OF_RANGE_MESSAGE =
                "Index out of range";
        //======================================================================
        //Members.
        /**
         * @brief The pointer to the array of elements in the vector_base.
         */
        value_type elements_[Size];
        //======================================================================
        //Constructors.
    public:
        /**
         * Initialise a vector_base with predefined values.
         *
         * <p>
         * If attempting to initialize the vector_base with more elements that
         * the vector can contain, then compilation will
         * fail.
         * </p>
         *
         * <p>
         * Providing the vector with fewer elements that the specified size,
         * the remaining elements will be initialized with a default value.
         * </p>
         *
         * @brief Construct a vector_base by defining the elements to be
         *              contained.
         * @param elements The parameter pack containing the initial values of
         *                  the vector.
         */
        template<typename... Ts>
        constexpr vector_base(const Ts&&... elements):
                elements_{static_cast<T>(elements)...}
        {
        }
        /**
         * Creates a vector_base which is exactly equal to another vector_base.
         *
         * <p>
         * Copy each the elements inside the original vector_base into a newly
         * created vector_base.
         * </p>
         *
         * @brief Copy constructor.
         * @param orig The original vector_base to be copied.
         */
        vector_base(const vector_base<Size, T>& orig)
        {
            //Copy the elements of the first vector_base into this.
            std::copy(
                      orig.elements_,
                      orig.elements_ + Size,
                      elements_);
        }
        /**
         * Deleted.
         */
        vector_base(vector_base<Size, T>&& orig) = delete;
        //======================================================================
        //Destructor.
        /**
         * @brief Destroy the vector_base.
         */
        ~vector_base() noexcept
        {
        }
        //======================================================================
        //Member operators.
        /**
         * Get the size of this vector_base.
         *
         * @brief Get the number of elements in this vector_base.
         * @return The number of elements in this.
         */
        constexpr std::size_t size() const noexcept
        {
            return Size;
        }
        /**
         * Get the beginning of this vector_base.
         *
         * @brief Get the iterator to the first element.
         * @return The iterator to the first element of this vector_base.
         */
        constexpr iterator begin() noexcept
        {
            return elements_;
        }
        /**
         * Get the beginning of this vector_base.
         *
         * <p>
         * <code>const</code> overload.
         * </p>
         *
         * @brief Get the const_iterator to the first element.
         * @return The iterator to the first element of this vector_base.
         */
        constexpr const_iterator begin() const noexcept
        {
            return elements_;
        }
        /**
         * Get the end of this vector_base.
         *
         * @brief Get the iterator which marks the end.
         * @return The iterator to the end of this vector_base.
         */
        constexpr iterator end() noexcept
        {
            return begin() + Size;
        }
        /**
         * Get the end of this vector_base.
         *
         * <p>
         * <code>const</code> overload.
         * </p>
         *
         * @brief Get the const_iterator which marks the end.
         * @return The iterator to the end of this vector_base.
         */
        constexpr const_iterator end() const noexcept
        {
            return begin() + Size;
        }
        //======================================================================
        //Member operators.
        /**
         * Copy all the elements of one vector_base into
         * this vector_base. All the current values will be over-written.
         *
         * @brief Copy assignment.
         * @return this vector_base after the operation.
         */
        vector_base<Size, value_type>& operator= (
                const vector_base<Size, value_type>& orig)
                noexcept
        {
            std::copy(orig.begin(), orig.end(), begin());
            return *this;
        }
        /**
         * Deleted.
         */
        vector_base<Size, value_type>& operator= (
                const vector_base<Size, value_type>&& orig) = delete;
        /**
         * Get the element at a given index within <code>this</code>
         * vector_base by reference.
         *
         * @brief Get the element at a specified position.
         * @param index The index of the element to be retrieved.
         * @return The reference to the element at the <code>index</code>.
         * @throw std::out_of_range If <code>index</code> is equal to or greater
         *          than the size of the vector_base.
         */
        value_type_ref operator[] (const std::size_t index)
        {
            if(index < Size)
                return elements_[index];
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);
        }
        /**
         * Get the element at a given index within this vector_base by value.
         *
         * <p>
         * <code>const</code> overload.
         * </p>
         *
         * @brief Get the element at a specified position.
         * @param index The index of the element to be retrieved.
         * @return The reference to the element at the <code>index</code>.
         * @throw std::out_of_range If <code>index</code> is equal to or greater
         *          than the size of the vector_base.
         */
        value_type operator[] (const std::size_t index) const
        {
            if(index < Size)
                return elements_[index];
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);
        }
    };
    //==========================================================================
    //Functions.
    /**
     * Compile time get function, which can retrieve elements from a vector_base
     * by value.
     *
     * <p>
     * Attempting to access a value outside the range of the vector will result
     * in failure to compile.
     * </p>
     *
     * @brief Get the element at a given position in the vector_base.
     * @param vect The reference to the vector_base to retrieve the element
     *          from.
     * @return The value of the vector_base at <code>Index</code>.
     */
    template<std::size_t Index, std::size_t Size, typename T>
    constexpr T get(const vector_base<Size, T>& vect) noexcept
    {
        static_assert(Index < Size, "Index out of bounds.");
        return vect.elements_[Index];
    }
} //glpp

#endif //GLPP_SRC_UTIL_VECTOR_HPP
