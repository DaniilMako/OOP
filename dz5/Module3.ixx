#include <string>

export module Module3;

namespace module3 {
	export std::string getMyName() {
		std::string name = "Simon";
		return name;
	}
}