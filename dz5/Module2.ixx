#include <string>

export module Module2;

namespace module2 {
	export std::string getMyName() {
		std::string name = "James";
		return name;
	}
}