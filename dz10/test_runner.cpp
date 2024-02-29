#include "Test_Runner.h"

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}
TestRunner::~TestRunner() { // ���������� ������ TestRunner, � ������� ����������� fail_count
    if (fail_count > 0) { //��� ��� ��� ��� ������, �����
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1); // ���������� ��������� � ����� �������� 1
    }
}
