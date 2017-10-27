#include "../gl_list.h"

namespace glpp
{
    /**
     * The int value which represents the absence of a list.
     */
    GLuint gl_list::NO_LIST = 0;
    /**
     * The size of the list group.
     */
    GLuint gl_list::SIZE = 1;
    /**
     * Construct a gl_list which does not have any list.
     */
    gl_list::gl_list()
        noexcept:
        handle_(NO_LIST)
    {
        //No implementation.
    } //gl_list()
    /**
     * 
     * 
     * @param mode The mode, should be GL_COMPILe or GL_COMPILE_AND_EXECUTE.
     * @param callback The procedure of calls inside the list.
     */
    gl_list::gl_list(
            const GLenum mode,
            const std::function<void ()> callback)
            throw(GLenum):
            handle_(glGenLists(SIZE))
    {
        //Check errors after generation.
        if(!handle_)
            throw glGetError();
        glNewList(handle_, mode);
        {
            //call the procedure.
            callback();
        }
        glEndList();
        //Check errors post list creation.
        GLenum error = glGetError();
        if(error)
            throw error;
    } //gl_list(const GLenum, std::function<void ()>)
    /**
     * Move constructor.
     * 
     * Move the list of a temporary gl_list into this gl_list by taking the
     * list of the temporary gl_list.
     * 
     * @param orig The original list to be moved into this list.
     */
    gl_list::gl_list(gl_list && orig)
            noexcept:
            handle_(orig.handle_)
    {
        orig.handle_ = NO_LIST;
    } //gl_list(const gl_list &)
    /**
     * Destroy this gl_list by releasing the list which this gl_list contains.
     */
    gl_list::~gl_list()
            noexcept
    {
        release();
    } //gl_list()
    /**
     * Move assignment.
     * 
     * Move a temporary gl_list into this list by releasing the current list,
     * then aquire the list of the temporary list object, and then setting the
     * temporary to NO_LIST.
     * 
     * @param orig The temporary gl_list object to be moved into this object.
     * @return The reference to this object after the move.
     */
    gl_list & gl_list::operator = (gl_list && orig)
            noexcept
    {
        release();
        handle_ = orig.handle_;
        orig.handle_ = NO_LIST;
        return *this;
    }
    /**
     * If the list of this gl_list is 0, then do nothing, otherwise, destroy the
     * list.
     */
    void gl_list::release()
            noexcept
    {
        if(!handle_)
            glDeleteLists(handle_, SIZE);
    }
    /**
     * 
     * @param callback
     * @return 
     */
    gl_list compile_list(const std::function<void ()> callback)
            throw(GLenum)
    {
        return gl_list(GL_COMPILE, callback);
    }
    /**
     * 
     * @param callback
     * @return 
     */
    gl_list compile_and_execute_list(const std::function<void ()> callback)
    throw(GLenum)
    {
        return gl_list(GL_COMPILE_AND_EXECUTE, callback);
    }
    /**
     * 
     * 
     * @param _list The list to be called.
     */
    void submit(const gl_list & _list)
            noexcept
    {
        glCallList(_list.handle_);
    } //submit(const gl_list &) noexcept
} //glpp