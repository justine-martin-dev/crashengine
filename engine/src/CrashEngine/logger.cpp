#include "CrashEngine/logger.hpp"

namespace crashengine {

	namespace log {

		void debug(const std::string& msg) {
			std::cout << "[DEBUG] " << msg << std::endl;
		}

		void info(const std::string& msg) {
			std::cout << "[INFO] " << msg << std::endl;
		}

		void warn(const std::string& msg) {
			std::cout << "[WARN] " << msg << std::endl;
		}

		void compatibilityWarning(const std::string& msg) {
			std::cout << "[COMPATIBILITY WARNING] " << msg << std::endl;
		}

		void error(const std::string& msg) {
			std::cerr << "[ERROR] " << msg << std::endl;
		}

	}
	
}