#include "CrashEngine/default-handlers/opengl/OpenGlBuffer.hpp"

namespace crashengine {

    template <typename T>
    OpenGlBuffer<T>::OpenGlBuffer(GLenum target)
        : target(target)
        , size(0)
    {
        glGenBuffers(1, &this->id);
    }

    template <typename T>
    OpenGlBuffer<T>::~OpenGlBuffer()
    {
        glDeleteBuffers(1, &this->id);
    }

    template <typename T>
    void OpenGlBuffer<T>::bind()
    {
        glBindBuffer(this->target, this->id);
    }

    template <typename T>
    void OpenGlBuffer<T>::unbind()
    {
        glBindBuffer(this->target, 0);
    }

    template <typename T>
    void OpenGlBuffer<T>::setData(std::vector<T>& data)
    {
        glBufferData(this->target, sizeof(T) * data.size(), data.data(), GL_STATIC_DRAW);
        this->size = data.size();
    }

    template <typename T>
    std::size_t OpenGlBuffer<T>::getSize()
    {
        return this->size;
    }

}
