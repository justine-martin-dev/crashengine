#include "CrashEngine/default-handlers/opengl/OpenGlMesh.hpp"

namespace crashengine {

    OpenGlMesh::OpenGlMesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex)
        : _ibo(GL_ELEMENT_ARRAY_BUFFER)
        , _positions(GL_ARRAY_BUFFER)
        , _normals(GL_ARRAY_BUFFER)
        , _textureCoordinates(GL_ARRAY_BUFFER)
    {
        glGenVertexArrays(1, &this->_id);

        this->bind();

        this->_ibo.bind();
        this->_ibo.data(verticesIndex);

        this->_positions.bind();
        this->_positions.data(vertices);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
        glEnableVertexAttribArray(0);

        this->_normals.bind();
        this->_normals.data(verticesNormals);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
        glEnableVertexAttribArray(1);

        this->_textureCoordinates.bind();
        this->_textureCoordinates.data(textureCoordinates);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
        glEnableVertexAttribArray(2);

        this->unbind();
    }

    OpenGlMesh::~OpenGlMesh()
    {
        glDeleteVertexArrays(1, &this->_id);
    }

    void OpenGlMesh::bind()
    {
        glBindVertexArray(this->_id);
    }

    void OpenGlMesh::unbind()
    {
        glBindVertexArray(0);
    }

    void OpenGlMesh::draw()
    {
        glDrawElements(GL_TRIANGLES, this->_ibo.size(), GL_UNSIGNED_INT, 0);
    }

}
