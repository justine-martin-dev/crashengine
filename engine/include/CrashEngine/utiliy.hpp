#pragma once

#include <cstddef>
#include <utility>

namespace crashengine {

	enum DataType {
		BYTE, DOUBLE, FLOAT, INT, SHORT, UBYTE, UINT, USHORT
	};

	template<DataType type, std::size_t dim1, std::size_t dim2>
	struct Data {

		std::pair<std::size_t, std::size_t> layout = std::pair(dim1, dim2);
		std::size_t count;
		DataType dataType = type;
		void* data;

	};

}