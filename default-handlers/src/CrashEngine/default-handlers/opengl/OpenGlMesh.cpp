#include "CrashEngine/default-handlers/opengl/OpenGlMesh.hpp"

namespace crashengine {

    OpenGlMesh::OpenGlMesh(std::vector<float>& vertices, std::vector<float>& verticesNormals, std::vector<float>& textureCoordinates, std::vector<unsigned int>& verticesIndex)
        : ibo(GL_ELEMENT_ARRAY_BUFFER)
        , positions(GL_ARRAY_BUFFER)
        , normals(GL_ARRAY_BUFFER)
        , textureCoordinates(GL_ARRAY_BUFFER)
    {
        glGenVertexArrays(1, &this->id);

        this->bind();

        this->ibo.bind();
        this->ibo.setData(verticesIndex);

        this->positions.bind();
        this->positions.setData(vertices);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
        glEnableVertexAttribArray(0);

        this->normals.bind();
        this->normals.setData(verticesNormals);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
        glEnableVertexAttribArray(1);

        this->textureCoordinates.bind();
        this->textureCoordinates.setData(textureCoordinates);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
        glEnableVertexAttribArray(2);

        this->unbind();
    }

    OpenGlMesh::~OpenGlMesh()
    {
        glDeleteVertexArrays(1, &this->id);
    }

    void OpenGlMesh::bind()
    {
        glBindVertexArray(this->id);
    }

    void OpenGlMesh::unbind()
    {
        glBindVertexArray(0);
    }

    void OpenGlMesh::draw()
    {
        glDrawElements(GL_TRIANGLES, this->ibo.getSize(), GL_UNSIGNED_INT, 0);
    }

}
