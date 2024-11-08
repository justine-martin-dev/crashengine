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

			virtual const ShaderVariableId getVariableId(const std::string& variable_name) = 0;

			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 1>& data) = 0;

			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 2>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 3>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 1, 4>& data) = 0;

			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 1>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 2>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 3>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::INT, 1, 4>& data) = 0;

			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 1>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 2>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 3>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::UINT, 1, 4>& data) = 0;

			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 2>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 3>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 4>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 3>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 2>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 2, 4>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 2>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 3, 4>& data) = 0;
			virtual void updateVariable(const ShaderVariableId variable_id, const Data<DataType::FLOAT, 4, 3>& data) = 0;

			template<DataType type, std::size_t dim1, std::size_t dim2>
			void updateVariable(const ShaderVariableId variable_id, const Data<type, dim1, dim2>& data) { 
				log::error("Unknown way to update the requested variable."); 
			}

			virtual void bind() = 0;
			virtual void unbind() = 0;

	};
}
