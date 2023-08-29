#include "MainScene.hpp"

MainScene::MainScene(crashengine::CrashEngine* engine) : 
		crashengine::Scene(engine), 
		entity() {
	std::pair<crashengine::ShaderType, std::string> vertex{crashengine::ShaderType::VERTEX, "shader.vert"};
	std::pair<crashengine::ShaderType, std::string> fragment{crashengine::ShaderType::FRAGMENT, "shader.frag"};
	std::set<std::pair<crashengine::ShaderType, std::string>> shadersToCreate;
	shadersToCreate.insert(vertex);
	shadersToCreate.insert(fragment);

	shader = this->engine->getGraphicsApiHandler()->createShader(shadersToCreate);
	shader->registerVariable("color");
	shader->registerVariable("myAwesomeTexture");
	shader->registerVariable("model");

	shader->bind();

	float v[] = {0.0f, 0.0f, 1.0f};
	crashengine::Data<crashengine::DataType::FLOAT, 1, 3> data;
	data.count = 1;
	data.data = v;

	int value = 0;
	crashengine::Data<crashengine::DataType::INT, 1, 1> data2;
	data2.count = 1;
	data2.data = &value;

	shader->updateVariable("color", data);
	shader->updateVariable("myAwesomeTexture", data2);
	shader->unbind();

	this->texture = engine->getGraphicsApiHandler()->storeTextureIntoMemory("nebu.png");

	std::vector<float> vertices = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	std::vector<float> uv = {
		1.0f, 1.0f, // top right
		1.0f, 0.0f,  // bottom right
		0.0f, 0.0f,  // bottom left
		0.0f, 1.0f   // top left 
	};

	std::vector<unsigned int> indices = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	mesh = this->engine->getGraphicsApiHandler()->storeMeshIntoMemory(vertices, vertices, uv, indices);

	this->entity.translate({0.2f, 0.2f, 0.0f});
}

MainScene::~MainScene() {
	delete shader;
	delete mesh;
}

void MainScene::show() {

}

void MainScene::hide() {

}

void MainScene::resized(int width, int height) {

}

void MainScene::update(float delta) {
}

void MainScene::draw() {
	this->shader->bind();
	this->texture->bind(0);
	this->mesh->bind();
	this->entity.updateMatrix();

	crashengine::Data<crashengine::DataType::FLOAT, 4, 4> data;
	data.count = 1;
	glm::mat4 m = this->entity.getModelMatrix();
	data.data = &m;

	this->shader->updateVariable("model", data);
	this->mesh->draw();
	this->mesh->unbind();
	this->texture->unbind();
	this->shader->unbind();
}