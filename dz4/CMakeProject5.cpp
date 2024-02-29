#include <iostream>
#include <string>
#include <ctime>
#include <numeric>
#include <fstream>
using namespace std;
double arr[36525] = { 0 };
struct tm a = { 0, 0, 12, 0, 0, 100 };


double take_salary(int y1, int m1, int d1, int y2, int m2, int d2) {
	struct tm r1 = { 0, 0, 12, d1, m1, y1 - 1900 };
	struct tm r2 = { 0, 0, 12, d2, m2, y2 - 1900 };
	time_t aa = mktime(&a);
	time_t x3 = mktime(&r1);
	time_t y3 = mktime(&r2);
	double diff = difftime(y3, x3) / (60 * 60 * 24);
	double start = difftime(x3, aa) / (60 * 60 * 24);
	double res = 0;
	double t = accumulate(&arr[(int)start], &arr[(int)diff + (int)start], res);
	return t;
}

void give_salary(int s, int y1, int m1, int d1, int y2, int m2, int d2) {
	struct tm r1 = { 0, 0, 12, d1, m1, y1 - 1900 };
	struct tm r2 = { 0, 0, 12, d2, m2, y2 - 1900 };
	time_t x1 = mktime(&r1);
	time_t aa = mktime(&a);
	time_t yy1 = mktime(&r2);
	double diff = difftime(yy1, x1) / (60 * 60 * 24);
	double start = difftime(x1, aa) / (60 * 60 * 24);
	double iter = (double)s / diff;
	for (int i = (int)start; i < (int)diff + (int)start; i++) {
		arr[i] += iter;
	}

}

int main() {
	ifstream inp;
	inp.open("input.txt");
	string bb;
	int size, yr1, yr2, mn1, mn2, dd1, dd2, earn;
	getline(inp, bb);
	size = stoi(bb);

	for (int i = 0; i < size; i++) {
		string buf;
		getline(inp, buf, ' ');
		if (buf == "Earn") {
			buf.clear();
			getline(inp, buf, '-');
			yr1 = stoi(buf);
			buf.clear();
			getline(inp, buf, '-');
			mn1 = stoi(buf);
			buf.clear();
			getline(inp, buf, ' ');
			dd1 = stoi(buf);
			buf.clear();
			getline(inp, buf, '-');
			yr2 = stoi(buf);
			buf.clear();
			getline(inp, buf, '-');
			mn2 = stoi(buf);
			buf.clear();
			getline(inp, buf, ' ');
			dd2 = stoi(buf);
			buf.clear();
			getline(inp, buf, '\n');
			earn = stoi(buf);
			buf.clear();
			give_salary(earn, yr1, mn1, dd1, yr2, mn2, dd2);
		}
		else if (buf == "ComputeIncome") {
			buf.clear();
			getline(inp, buf, '-');
			yr1 = stoi(buf);
			buf.clear();
			getline(inp, buf, '-');
			mn1 = stoi(buf);
			buf.clear();
			getline(inp, buf, ' ');
			dd1 = stoi(buf);
			buf.clear();
			getline(inp, buf, '-');
			yr2 = stoi(buf);
			buf.clear();
			getline(inp, buf, '-');
			mn2 = stoi(buf);
			buf.clear();
			getline(inp, buf);
			dd2 = stoi(buf);
			buf.clear();
			cout << take_salary(yr1, mn1, dd1, yr2, mn2, dd2) << endl;
		}
	}
	return 0;

}
