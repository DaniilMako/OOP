#include <iostream>

import Module1;
import Module2;
import Module3;

using namespace std;

int main() {
	cout << module1::getMyName() << endl;
	cout << module2::getMyName() << endl;
	cout << module3::getMyName() << endl;
	return 0;
}