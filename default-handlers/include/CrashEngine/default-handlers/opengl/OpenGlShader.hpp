#pragma once

#include "CrashEngine/logger.hpp"
#include "CrashEngine/Shader.hpp"
#include "CrashEngine/Data.hpp"

#include "glad/gl.h"


namespace crashengine {

	class OpenGlShader : public Shader {

		protected:

			GLuint id;

			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 1>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 2>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 3>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 4>& data) override;

			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 1>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 2>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 3>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 4>& data) override;

			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 1>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 2>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 3>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 4>& data) override;

			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 2>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 3>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 4>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 3>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 2>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 4>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 2>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 4>& data) override;
			void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 3>& data) override;

		public:

			OpenGlShader();
			~OpenGlShader();

			const ShaderVariableId getVariableId(const std::string& variable_id) override;

			void bind() override;
			void unbind() override;

			void attachShader(GLuint shaderId);
			void linkProgram();

	};

}
