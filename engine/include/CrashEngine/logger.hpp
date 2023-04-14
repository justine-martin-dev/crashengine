#pragma once

#include <iostream>
#include <string>

namespace crashengine {

	namespace log {

		void debug(const std::string& msg);
		void info(const std::string& msg);
		void warn(const std::string& msg);
		void compatibilityWarning(const std::string& msg);
		void error(const std::string& msg);

	}

}