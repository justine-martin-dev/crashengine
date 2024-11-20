#include "CrashEngine/default-handlers/opengl/OpenGlBuffer.hpp"

namespace crashengine {

    template <typename T>
    OpenGlBuffer<T>::OpenGlBuffer(GLenum target)
        : _target(target)
        , _size(0)
    {
        glGenBuffers(1, &this->_id);
    }

    template <typename T>
    OpenGlBuffer<T>::~OpenGlBuffer()
    {
        glDeleteBuffers(1, &this->_id);
    }

    template <typename T>
    void OpenGlBuffer<T>::bind()
    {
        glBindBuffer(this->_target, this->_id);
    }

    template <typename T>
    void OpenGlBuffer<T>::unbind()
    {
        glBindBuffer(this->_target, 0);
    }

    template <typename T>
    void OpenGlBuffer<T>::data(std::vector<T>& data)
    {
        glBufferData(this->_target, sizeof(T) * data.size(), data.data(), GL_STATIC_DRAW);
        this->_size = data.size();
    }

    template <typename T>
    std::size_t OpenGlBuffer<T>::size()
    {
        return this->_size;
    }

}
