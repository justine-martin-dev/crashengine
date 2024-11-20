#pragma once

#include <string>

namespace crashengine {

	namespace log {

		void debug(const std::string& msg);
		void info(const std::string& msg);
		void warn(const std::string& msg);
		void compatibility_warning(const std::string& msg);
		void error(const std::string& msg);

	}

}
