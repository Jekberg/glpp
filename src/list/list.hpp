/* 
 * File:    list.hpp
 * Author:  John Berg
 * Date:    27/10/2017
 */

#ifndef LIST_HPP
#define LIST_HPP

#include <functional>
#include <GL/gl.h>
#include "../error.hpp"
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Forward declarations.
    class gl_list;
    //==========================================================================
    //Typedefs.
    /**
     * Alias of <code>glpp::gl_list</code>.
     */
    typedef gl_list list;
    //==========================================================================
    //Enums.
    /**
     * The compilations modes available for list.
     */
    enum class list_mode: GLenum
    {
        COMPILE             = GL_COMPILE,
        COMPILE_AND_EXECUTE = GL_COMPILE_AND_EXECUTE
    };
    //==========================================================================
    //Classes.
    /**
     * The <code>gl_list</code> class is a wrapper around the OpenGL list which
     * manages lists as resources.
     */
    class gl_list
    {
    private:
        //======================================================================
        //Friends.
        friend gl_list create_list(list_mode, procedure)
                throw (error);
        friend void submit(const gl_list &) noexcept;
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
         * Create a <code>glpp:gl_list</code> which contains no list.
         */
        gl_list() noexcept;
    private:
        /**
         * Create a <code>glpp::list</code> using a specific compilation mode,
         * and a procedure with the details of the list.
         * 
         * @param mode The compilation mode.
         * @param callback The procedure with the details of the list.
         * @throws glpp::error If OpenGL raises an error.
         */
        gl_list(
                list_mode mode,
                procedure callback)
                throw(error);
    public:
        /**
         * Deleted.
         */
        gl_list(const gl_list &) = delete;
        /**
         * Move constructor.
         * 
         * <p>
         * Move the <list of a temporary <code>glpp::gl_list</code> into a
         * <code>glpp::gl_list</code> by taking the list of the temporary
         * <code>glpp::gl_list</code>.
         * </p>
         * 
         * @param orig The rvalue reference to the <code>glpp::gl_list</code>
         *          to be moved.
         */
        gl_list(gl_list && orig) noexcept;
        //======================================================================
        //Destructors.
        /**
         * Destroy the <code>glpp::gl_list</code>.
         * 
         * <p>
         * If no valid list is contained within <code>glpp::gl_list</code> then
         * nothing happens.
         * </p>
         */
        ~gl_list() noexcept;
        //======================================================================
        //Member operators.
        /**
         * Deleted. 
         */
        gl_list & operator = (const gl_list &) = delete;
        /**
         * Move assignment.
         * 
         * Move a <code>glpp::gl_list</code> into <code>this</code>.
         * 
         * @param orig The rvalue reference to the gl_list object to be moved into
         *      this object.
         * @return The reference to this object after the move.
         */
        gl_list & operator = (gl_list && orig) noexcept;
        //======================================================================
        //Member functions.
    private:
        /**
         * Release the list contained in <code>this</code>.
         * 
         * <p>
         * Does nothing if there is no list inside <code>this</code>.
         * </p>
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
     * Create a <code>glpp::gl_list</code>.
     * 
     * @param mode The compilation mode.
     * @param callback The procedure which contains the details of the list.
     * @return The newly created <code>glpp::gl_list</code>.
     * @throws glpp::error If OpenGL raises an error.
     */
    inline gl_list create_list(
            list_mode mode,
            procedure callback)
            throw(error)
    {
        return gl_list(mode, callback);
    }
    /**
     * Submit a call to a <code>glpp::gl_list</code> to OpenGL.
     * 
     * @param li The <code>glpp::gl_list</code> to be called.
     */
    inline void submit(const gl_list & li) noexcept
    {
        glCallList(li.handle_);
    }
} //glpp;

#endif //LIST_HPP