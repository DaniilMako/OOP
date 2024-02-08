#pragma once

#include <string>
#include <set>
#include <map>
#include <iostream>
#include <sstream> 

#include <sstream>
using namespace std;

#define ASSERT_EQUAL(x, y)  {                                           \
    ostringstream os;                                                   \
    os << #x << " != " << #y << ", " <<__FILE__ << ":" << __LINE__;     \
    AssertEqual(x, y, os.str());                                        \
}

#define ASSERT(x)  {                                                    \
    ostringstream os;                                                   \
    os << #x << " is false, " <<__FILE__ << ":" << __LINE__;            \
    AssertEqual(x, os.str());                                           \
}
#define RUN_TEST(tr, func) tr.RunTest(func, #func)

template <class T> // учимся выводить в поток set
ostream& operator << (ostream& os, const set <T>& s);
template <class K, class V> // учимся выводить в поток map
ostream& operator << (ostream& os, const map <K, V>& m);
template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint);
void Assert(bool b, const string& hint);
class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name);
    ~TestRunner();
private:
    int fail_count = 0; // счётчик числа упавших тестов
};


template <class T> // учимся выводить в поток set
ostream& operator << (ostream& os, const set <T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}
template <class K, class V> // учимся выводить в поток map
ostream& operator << (ostream& os, const map <K, V>& m) {
    os << "{";
    bool first = true; // грамотная расстановка запятых
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    // значения двух разных типов для удобства
    if (t != u) { // если значения не равны, то мы даём знать, что этот assert не сработал
        ostringstream os;
        os << "Assertion failed: " << t << "!=" << u << "Hint: " << hint;;
        throw runtime_error(os.str()); // бросим исключение с сообщением со значениями t и u
    }
}



template <class TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name) {
    try { // RunTest стал шаблонным методом класса
        func();
        cerr << test_name << " OK" << endl;
    }
    catch (runtime_error& e) {
        ++fail_count; // увеличиваем счётчик упавших тестов
        cerr << test_name << " fail: " << e.what() << endl;
    }
}

