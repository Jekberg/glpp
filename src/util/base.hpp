#ifndef BASE_HPP
#define BASE_HPP

#include <exception>
#include <string>

namespace glpp
{
    //==========================================================================
    //Classes.
    /**
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
        static_assert(
                std::is_fundamental<T>::value,
                "vector_base only works with fundamental types.");
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
    private:
        //======================================================================
        //Static members.
        //static const std::string OUT_OF_RANGE = "??";
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
        constexpr vector_base(Ts&&... elements):
                elements_{elements...}
        {
        }
        /**
         *
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
            throw std::out_of_range("");
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
} //glpp

#endif // BASE_HPP
