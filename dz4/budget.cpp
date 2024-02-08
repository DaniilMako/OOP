//дз 4
//–еализуйте систему ведени€ личного бюджета. ¬ам необходимо обрабатывать запросы следующих типов:
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

const int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // количество дней в каждом мес€це

auto numberMonthDays(int date) {  // количество дней до указанного мес€ца
    int sum = 0;
    for (int i = 0; i < date; i++)
        sum += month_days[i];
    return sum;
}

auto numberDaysYear(int date) {  // количество дней до указанного года
    int sum = 0;
    for (int i = 2000; i <= date; i++) {
        if (i % 4 == 0 || (i % 100 == 0 && i % 400 == 0))
            sum += 366;
        else
            sum += 365;
    }
    return sum;
}

map<int, double> wallet;  // контейнер дл€ хранени€ информации о платежах

auto paymentMemorisation(tuple<int, int> days, int value) {  // сохран€ем информацию о платеже
    double payment = value / (get<1>(days) + 1 - get<0>(days));  // вычисл€ем ежедневый доход: значение делим на разницу между датами
    for (int i = get<0>(days); i <= get<1>(days); i++) {
        if (wallet.count(i) > 0)
            wallet[i] += payment;
        else
            wallet[i] = payment;
    }
}

auto numberDaysInDate(tuple<int, int, int> date1, tuple<int, int, int> date2) {  // количество дней в дате
    int c1 = numberDaysYear(get<0>(date1)) + numberMonthDays(get<1>(date1)) + get<2>(date1);
    int c2 = numberDaysYear(get<0>(date2)) + numberMonthDays(get<1>(date2)) + get<2>(date2);
    tuple<int, int> days(c1, c2);
    return days;
}

auto Earn(tuple<int, int, int> date1, tuple<int, int, int> date2, int value) {  // записываем информацию о заработанных деньгах в указанный период
    tuple<int, int> days = numberDaysInDate(date1, date2);
    paymentMemorisation(days, value);  // сохран€ем инфу о доходе
}

auto ComputeIncome(tuple<int, int, int> date1, tuple<int, int, int> date2) {  // вывод заработанных денег в указанный период
    tuple<int, int> days = numberDaysInDate(date1, date2);  // вычисл€ем количество дней в датах
    double payment = 0;
    for (int i = get<0>(days); i <= get<1>(days); i++)  // суммируем ежедневный доход
        payment += wallet[i];
    return payment;
}

auto parseDate(string date_str) {  // парсим дату на кортеж (год, мес€ц, день)
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
    int Q;  // количество запросов
    s >> Q;
    s.ignore(1);
    for (auto i = 0; i < Q; i++) {
        int value;
        string temp, date1, date2, command;
        getline(cin, temp);
        stringstream ss(temp);
        ss >> command >> date1 >> date2;
        auto d1 = parseDate(date1);  // сразу парсим строковые даты на кортеж
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