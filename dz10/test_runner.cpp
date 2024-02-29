#include "Test_Runner.h"

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}
TestRunner::~TestRunner() { // деструктор класса TestRunner, в котором анализируем fail_count
    if (fail_count > 0) { //это как раз тот момент, когда
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1); // завершение программы с кодом возврата 1
    }
}
