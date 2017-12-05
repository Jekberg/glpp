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
     * A texture object contains both the texture_mode and the id which
     * identifies the texture. A texture may be moved but not copied.
     *
     * @brief Encapsulation of textures which are used by OpenGL.
     */
    class texture final
    {
        //======================================================================
        //Friends.
    private:
        template<typename F>
        friend texture load_texture(
                const std::string&,
                texture_mode,
                F load_strategy)
        noexcept(noexcept(load_strategy("", 0, 0)));
        friend void submit(const texture&);
        //======================================================================
        //Static members.
        /**
         * @brief The size of how many textures to generate.
         */
        static const GLuint SIZE;
        /**
         * @brief The numeric value representing the an invalid texture.
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
         * @brief The GLenum representing the texture mode.
         */
        GLenum target_;
        /**
         * @brief The numeric value which represents this texture.
         */
        GLuint handle_;
        //======================================================================
        //Constructors.
    public:
        /**
         * The texture constructed will be GL_TEXTURE_2D and invalid.
         *
         * @brief The default constructor.
         */
        constexpr texture() noexcept:
                target_(GL_TEXTURE_2D),
                handle_(NO_TEXTURE)
        {
        }
        /**
         * Constructing a texture will generate a texture.
         *
         * @brief Create a texture with a specific texture_mode.
         * @param target The texture_mode which will be used in this texture.
         * @throw error If generating a texture fails.
         */
        inline texture(texture_mode target):
                target_(static_cast<GLenum>(target))
        {
            glGenTextures(SIZE, &handle_);
            get_error();
        }
        /**
         * Deleted.
         */
        texture(const texture&) = delete;
        /**
         * Move a texture into a newly constructed texture by copying the
         * texture_mode and texture id of the original texture, then setting
         * the original texture to contain no list.
         *
         * @brief Move constructor.
         * @param The rvalue reference to the texture to be moved
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
         * Destroy the texture and free the resource.
         *
         * @brief Delete the texture.
         */
        ~texture() noexcept;
        //======================================================================
        //Member functions
    private:
        /**
         * A texture will only be released if a texture id is present.
         *
         * @brief Release the texture contained in this.
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
         * Before moving the original texture into this, first the resources in
         * this texture will be released, then the texture_mode and id from the
         * original texture will be copied, then the texture id of the original
         * will be set to contain no texture.
         *
         * @brief Move assignment.
         * @param orig The rvalue reference to the texture to move into this
         *          texture.
         */
        texture& operator= (texture&& orig) noexcept;
    };
    /**
     * A callback must be provided to help the set up of the texture.
     *
     * <p>
     * If the <code>load_strategy</code> may throw, then this function may also
     * throw; however, if <code>load_strategy</code> may not throw, then neither
     * will this function.
     * </p>
     *
     * @brief Load a texture into a texture object.
     * @param filename The reference to a string representing the name of the
     *          file to be loaded.
     * @param target The type of texture to be loaded.
     * @param A function which defines the strategy of loading the textures.
     * @return A texture object representing the loaded texture.
     */
    template<typename F>
    texture load_texture(
                         const std::string& filename,
                         texture_mode target,
                         F load_strategy)
                         noexcept(noexcept(load_strategy("", 0, 0)))
    {
        texture tex(target);
        load_strategy(filename, tex.handle_, tex.target_);
        return tex;
    }
    /**
     * @brief Bind the texture for drawing.
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
