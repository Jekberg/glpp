#ifndef BASE_HPP
#define BASE_HPP

#include <exception>
#include <string>

namespace glpp
{
    //==========================================================================
    //Classes.
    /**
     * The <code>glpp::vector_base</code> class provides basic functionality of
     * vector-like data types.
     *
     * <p>
     * <code>glpp::vector_base</code> restricts types to only contain
     * fundamental data types.
     * </p>
     *
     * @param Size The number of elements which can be held by
     *              <code>glpp::vector_base</code>.
     * @param T The type of the elements within <code>glpp::vector_base</code>.
     */
    template<std::size_t Size, typename T>
    class vector_base
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
         * The value type in <code>this</code> <code>glpp::vector_base</code>.
         */
        typedef T value_type;
        /**
         * The const value type in <code>this</code>
         * <code>glpp::vector_base</code>.
         */
        typedef const value_type const_value_type;
        /**
         * The pointer to the value type in <code>this</code>
         * <code>glpp::vector_base</code>.
         */
        typedef value_type* iterator;
        /**
         * The const pointer to the value type in <code>this</code>
         * <code>glpp::vector_base</code>.
         */
        typedef const_value_type* const_iterator;
        /**
         * The reference to the value type in <code>this</code>
         * <code>glpp::vector_base</code>.
         */
        typedef value_type& value_type_ref;
        /**
         * The const reference to the value type in <code>this</code>
         * <code>glpp::vector_base</code>.
         */
        typedef const_value_type& const_value_type_ref;
        //======================================================================
        //Static members.
        /**
         * The c string which contains an error message for when attempting to
         * access an element at an index which exceeds the size of the vector.
         */
        static constexpr const char* OUT_OF_RANGE_MESSAGE =
                "Index out of range";
        //======================================================================
        //Members.
        /**
         * The pointer to the array of elements in the
         * <code>glpp::vector_base</code>.
         */
        value_type elements_[Size];
        //======================================================================
        //Constructors.
    public:
        /**
         * Initialise a <code>glpp::vector_base</code> with predefined values.
         *
         * <p>
         * If attempting to initialize the <code>glpp::vector_base</code> with
         * more elements that the vector can contain, then compilation will
         * fail.
         * </p>
         *
         * <p>
         * Providing the <code>glpp::vector</code> with fewer elements that
         * the specified size, the remaining elements will be initialized with
         * a default value.
         * </p>
         *
         * @param Ts The variadic template type.
         * @param elements The parameter pack containing the initial values of
         *                  the vector.
         */
        template<typename... Ts>
        constexpr vector_base(const Ts&&... elements):
                elements_{static_cast<T>(elements)...}
        {
        }
        /**
         * Copy constructor.
         *
         * <p>
         * Creates a <code>glpp::vector_base</code> which is exactly equal to
         * another <code>glpp::vector_base</code>.
         * </p>
         *
         * <p>
         * Copy each the elements inside the original
         * <code>glpp::vector_base</code> into a newly created
         * <code>glpp::vector_base</code>.
         * </p>
         *
         * @param orig The original <code>glpp::vector_base</code> to be copied.
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
         * Destroy the <code>glpp::vector_base</code>.
         */
        virtual ~vector_base() noexcept
        {
        }
        //======================================================================
        //Member operators.
        /**
         * Get the size of <code>this</code> <code>glpp::vector_base</code>.
         *
         * @return The number of elements in <code>this</code>.
         */
        constexpr std::size_t size() const noexcept
        {
            return Size;
        }
        /**
         * Get the beginning of <code>this</code>
         * <code>glpp::vector_base</code>.
         *
         * @return The iterator to the first element of <code>this</code>.
         */
        constexpr iterator begin() noexcept
        {
            return elements_;
        }
        /**
         * Get the beginning of <code>this</code>
         * <code>glpp::vector_base</code>.
         *
         * <p>
         * <code>const</code> overload.
         * </p>
         *
         * @return The iterator to the first element of <code>this</code>.
         */
        constexpr const_iterator begin() const noexcept
        {
            return elements_;
        }
        /**
         * Get the end of <code>this</code>
         * <code>glpp::vector_base</code>.
         *
         * @return The iterator to the end of <code>this</code>.
         */
        constexpr iterator end() noexcept
        {
            return begin() + Size;
        }
        /**
         * Get the end of <code>this</code>
         * <code>glpp::vector_base</code>.
         *
         * <p>
         * <code>const</code> overload.
         * </p>
         *
         * @return The iterator to the end of <code>this</code>.
         */
        constexpr const_iterator end() const noexcept
        {
            return begin() + Size;
        }
        //======================================================================
        //Member operators.
        /**
         * Copy assignment.
         *
         * <p>
         * Copy all the elements of one <code>glpp::vector_base</code> into
         * <code>this</code>. All the current values will be over-written.
         * </p>
         *
         * @return <code>this</code> after the operation.
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
         * <code>glpp::vector_base</code> by reference.
         *
         * @param index The index of the element to be retrieved.
         * @return The reference to the element at the <code>index</code>.
         * @throw std::out_of_range If <code>index</code> is equal to or greater
         *          than <code>size</code>.
         */
        value_type_ref operator[] (const std::size_t index)
        {
            if(index < Size)
                return elements_[index];
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);
        }
        /**
         * Get the element at a given index within <code>this</code>
         * <code>glpp::vector_base</code> by <code>const</code> value.
         *
         * <p>
         * <code>const</code> overload.
         * </p>
         *
         * @param index The index of the element to be retrieved.
         * @return The reference to the element at the <code>index</code>.
         * @throw std::out_of_range If <code>index</code> is equal to or greater
         *          than <code>size</code>.
         */
        const_value_type operator[] (const std::size_t index) const
        {
            if(index < Size)
                return elements_[index];
            throw std::out_of_range("");
        }
    };
    //==========================================================================
    //Functions.
    /**
     * Compile time get function, which can retrieve elements from a
     * <code>glpp::vector_base</code> by value.
     *
     * <p>
     * Attempting to access a value outside the range of the vector will result
     * in failure to compile.
     * </p>
     *
     * @param Index The index of the element.
     * @param Size The size of the <code>glpp::vector_base</code>.
     * @param T The type contained within <code>glpp::vector_base</code>.
     * @param vect The <code>glpp::vector_base</code> to retrieve the element
     *              from.
     * @return The value of the <code>glpp::vector_base</code> at
     *          <code>Index</code>.
     */
    template<std::size_t Index, std::size_t Size, typename T>
    constexpr T get(const vector_base<Size, T>& vect) noexcept
    {
        static_assert(Index < Size, "Index out of bounds.");
        return vect.elements_[Index];
    }
} //glpp

#endif // BASE_HPP
