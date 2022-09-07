#include "MainScene.hpp"

MainScene::MainScene(crashengine::CrashEngine* engine) : crashengine::Scene(engine) {
	std::pair<crashengine::ShaderType, std::string> vertex{crashengine::ShaderType::VERTEX, "shader.vert"};
	std::pair<crashengine::ShaderType, std::string> fragment{crashengine::ShaderType::FRAGMENT, "shader.frag"};
	std::set<std::pair<crashengine::ShaderType, std::string>> shadersToCreate;
	shadersToCreate.insert(vertex);
	shadersToCreate.insert(fragment);

	shader = this->engine->getGraphicsApiHandler()->createShader(shadersToCreate);
	shader->registerVariable("color");
	
	float v[] = {0.0f, 0.0f, 1.0f};
	crashengine::Data<crashengine::DataType::FLOAT, 1, 3> data;
	data.count = 1;
	data.data = v;

	shader->bind();
	shader->updateVariable("color", data);

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
	this->mesh->bind();
	this->mesh->draw();
	this->mesh->unbind();
	this->shader->unbind();
}