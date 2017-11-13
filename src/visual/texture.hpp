/*
 * File:    texture.hpp
 * Author:  John Berg
 * Date:    03/11/2017
 */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP


#include <iostream>
#include <exception>
#include <GL/gl.h>
#include "../util.hpp"

namespace glpp
{
    //==========================================================================
    //Forward declarations.
    /**
     */
    class texture final
    {
        //======================================================================
        //Friends.
        template<typename F>
        friend texture load_texture(const std::string&, GLenum, F load_strategy)
        noexcept(noexcept(load_strategy("", 0, 0)));
        friend void submit(const texture&);
        //======================================================================
        //Static members.
    private:
        /**
         * The size of how many textures to generate.
         */
        static const GLuint SIZE;
        /**
         * The numeric value representing the an invalid texture.
         */
        static constexpr const GLuint NO_TEXTURE = 0;
        /**
         * The string containing the message for when a texture which is invalid
         * has been bind.
         */
        static const std::string NO_VALID_TEXTURE;
        //======================================================================
        //Members.
        /**
         *
         */
        GLenum target_;
        /**
         * The numeric value which represents this texture.
         */
        GLuint handle_;
        //======================================================================
        //Constructors.
    public:
        /**
         *
         */
        constexpr texture() noexcept:
                target_(GL_TEXTURE_2D),
                handle_(NO_TEXTURE)
        {
        }
        /**
         *
         * @param target
         */
        inline texture(GLenum target):
                target_(target)
        {
            glGenTextures(SIZE, &handle_);
            get_error();
        }
        /**
         * Deleted.
         */
        texture(const texture&) = delete;
        /**
         *
         * @param The rvalue reference to the <code>glpp::texture</code> to be
         *       moved
         */
        texture(texture&& orig):
                target_(orig.target_),
                handle_(orig.handle_)
        {
            orig.handle_ = NO_TEXTURE;
        }
        //======================================================================
        //Destructor.
        /**
         * Destroy the <code>glpp::texture</code> and free the resource.
         */
        ~texture() noexcept;
        //======================================================================
        //Member functions
    private:
        /**
         *
         */
        inline void release() noexcept
        {
            //Destroy the texture if the texture is still in use.
            if(handle_)
                glDeleteTextures(SIZE, &handle_);
        }
        //======================================================================
        //Member operators.
    public:
        /**
         * Deleted.
         */
        texture operator= (const texture&) = delete;
        /**
         *
         *
         */
        texture& operator= (texture&& orig) noexcept;
    };
    /**
     * Load a texture.
     *
     * <p>
     * A callback must be provided to help the set up of the texture.
     * </p>
     *
     * <p>
     * If the <code>load_strategy</code> may throw, then this function may also
     * throw; however, if <code>load_strategy</code> may not throw, then neither
     * will this function.
     * </p>
     *
     * @param filename The reference to a string representing the name of the
     *          file to be loaded.
     * @param target The type of texture to be loaded.
     * @param A function which defines the strategy of loading the textures.
     * @return A <code>glpp::texture</code> object representing the loaded
     *          texture.
     */
    template<typename F>
    texture load_texture(
                         const std::string& filename,
                         GLenum target,
                         F load_strategy)
                         noexcept(noexcept(load_strategy("", 0, 0)))
    {
        texture tex(target);
        load_strategy(filename, tex.handle_, tex.target_);
        return tex;
    }
    /**
     * Bind the texture for drawing.
     *
     * @param tex The reference to the texture to bind for drawing.
     * @throw std::invalid_argument If <code>tex</code> is an invalid texture.
     */
    inline void submit(const texture& tex)
    {
        if(!tex.handle_)
            throw std::invalid_argument(texture::NO_VALID_TEXTURE);
        glBindTexture(tex.target_, tex.handle_);
    }
} //glpp

#endif //TEXTURE_HPP
