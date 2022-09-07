#pragma once

#include "CrashEngine/Shader.hpp"
#include "CrashEngine/utiliy.hpp"

#include "glad/gl.h"

#include <cstdarg>
#include <cstdint>

namespace crashengine {

	class OpenGlShader  : public Shader {

		protected:

			GLuint id;

			void updateVec1fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 1>& data) override;
			void updateVec2fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 2>& data) override;
			void updateVec3fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 3>& data) override;
			void updateVec4fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 4>& data) override;

			void updateVec1iVar(const std::string& variable, const Data<DataType::INT, 1, 1>& data) override;
			void updateVec2iVar(const std::string& variable, const Data<DataType::INT, 1, 2>& data) override;
			void updateVec3iVar(const std::string& variable, const Data<DataType::INT, 1, 3>& data) override;
			void updateVec4iVar(const std::string& variable, const Data<DataType::INT, 1, 4>& data) override;

			void updateVec1uiVar(const std::string& variable, const Data<DataType::UINT, 1, 1>& data) override;
			void updateVec2uiVar(const std::string& variable, const Data<DataType::UINT, 1, 2>& data) override;
			void updateVec3uiVar(const std::string& variable, const Data<DataType::UINT, 1, 3>& data) override;
			void updateVec4uiVar(const std::string& variable, const Data<DataType::UINT, 1, 4>& data) override;

			void updateMatrix2Var(const std::string& variable, const Data<DataType::FLOAT, 2, 2>& data) override;
			void updateMatrix3Var(const std::string& variable, const Data<DataType::FLOAT, 3, 3>& data) override;
			void updateMatrix4Var(const std::string& variable, const Data<DataType::FLOAT, 4, 4>& data) override;
			void updateMatrix2x3Var(const std::string& variable, const Data<DataType::FLOAT, 2, 3>& data) override;
			void updateMatrix3x2Var(const std::string& variable, const Data<DataType::FLOAT, 3, 2>& data) override;
			void updateMatrix2x4Var(const std::string& variable, const Data<DataType::FLOAT, 2, 4>& data) override;
			void updateMatrix4x2Var(const std::string& variable, const Data<DataType::FLOAT, 4, 2>& data) override;
			void updateMatrix3x4Var(const std::string& variable, const Data<DataType::FLOAT, 3, 4>& data) override;
			void updateMatrix4x3Var(const std::string& variable, const Data<DataType::FLOAT, 4, 3>& data) override;

		public:

			OpenGlShader();
			~OpenGlShader();

			void registerVariables(const std::string& variables...) override;
			void registerVariable(const std::string& variable) override;

			void bind() override;
			void unbind() override;

			void attachShader(GLuint shaderId);
			void linkProgram();

	};

}