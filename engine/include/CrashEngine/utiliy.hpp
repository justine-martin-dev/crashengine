#pragma once

#include <string>
#include <cstddef>
#include <utility>

namespace crashengine {

	enum DataType {
		BYTE, DOUBLE, FLOAT, INT, SHORT, UBYTE, UINT, USHORT, ERROR
	};

	template<DataType type, std::size_t dim1, std::size_t dim2>
	struct Data {

		std::pair<std::size_t, std::size_t> layout = std::pair(dim1, dim2);
		std::size_t count;
		DataType dataType = type;
		void* data;

	};

	template<typename T>
	DataType getDataType(const T &data);

	template<> DataType getDataType(const          char   &data);
	template<> DataType getDataType(const          double &data);
	template<> DataType getDataType(const          float  &data);
	template<> DataType getDataType(const          int    &data);
	template<> DataType getDataType(const          short  &data);
	template<> DataType getDataType(const unsigned char   &data);
	template<> DataType getDataType(const unsigned int    &data);
	template<> DataType getDataType(const unsigned short  &data);

	std::string getDataTypeName(const DataType &dtype);
}
