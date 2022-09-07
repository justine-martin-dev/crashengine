#pragma once

#include <CrashEngine/utiliy.hpp>

#include <map>
#include <string>

#include <iostream>

namespace crashengine {

	class Shader {

		protected:

			std::map<std::string, unsigned int> variableLocations;

			virtual void updateVec1fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 1>& data) = 0;
			virtual void updateVec2fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 2>& data) = 0;
			virtual void updateVec3fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 3>& data) = 0;
			virtual void updateVec4fVar(const std::string& variable, const Data<DataType::FLOAT, 1, 4>& data) = 0;

			virtual void updateVec1iVar(const std::string& variable, const Data<DataType::INT, 1, 1>& data) = 0;
			virtual void updateVec2iVar(const std::string& variable, const Data<DataType::INT, 1, 2>& data) = 0;
			virtual void updateVec3iVar(const std::string& variable, const Data<DataType::INT, 1, 3>& data) = 0;
			virtual void updateVec4iVar(const std::string& variable, const Data<DataType::INT, 1, 4>& data) = 0;

			virtual void updateVec1uiVar(const std::string& variable, const Data<DataType::UINT, 1, 1>& data) = 0;
			virtual void updateVec2uiVar(const std::string& variable, const Data<DataType::UINT, 1, 2>& data) = 0;
			virtual void updateVec3uiVar(const std::string& variable, const Data<DataType::UINT, 1, 3>& data) = 0;
			virtual void updateVec4uiVar(const std::string& variable, const Data<DataType::UINT, 1, 4>& data) = 0;

			virtual void updateMatrix2Var(const std::string& variable, const Data<DataType::FLOAT, 2, 2>& data) = 0;
			virtual void updateMatrix3Var(const std::string& variable, const Data<DataType::FLOAT, 3, 3>& data) = 0;
			virtual void updateMatrix4Var(const std::string& variable, const Data<DataType::FLOAT, 4, 4>& data) = 0;
			virtual void updateMatrix2x3Var(const std::string& variable, const Data<DataType::FLOAT, 2, 3>& data) = 0;
			virtual void updateMatrix3x2Var(const std::string& variable, const Data<DataType::FLOAT, 3, 2>& data) = 0;
			virtual void updateMatrix2x4Var(const std::string& variable, const Data<DataType::FLOAT, 2, 4>& data) = 0;
			virtual void updateMatrix4x2Var(const std::string& variable, const Data<DataType::FLOAT, 4, 2>& data) = 0;
			virtual void updateMatrix3x4Var(const std::string& variable, const Data<DataType::FLOAT, 3, 4>& data) = 0;
			virtual void updateMatrix4x3Var(const std::string& variable, const Data<DataType::FLOAT, 4, 3>& data) = 0;

		public:

			virtual void registerVariables(const std::string& variables...) = 0;
			virtual void registerVariable(const std::string& variable) = 0;

			template<DataType type, std::size_t dim1, std::size_t dim2>
			void updateVariable(const std::string& variable, const Data<type, dim1, dim2>& data) { std::cout << "Data type not supported" << std::endl; }

			virtual void bind() = 0;
			virtual void unbind() = 0;

	};
	
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 1, 1>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 1, 2>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 1, 3>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 1, 4>& data);

	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::INT, 1, 1>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::INT, 1, 2>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::INT, 1, 3>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::INT, 1, 4>& data);

	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::UINT, 1, 1>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::UINT, 1, 2>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::UINT, 1, 3>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::UINT, 1, 4>& data);

	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 2, 2>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 3, 3>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 4, 4>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 2, 3>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 3, 2>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 2, 4>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 4, 2>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 3, 4>& data);
	template<> void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 4, 3>& data);

}