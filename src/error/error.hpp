/*
 * File:    error.hpp
 * Author:  John Berg
 * Date:    28/10/2017
 */

#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>
#include <GL/gl.h>
#include <GL/glu.h>

namespace glpp
{
    /**
     * The error codes which can be raised by OpenGL.
     * 
     * <p>
     * Each enum corresponds to a <code>GLenum</code>.
     * </p>
     */
    enum class error_code: GLenum
    {
        INVALID_ENUM            = GL_INVALID_ENUM,
        INVALID_VALUE           = GL_INVALID_VALUE,
        INVALID_OPERATION       = GL_INVALID_OPERATION,
        STACK_OVERFLOW          = GL_STACK_OVERFLOW,
        STACK_UNDERFLOW         = GL_STACK_UNDERFLOW,
        OUT_OF_MEMORY           = GL_OUT_OF_MEMORY
    };
    //==========================================================================
    //Classes and structs.
    /**
     * The <code>glpp::error</code> is a wrapper class for the
     * <code>glpp::error_code</code>.
     * 
     * <p>
     * The <code>glpp::error</code> also provides utility for getting c string
     * representations of errors raised by OpenGL.
     * </p>
     */
    class error: std::exception
    {
        //======================================================================
        //Members.
    private:
        /**
         * The <code>error_code</code> which was raised.
         */
        error_code code_;
    public:
        //======================================================================
        //Constructors and destructors.
        //----------------------------------------------------------------------
        //Constructors.
        /**
         * Deleted.
         */
        error() = delete;
        /**
         * Create a <code>glpp::error</code> object with a
         * <code>glpp::error_code</code> that was raised by OpenGL.
         * 
         * @param code The error code which was raised.
         */
        explicit error(const error_code code) noexcept;
        /**
         * Copy constructor.
         * 
         * <p>
         * Create a <code>glpp::error</code> by copying an existing
         * <code>glpp::error</code> object, so that the newly created
         * <code>glpp::error</code> contains the same
         * <code>glpp::error_code</code>.
         * </p>
         * 
         * @param orig The reference to the original <code>glpp::error</code>
         *          object to be copied.
         */
        error(const error & orig) noexcept;
        /**
         * Move constructor.
         * 
         * <p>
         * Create a <code>glpp::error</code> object by copying the
         * <code>glpp::error_code</code> from the temporary object into the
         * newly created object. 
         * </p>
         * 
         * @param orig The rvalue reference of the original
         *          <code>glpp::error</code> object to be moved.
         */
        error(const error && orig) noexcept;
        //----------------------------------------------------------------------
        //Destructors.
        /**
         * Destroy the error.
         */
        virtual ~error();
        //======================================================================
        //Member operators.
        /**
         * Get the <code>glpp::error_code</code> which si contained within
         * <code>this</code> <code>glpp::error</code>.
         * 
         * @return The error code which was raised.
         */
        inline error_code code() const noexcept
        {
            return code_;
        }
        /**
         * Get the c string message which describes the cause of the exception.
         * 
         * <p>
         * Using gluErrorString(GLenum) to get the c string.
         * </p>
         * 
         * @return The c string error message.
         */
        virtual const char * what() const throw() override;
    };
    //==========================================================================
    //Functions.
    /**
     * Check if an error has been raised by OpenGL, then wrap the raised error
     * in with a <code>glpp::error</code> and throw it.
     * 
     * <p>
     * If no errors are raised, then this function does nothing.
     * </p>
     * 
     * @throws glpp::error If OpenGL raises an error.
     */
    inline void get_error()
            throw(error)
    {
        GLenum err = glGetError();
        if(err)
            throw error((error_code) err);
    }
} //glpp

#endif //ERROR_HPP