#include <string>
#include <iostream>
#include <sstream>
#include <ostream>
using namespace std;
class Rational {
public:
    Rational() = default;
    Rational(int numerator, int denominator) {  //numerator - числитель, denominator - знаменатель
        if (denominator == 0) {
            stringstream ss;
            ss << "Argument must not be zero";
            throw invalid_argument(ss.str());
        }

        num = numerator;
        denom = denominator;
    }

    int Numerator() const { return num; };
    int Denominator() const { return denom; };

    friend Rational operator+(const Rational& a, const Rational& b) {
        return Rational(a.num * b.denom + b.num * a.denom, a.denom * b.denom);
    }
    friend Rational operator*(const Rational& a, const Rational& b) {
        return Rational(a.num * b.num, a.denom * b.denom);
    }
    friend Rational operator/(const Rational& a, const Rational& b) {
        return Rational(a.num * b.denom, a.denom * b.num);
    }
    friend Rational operator-(const Rational& a, const Rational& b) {
        return Rational(a.num * b.denom - b.num * a.denom, a.denom * b.denom);
    }
    friend bool operator==(const Rational& a, const Rational& b) {
        return a.num == b.num && a.denom == b.denom;
    }
    friend ostream& operator<<(ostream& out, const Rational& a) {
        return out << a.num << '/' << a.denom << endl;
    }
    friend istream& operator>>(istream& in, Rational& a) {
        char c = '/';
        return in >> a.num >> c >> a.denom;
    }
private:
    int num, denom;
};


////////////////////////МЭИН
int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    Rational r1, r2;
    char operation;
    try {
        ss >> r1;
        ss.ignore(1);
        ss >> operation;
        ss.ignore(1);
        ss >> r2;
    }
    catch (exception& ex) {
        cout << "Invalid argument" << endl;
        return 1;
    }
    Rational res;
    try {
        switch (operation) {
        case '+': {
            res = r1 + r2;
            break;
        }
        case '-': {
            res = r1 - r2;
            break;
        }
        case '*': {
            res = r1 * r2;
            break;
        }
        case '/': {
            res = r1 / r2;
            break;
        }
        default: {
            cout << "Invalid operation" << endl;
        }
        }
    }
    catch (exception& ex) {
        cout << "Division by zero" << endl;
        return 2;
    }
    cout << res;

    return 0;
}