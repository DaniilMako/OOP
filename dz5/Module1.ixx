#include <string>

export module Module1;

namespace module1 {
	export std::string getMyName() {
		std::string name = "John";
		return name;
	}
}