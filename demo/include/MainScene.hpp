#pragma once

#include "CrashEngine/CrashEngine.hpp"
#include "CrashEngine/Mesh.hpp"
#include "CrashEngine/Scene.hpp"
#include "CrashEngine/Shader.hpp"

class MainScene : public crashengine::Scene {

	protected:

		crashengine::Mesh* mesh;
		crashengine::Shader* shader;

	public:

		MainScene(crashengine::CrashEngine* engine);
		~MainScene();

		void show() override;
		void hide() override;

		void resized(int width, int height) override;

		void update(float delta) override;
		void draw() override;

};