#pragma once

#include "CrashEngine/logger.hpp"
#include "CrashEngine/Shader.hpp"
#include "CrashEngine/Data.hpp"

#include "glad/gl.h"

#include <filesystem>

namespace crashengine {

	class OpenGlShader : public Shader {

		protected:

			GLuint _id;
			GLuint _create_shader_stage(const std::filesystem::path& path, const GLenum stageType);

		public:

			OpenGlShader(const std::filesystem::path& vertexShaderPath, const std::filesystem::path& fragmentShaderPath);
			~OpenGlShader();

			const ShaderVariableId get_variable_id(const std::string& variableId) override;

			void bind() override;
			void unbind() override;

			void attach_shader(GLuint shaderId);
			void link_program();

			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 1>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 2>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 3>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 4>& data) override;

			void update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 1>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 2>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 3>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 4>& data) override;

			void update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 1>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 2>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 3>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 4>& data) override;

			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 2>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 3>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 4>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 3>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 2>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 4>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 2>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 4>& data) override;
			void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 3>& data) override;
	};

}
