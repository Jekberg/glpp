#ifndef GLPP_SRC_DESIGN_LIST_HPP
#define GLPP_SRC_DESIGN_LIST_HPP

#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Classes.
    /**
     * The list class is a wrapper around the OpenGL list which
     * manages lists as resources.
     *
     * @brief A wrapper class around an OpenGL display %list.
     */
    class list
    {
        //======================================================================
        //Friends.
    private:
        template<typename F>
        friend list create_list(list_mode, F);
        friend void submit(const list &) noexcept;
        //======================================================================
        //Static members.
        /**
         * The representation of a non-existing list.
         */
        const static GLuint NO_LIST;
        /**
         * The size of the group of lists to generate.
         */
        const static GLuint SIZE;
        //======================================================================
        //Members.
        /**
         * The representation of the list.
         */
        GLuint handle_;
        //======================================================================
        //Constructors.
    public:
        /**
         * @brief Create a list which contains no %list.
         */
        list() noexcept;
    private:
        /**
         * Create a list using a specific compilation mode, and a procedure with
         * the details of the list.
         *
         * @brief Construct a list object.
         * @param mode The list_mode used during construction.
         * @param callback The procedure with the details of the list.
         * @throw error If OpenGL raises an error.
         * @throw std::exception If The callback throws a std::exception.
         */
        template<typename F>
        list(
                list_mode mode,
                F callback) try:
                handle_(glGenLists(SIZE))
        {
            //Check errors after generation.
            get_error();
            glNewList(handle_, (GLenum) mode);
            callback();
            glEndList();
            get_error(); //Check if any errors have been raised.
        }
        catch(const std::exception& e)
        {
            release();
            throw;
        }
    public:
        /**
         * Deleted.
         */
        list(const list &) = delete;
        /**
         * Move the list of a temporary list into a list by taking the list of
         * the temporary list.
         *
         * @brief Move constructor.
         * @param orig The rvalue reference to the list to be moved.
         */
        list(list&& orig) noexcept;
        //======================================================================
        //Destructors.
        /**
         * If no valid list is contained within list then nothing happens.
         *
         *@brief Destroy the list.
         */
        ~list() noexcept;
        //======================================================================
        //Member operators.
        /**
         * Deleted.
         */
        list & operator = (const list &) = delete;
        /**
         * Move a list into this list.
         *
         * @brief Move assignment.
         * @param orig The rvalue reference to the list object to be moved
         *      into this object.
         * @return The reference to this object after the move.
         */
        list & operator = (list && orig) noexcept;
        //======================================================================
        //Member functions.
    private:
        /**
         * Does nothing if there is no list inside <code>this</code>.
         *
         * @brief Release the list contained in this list.
         */
        inline void release() noexcept
        {
            if(!handle_)
                glDeleteLists(handle_, SIZE);
        }
    };
    //==========================================================================
    //Functions.
    /**
     * Create a list object by calling a procedure containing the steps to
     * creating the list.
     *
     * @brief Create a list object.
     * @param mode The compilation mode.
     * @param callback The procedure which contains the details of the list.
     * @return The newly created list.
     * @throw error If OpenGL raises an error.
     * @throw std::exception If the callback throws.
     */
    template<typename F>
    inline list create_list(
            list_mode mode,
            F callback)
    {
        return list(mode, callback);
    }
    /**
     * The result of this method is the equivalent of calling
     * glCallList(GLuint).
     *
     * @brief Submit a call to a list.
     * @param li The list to be called.
     */
    inline void submit(const list & li) noexcept
    {
        glCallList(li.handle_);
    }
} //glpp;

#endif //GLPP_SRC_DESIGN_LIST_HPP
