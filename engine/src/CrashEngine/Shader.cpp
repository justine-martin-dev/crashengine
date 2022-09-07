#include "CrashEngine/Shader.hpp"

namespace crashengine {
	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 1, 1>& data) { 
		this->updateVec1fVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 1, 2>& data) { 
		this->updateVec2fVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 1, 3>& data) { 
		this->updateVec3fVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 1, 4>& data) { 
		this->updateVec4fVar(variable, data); 
	}
	
	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::INT, 1, 1>& data) { 
		this->updateVec1iVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::INT, 1, 2>& data) { 
		this->updateVec2iVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::INT, 1, 3>& data) { 
		this->updateVec3iVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::INT, 1, 4>& data) { 
		this->updateVec4iVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::UINT, 1, 1>& data) { 
		this->updateVec1uiVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::UINT, 1, 2>& data) { 
		this->updateVec2uiVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::UINT, 1, 3>& data) { 
		this->updateVec3uiVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::UINT, 1, 4>& data) { 
		this->updateVec4uiVar(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 2, 2>& data) { 
		this->updateMatrix2Var(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 3, 3>& data) { 
		this->updateMatrix3Var(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 4, 4>& data) { 
		this->updateMatrix4Var(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 2, 3>& data) { 
		this->updateMatrix2x3Var(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 3, 2>& data) { 
		this->updateMatrix3x2Var(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 2, 4>& data) { 
		this->updateMatrix2x4Var(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 4, 2>& data) { 
		this->updateMatrix4x2Var(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 3, 4>& data) { 
		this->updateMatrix3x4Var(variable, data); 
	}

	template<> 
	void Shader::updateVariable(const std::string& variable, const Data<DataType::FLOAT, 4, 3>& data) { 
		this->updateMatrix4x3Var(variable, data); 
	}

}