#include "MainScene.hpp"

MainScene::MainScene(crashengine::CrashEngine* engine)
    : crashengine::Scene(engine)
    , entity()
{
    // Create shader
    shader = this->engine->getGraphicsApiHandler()->createShader("assets/shader.vert", "assets/shader.frag");

    this->shader_var_color   = shader->getVariableId("color");
    this->shader_var_texture = shader->getVariableId("myAwesomeTexture");
    this->shader_var_model   = shader->getVariableId("model");

    float                                                 v[] = { 0.0f, 0.0f, 1.0f };
    crashengine::Data<crashengine::DataType::FLOAT, 1, 3> color;
    color.count = 1;
    color.data  = v;

    int                                                 value = 0;
    crashengine::Data<crashengine::DataType::INT, 1, 1> data2;
    data2.count = 1;
    data2.data  = &value;

    shader->bind();
    shader->updateVariable(shader_var_color, color);
    shader->unbind();

    // Create mesh
    std::vector<float> vertices = {
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };

    std::vector<float> uv = {
        1.0f, 1.0f, // top right
        1.0f, 0.0f, // bottom right
        0.0f, 0.0f, // bottom left
        0.0f, 1.0f  // top left
    };

    std::vector<unsigned int> indices = {
        // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    mesh = this->engine->getGraphicsApiHandler()->createMesh(vertices, vertices, uv, indices);

    // Setting up entity
    this->entity.translate({ 0.2f, 0.2f, 0.0f });
    this->entity.setScale(0.5f);
    this->entity.updateMatrix();

    // Create texture
    this->texture = engine->getGraphicsApiHandler()->createTexture("assets/nebu.png");
}

MainScene::~MainScene()
{
    delete shader;
    delete mesh;
}

void MainScene::show()
{
}

void MainScene::hide()
{
}

void MainScene::resized(int width, int height)
{
}

void MainScene::update(float delta)
{
}

void MainScene::draw()
{
    this->shader->bind();
    this->texture->bindToSlot(0);
    this->mesh->bind();

    glm::mat4                                             m = this->entity.getModelMatrix();
    crashengine::Data<crashengine::DataType::FLOAT, 4, 4> data;
    data.count = 1;
    data.data  = &m;
    this->shader->updateVariable(this->shader_var_model, data);

    this->mesh->draw();
}
