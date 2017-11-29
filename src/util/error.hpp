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
     * @brief The error codes which can be raised by OpenGL.
     *
     * Each enum value corresponds to a @typedef GLenum.
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
    class error final: public std::exception
    {
        //======================================================================
        //Members.
    private:
        /**
         * @brief The error_code which was raised.
         */
        error_code code_;
        //======================================================================
        //Constructors.
    public:
        /**
         * Deleted.
         */
        error() = delete;
        /**
         * Create an error object with an error_code that was raised by OpenGL.
         *
         * @param code The error_code which was raised.
         */
        explicit error(const error_code code) noexcept;
        /**
         * @brief Copy constructor.
         *
         * <p>
         * Create an error by copying an existing error object, so that the
         * newly created error contains the same error_code.
         * </p>
         *
         * @param orig The reference to the original error object to be copied.
         */
        error(const error& orig) noexcept;
        //======================================================================
        //Destructors.
        /**
         * @brief Destructor.
         *
         * Destroy the error.
         */
        virtual ~error();
        //======================================================================
        //Member operators.
        /**
         * @brief Get the error_code from this error.
         * @return The error_code which was raised.
         */
        inline error_code code() const noexcept
        {
            return code_;
        }
        /**
         * @brief Get the string representation of the error.
         *
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
     * @throw glpp::error If OpenGL raises an error.
     */
    void get_error();
} //glpp

#endif //ERROR_HPP
