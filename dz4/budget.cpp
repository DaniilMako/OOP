//�� 4
//���������� ������� ������� ������� �������. ��� ���������� ������������ ������� ��������� �����:
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

const int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // ���������� ���� � ������ ������

auto numberMonthDays(int date) {  // ���������� ���� �� ���������� ������
    int sum = 0;
    for (int i = 0; i < date; i++)
        sum += month_days[i];
    return sum;
}

auto numberDaysYear(int date) {  // ���������� ���� �� ���������� ����
    int sum = 0;
    for (int i = 2000; i <= date; i++) {
        if (i % 4 == 0 || (i % 100 == 0 && i % 400 == 0))
            sum += 366;
        else
            sum += 365;
    }
    return sum;
}

map<int, double> wallet;  // ��������� ��� �������� ���������� � ��������

auto paymentMemorisation(tuple<int, int> days, int value) {  // ��������� ���������� � �������
    double payment = value / (get<1>(days) + 1 - get<0>(days));  // ��������� ��������� �����: �������� ����� �� ������� ����� ������
    for (int i = get<0>(days); i <= get<1>(days); i++) {
        if (wallet.count(i) > 0)
            wallet[i] += payment;
        else
            wallet[i] = payment;
    }
}

auto numberDaysInDate(tuple<int, int, int> date1, tuple<int, int, int> date2) {  // ���������� ���� � ����
    int c1 = numberDaysYear(get<0>(date1)) + numberMonthDays(get<1>(date1)) + get<2>(date1);
    int c2 = numberDaysYear(get<0>(date2)) + numberMonthDays(get<1>(date2)) + get<2>(date2);
    tuple<int, int> days(c1, c2);
    return days;
}

auto Earn(tuple<int, int, int> date1, tuple<int, int, int> date2, int value) {  // ���������� ���������� � ������������ ������� � ��������� ������
    tuple<int, int> days = numberDaysInDate(date1, date2);
    paymentMemorisation(days, value);  // ��������� ���� � ������
}

auto ComputeIncome(tuple<int, int, int> date1, tuple<int, int, int> date2) {  // ����� ������������ ����� � ��������� ������
    tuple<int, int> days = numberDaysInDate(date1, date2);  // ��������� ���������� ���� � �����
    double payment = 0;
    for (int i = get<0>(days); i <= get<1>(days); i++)  // ��������� ���������� �����
        payment += wallet[i];
    return payment;
}

auto parseDate(string date_str) {  // ������ ���� �� ������ (���, �����, ����)
    int year, month, day;
    stringstream ss(date_str);
    ss >> year;
    ss.ignore(1);
    ss >> month;
    ss.ignore(1);
    ss >> day;
    tuple<int, int, int> date(year, month, day);
    return date;
}

int main() {
    string str;
    getline(cin, str);
    stringstream s(str);
    int Q;  // ���������� ��������
    s >> Q;
    s.ignore(1);
    for (auto i = 0; i < Q; i++) {
        int value;
        string temp, date1, date2, command;
        getline(cin, temp);
        stringstream ss(temp);
        ss >> command >> date1 >> date2;
        auto d1 = parseDate(date1);  // ����� ������ ��������� ���� �� ������
        auto d2 = parseDate(date2);
        if (command == "Earn") {
            ss >> value;
            Earn(d1, d2, value);
        }
        else
            cout << ComputeIncome(d1, d2) << endl;
    }
    return 0;
}