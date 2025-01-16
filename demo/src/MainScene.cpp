#include "MainScene.hpp"

MainScene::MainScene(crashengine::CrashEngine* engine)
    : crashengine::Scene(engine)
    , _camera({ 0.0f, 0.0f, -2.0f }, { 0.0f, 3.14f, 0.0f }, 45.0f, 2560.0f / 1440.0f, 0.01f, 100.0f)
    , _entity()
{
    // Create shader
    this->_shader = this->engine->graphics_api_handler()->create_shader("assets/shader.vert", "assets/shader.frag");

    this->_shader_var_color   = this->_shader->get_variable_id("color");
    this->_shader_var_texture = this->_shader->get_variable_id("myAwesomeTexture");
    this->_shader_var_model   = this->_shader->get_variable_id("mvp");

    float v[] = { 0.0f, 0.0f, 1.0f };

    crashengine::Data<crashengine::DataType::FLOAT, 1, 3> color;
    color.count = 1;
    color.data  = v;

    int value = 0;

    crashengine::Data<crashengine::DataType::INT, 1, 1> data2;
    data2.count = 1;
    data2.data  = &value;

    this->_shader->bind();
    this->_shader->update_variable(this->_shader_var_color, color);
    this->_shader->unbind();

    // Create mesh
    std::vector<float> vertices = {
        0.75f, 0.5f, -0.5f,   // top right
        0.75f, -0.5f, -0.5f,  // bottom right
        -0.75f, -0.5f, 0.5f, // bottom left
        -0.75f, 0.5f, 0.5f   // top left
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

    this->_mesh = this->engine->graphics_api_handler()->create_mesh(vertices, vertices, uv, indices);

    // Setting up entity
    /*this->_entity.translate({ 0.2f, 0.2f, 0.0f });*/
    /*this->_entity.proportions(0.5f);*/
    this->_entity.update_matrix();

    // Create texture
    this->_texture = engine->graphics_api_handler()->create_texture("assets/nebu.png");
}

MainScene::~MainScene()
{
    delete this->_shader;
    delete this->_mesh;
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
    this->_shader->bind();
    this->_texture->bind_to_slot(0);
    this->_mesh->bind();

    glm::mat4 mvp = this->_camera.projection_matrix() * this->_camera.view_matrix() * this->_entity.model_matrix();

    crashengine::Data<crashengine::DataType::FLOAT, 4, 4> data;
    data.count = 1;
    data.data  = &mvp;
    this->_shader->update_variable(this->_shader_var_model, data);

    this->_mesh->draw();
}
