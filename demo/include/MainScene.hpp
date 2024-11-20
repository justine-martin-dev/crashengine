#pragma once

#include "CrashEngine/CrashEngine.hpp"
#include "CrashEngine/Entity.hpp"
#include "CrashEngine/Mesh.hpp"
#include "CrashEngine/Scene.hpp"
#include "CrashEngine/Shader.hpp"
#include "CrashEngine/Texture.hpp"

class MainScene : public crashengine::Scene {

    protected:
        crashengine::ShaderVariableId _shader_var_color;
        crashengine::ShaderVariableId _shader_var_texture;
        crashengine::ShaderVariableId _shader_var_model;

        crashengine::Entity _entity;

        crashengine::Mesh*    _mesh;
        crashengine::Shader*  _shader;
        crashengine::Texture* _texture;

    public:
        MainScene(crashengine::CrashEngine* engine);
        ~MainScene();

        void show() override;
        void hide() override;

        void resized(int width, int height) override;

        void update(float delta) override;
        void draw() override;
};
