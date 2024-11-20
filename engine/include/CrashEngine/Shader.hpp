#pragma once

#include "CrashEngine/logger.hpp"
#include <CrashEngine/Data.hpp>

#include <any>

namespace crashengine {
	typedef std::any ShaderVariableId;

	class Shader {

		protected:


		public:

			virtual ~Shader() = default;

			virtual const ShaderVariableId get_variable_id(const std::string& variableName) = 0;

			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 1>& data) = 0;

			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 2>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 3>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 1, 4>& data) = 0;

			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 1>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 2>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 3>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::INT, 1, 4>& data) = 0;

			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 1>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 2>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 3>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::UINT, 1, 4>& data) = 0;

			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 2>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 3>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 4>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 3>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 2>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 2, 4>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 2>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 3, 4>& data) = 0;
			virtual void update_variable(const ShaderVariableId variableId, const Data<DataType::FLOAT, 4, 3>& data) = 0;

			template<DataType type, std::size_t dim1, std::size_t dim2>
			void update_variable(const ShaderVariableId variableId, const Data<type, dim1, dim2>& data) { 
				log::error("Unknown way to update the requested variable."); 
			}

			virtual void bind() = 0;
			virtual void unbind() = 0;

	};
}
