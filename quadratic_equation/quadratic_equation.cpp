#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, c, x1, x2;
    cin >> a >> b >> c;
    double d = b * b - (4 * a * c);
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Roots: " << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (d == 0) {
        x1 = (b * -1 / (2 * a));
        x2 = (b * -1 / (2 * a));
        cout << "Roots: " << endl;
        cout << "x = " << x1 << endl;
    }
    else {
        cout << "Roots: no roots:";
    }
	return 0;
}