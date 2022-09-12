#include "CrashEngine/utiliy.hpp"

namespace crashengine {

    template<typename T> DataType getDataType(const T &data) {
        return DataType::ERROR;
    }

    template<> DataType getDataType(const char &data) {
        return DataType::BYTE;
    }

	template<> DataType getDataType<double>(const double &data) {
        return DataType::DOUBLE;
    }

	template<> DataType getDataType<float>(const float &data) {
        return DataType::FLOAT;
    }
	
    template<> DataType getDataType<int>(const int &data) {
        return DataType::INT;
    }

	template<> DataType getDataType<short>(const short &data) {
        return DataType::SHORT;
    }

	template<> DataType getDataType<unsigned char>(const unsigned char &data) {
        return DataType::UBYTE;
    }

	template<> DataType getDataType<unsigned int>(const unsigned int &data) {
        return DataType::UINT;
    }

	template<> DataType getDataType<unsigned short>(const unsigned short &data) {
        return DataType::USHORT;
    }
    
    std::string getDataTypeName(const DataType &dtype) {
        switch (dtype) {
            case DataType::ERROR:  return "error_type";
            case DataType::BYTE:   return "byte";
            case DataType::DOUBLE: return "double";
            case DataType::FLOAT:  return "float";
            case DataType::INT:    return "int";
            case DataType::SHORT:  return "short";
            case DataType::UBYTE:  return "ubyte";
            case DataType::UINT:   return "uint";
            case DataType::USHORT: return "ushort";
            default: return "ERROR_no_type";
        }
    }
}
