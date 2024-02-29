#include <iostream>
#include <string>
using namespace std;

int main() {
	string number = "8 ( 902      1  )23-4  56 7", new_number = "";
	//cin >> number;  // ����
	int open_bracket = 0, close_bracket = 0;  // ������� ���-�� (�����������/�����������) ������

	if (number[0] != '8' and (number[0] != '+' and number[1] != '7')) {  // �������� ������������ ���� ������
		cout << "error 1";
		return 1;
	}
	if (number[0] == '8'){  // ����� ������ 8 �� +7
		number[0] = ' ';  
		new_number.push_back('+'); 
		new_number.push_back('7');
	}

	for (int c = 0; number[c] != '\0'; c++) {
		if (number[c] == '-' and number[c+1] == '-') {  // �������� ������ ������ -����-
			cout << "error 2";
			return 1;
		}
		if (number[c] == '(')
			open_bracket += 1;
		if (number[c] == ')')
			close_bracket += 1;
		if (close_bracket > 1 or open_bracket > 1) // ���� ���-�� ����/���� ������ ������ ������
			break;
		if (number[c] != '(' and number[c] != ')' and number[c] != ' ' and number[c] != '-')
			new_number.push_back(number[c]);
	}
	if (open_bracket != close_bracket)
		cout << "error 3";
	else 
		cout << new_number;
		
	return 0;
}