//#include "BitArray.h"
//#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include <vector>
#include <limits>
#include <tuple>
#include <cassert>
#include <stdexcept>

using namespace std;

class BitArray
{
public:
	BitArray() {
		bites = (bool*)calloc(8, sizeof(bool));
		len = 8;
	}
	~BitArray() {
		delete[] bites;
		len = 0;
	}

	//Конструирует массив, хранящий заданное количество бит.
	//Первые sizeof(long) бит можно инициализровать с помощью параметра value.
	explicit BitArray(int num_bits, unsigned long value = 0) {
		if (num_bits > 0) {
			bites = (bool*)calloc(num_bits, sizeof(bool));
			for (int i = 0; i < value; i++)
				bites[i] = 1;
			len = num_bits;
		}
		else
			throw out_of_range("Bitset must contain more than 0 elemets");
			//cout << "Bitset must contain more than 0 elemets" << endl;
	}

	BitArray(const BitArray& b) {
		unsigned int size = sizeof(b.bites);
		bites = (bool*)malloc(size);
		for (unsigned int i = 0; i < size; i++)
			bites[i] = b.bites[i];
	}

	//Обменивает значения двух битовых массивов.
	void swap(BitArray& b) {
		if (sizeof(bites) == sizeof(b.bites)) {
			bool temp = 0;
			for (unsigned int i = 0; i < sizeof(bites); i++) {
				temp = bites[i];
				bites[i] = b.bites[i];
				b.bites[i] = temp;
			}
		}
		else
			throw out_of_range("Bitsets must be equal");
	}

	BitArray& operator=(const BitArray& b) {
		if (sizeof(bites) == sizeof(b.bites)) {
			for (unsigned int i = 0; i < sizeof(bites); i++)
				bites[i] = b.bites[i];
		}
		else {
			free(bites);
			bites = (bool*)malloc(sizeof(b.bites));
			for (unsigned int i = 0; i < sizeof(bites); i++)
				bites[i] = b.bites[i];
		}
		return *this;
	}
	//Изменяет размер массива. В случае расширения, новые элементы инициализируются значением value.
	void resize(int num_bits, bool value = false) {
		if (num_bits == 0)
			free(bites);
		else {
			bites = (bool*)realloc(bites, num_bits);
			//unsigned int* al = (unsigned int*)realloc(bites, sizeof(bool) / 8 * num_bits);
			for (unsigned int i = len; i < num_bits; i++) {
				if (value == 0)
					bites[i] = 0;
				else
					bites[i] = 1;
			}
			len = num_bits;
		}

	}
	//Очищает массив.
	void clear() {
		free(bites);
		len = 0;
	}
	//Добавляет новый бит в конец массива. В случае необходимости происходит перераспределение памяти.
	void push_back(bool bit) {
		for (unsigned int i = 0; i < len; i++) {
			if (bites[i] == 205) {
				bites[i] = bit;
				return;
			}
		}
		resize(len + 1, bit);
	}
	//Битовые операции над массивами.
	//Работают только на массивах одинакового размера.
	//Обоснование реакции на параметр неверного размера входит в задачу.
	BitArray& operator&=(const BitArray& b) {
		for (unsigned int i = 0; i < sizeof(bites); i++)
			bites[i] &= b.bites[i];
		return *this;
	}

	BitArray& operator|=(const BitArray& b) {
		for (unsigned int i = 0; i < sizeof(bites); i++)
			bites[i] |= b.bites[i];
		return *this;
	}

	BitArray& operator^=(const BitArray& b) {
		for (int i = 0; i < len; i++) {
			if (bites[i] == b.bites[i])
				bites[i] = 0;
			else
				bites[i] = 1;
		}
		return *this;
	}

	//Битовый сдвиг с заполнением нулями.
	BitArray& operator<<=(int n) {
		int j = 0;
		for (int i = n; i < len + n; i++) {
			if (i >= len) {
				bites[j] = 0;
				j++;
			}
			else {
				bites[j] = bites[i];
				j++;
			}
		}
		return *this;
	}

	BitArray& operator>>=(int n) {
		int j = len;
		for (int l = 0; l < n; l++) {
			for (unsigned int i = len - 1; i >= 1; i--)
				bites[i] = bites[i - 1];
			bites[0] = 0;
		}
		return *this;
	}
	BitArray operator<<(int n) const {
		for (int i = 0; i < len - n; i++)
			bites[i] = bites[i + n];
		for (int i = len - n; i < len; i++)
			bites[i] = false; // Заполняем освободившиеся позиции нулями
		return *this;
	}
	BitArray operator>>(int n) const {
		for (int i = len - 1; i >= n; i--)
			bites[i] = bites[i - n];
		for (int i = 0; i < n; i++)
			bites[i] = false; // Заполняем освободившиеся позиции нулями
		return *this;
	}

	//Устанавливает бит с индексом n в значение val.
	BitArray& set(int n, bool val = true) {
		bites[n] = val;
		return *this;
	}
	//Заполняет массив истиной.
	BitArray& set() {
		for (unsigned int i = 0; i < len; i++)
			bites[i] = 1;
		return *this;
	}

	//Устанавливает бит с индексом n в значение false.
	BitArray& reset(int n) {
		bites[n] = false;
		return *this;
	}
	//Заполняет массив ложью.
	BitArray& reset() {
		for (int i = 0; i < len; i++)
			bites[i] = false;
		return *this;
	}

	//true, если массив содержит истинный бит.
	bool any() const {
		for (int i = 0; i < len; i++) {
			if (bites[i] == 0)
				continue;
			else
				if (bites[i] == 1)
					return true;
		}
		return false;
	}
	//true, если все биты массива ложны.
	bool none() const {
		return (!this->any());
	}
	//Битовая инверсия
	BitArray operator~() const {
		for (int i = 0; i < len; i++) {
			if (bites[i] == true)
				bites[i] = false;
			else
				bites[i] = true;
		}
		return *this;
	}
	//Подсчитывает количество единичных бит.
	int count() const {
		int count = 0;
		for (int i = 0; i < size(); i++)
			if (bites[i] == 1)
				count++;
		return count;
	}

	//Возвращает значение бита по индексу i.
	bool operator[](int i) const {
		return bites[i];
	}

	int size() const {
		return len;
	}

	bool empty() const {
		if (len == 0)
			return true;
		else
			return false;
	}

	//Возвращает строковое представление массива.
	string to_string() const {
		string str = "";
		for (unsigned int i = 0; i < len; i++) {
			if (bites[i] == true)
				str += '1';
			if (bites[i] == false)
				str += '0';
		}
		return str;
	}

	void print_array() {
		for (int i = 0; i < len; i++)
			cout << bites[i];
		cout << endl;
	}
private:
	bool* bites;
	int len;
};

bool operator==(const BitArray& a, const BitArray& b)
{
	bool flag = true;
	if (a.size() != b.size())
		flag = false;
	else {
		for (unsigned int i = 0; i < a.size(); i++)
			if (a[i] != b[i]) {
				flag = false;
				break;
			}
	}
	return flag;
}

bool operator!=(const BitArray& a, const BitArray& b)
{
	bool flag = false;
	if (a.size() != b.size())
		flag = true;
	else {
		for (unsigned int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				flag = true;
				break;
			}
		}
	}
	return flag;
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
	BitArray temp(b1);
	if (b1.size() != b2.size()) {
		cout << temp.size() << b2.size() << endl;
		throw out_of_range("Arrays are not equal");
		//cout << "Arrays are not equal" << endl;
	}
	else {
		for (int i = 0; i < b1.size(); i++) {
			if (b1[i] == 1 && b2[i] == 1)
				temp.set(i);
			else
				temp.reset(i);
		}
	}
	return temp;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
	BitArray temp(b1);
	if (b1.size() != b2.size()) {
		cout << temp.size() << b2.size() << endl;
		throw out_of_range("Arrays are not equal");
	}
	else {
		for (int i = 0; i < b1.size(); i++) {
			if (b1[i] == 0 && b2[i] == 0)
				temp.reset(i);
			else
				temp.set(i);
		}
	}
	return temp;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
	BitArray temp(b1);
	if (b1.size() != b2.size()) {
		cout << temp.size() << b2.size() << endl;
		throw out_of_range("Arrays are not equal");
	}
	else {
		for (int i = 0; i < b1.size(); i++) {
			if (b1[i] == b2[i])
				temp.reset(i);
			else
				temp.set(i);
		}
	}
	return temp;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//int main() {
//	BitArray bites0(8, 8), bites1(8, 4);
//	// исходные массивы
//	cout << "bites0 = ";
//	bites0.print_array();
//	cout << "bites1 = ";
//	bites1.print_array();
//
//	//swap
//	cout << endl << "swap" << endl;
//	bites0.swap(bites1);
//	cout << "bites0 = ";
//	bites0.print_array();
//	cout << "bites1 = ";
//	bites1.print_array();
//
//	//operator=
//	cout << endl << "operator=" << endl;
//	bites0 = bites1;
//	cout << "bites0 = ";
//	bites0.print_array();
//	cout << "bites1 = ";
//	bites1.print_array();
//
//	//resize
//	cout << endl << "resize" << endl;
//	bites0.resize(16);
//	cout << "bites0 = ";
//	bites0.print_array();
//
//	//push_back
//	cout << endl << "push_back" << endl;
//	bites0.push_back(1);
//	cout << "bites0 = ";
//	bites0.print_array();
//
//	//operator&=
//	BitArray bites2(8, 7);
//	cout << endl << "operator&=" << endl;
//	bites1 &= bites2;
//	cout << "bites1 = ";
//	bites1.print_array();
//	cout << "bites2 = ";
//	bites2.print_array();
//
//	//operator|=
//	BitArray bites3(8, 2);
//	cout << endl << "operator|=" << endl;
//	bites3 |= bites2;
//	cout << "bites2 = ";
//	bites2.print_array();
//	cout << "bites3 = ";
//	bites3.print_array();
//
//	//operator^=
//	BitArray bites5(8, 4);
//	cout << endl <<"bites2 = ";
//	bites2.print_array();
//	cout << "bites5 = ";
//	bites5.print_array();
//	cout << "operator^=" << endl;
//	bites2 ^= bites5;
//	cout << "bites2 = ";
//	bites2.print_array();
//	cout << "bites5 = ";
//	bites5.print_array();
//
//	//operator<<=
//	cout << endl << "operator<<=" << endl;
//	bites3 <<= 2;
//	cout << "bites3 = ";
//	bites3.print_array();
//
//	//operator>>=
//	cout << endl << "operator>>=" << endl;
//	bites3 >>= 2;
//	cout << "bites3 = ";
//	bites3.print_array();
//
//	//operator<<
//	cout << endl << "operator<<" << endl;
//	bites3 << 2;
//	cout << "bites3 = ";
//	bites3.print_array();
//
//	//operator>>
//	cout << endl << "operator>>" << endl;
//	bites3 >> 2;
//	cout << "bites3 = ";
//	bites3.print_array();
//
//	//set
//	cout << endl << "set" << endl;
//	bites3.set(7);
//	cout << "bites3 = ";
//	bites3.print_array();
//	//set()
//	cout << "set()" << endl;
//	bites3.set();
//	cout << "bites3 = ";
//	bites3.print_array();
//
//	//reset
//	cout << endl << "reset" << endl;
//	bites3.reset(7);
//	cout << "bites3 = ";
//	bites3.print_array();
//	//reset()
//	cout << "reset()" << endl;
//	bites3.reset();
//	cout << "bites3 = ";
//	bites3.print_array();
//
//	//any()
//	cout << endl << "bites3.any() = " << bites3.any() << endl;
//	//none()
//	cout << endl << "bites3.none() = " << bites3.none() << endl;
//
//	//operator~;
//	cout << endl << "operator~" << endl;
//	~bites3;
//	cout << "bites3 = ";
//	bites3.print_array();
//	
//	//count()
//	cout << endl << "bites3.count() = " << bites3.count() << endl;
//
//	//operator[]
//	cout << endl << "bites3[2] = " << bites3[2] << endl;
//
//	//size()
//	cout << endl << "bites3.size() = " << bites3.size() << endl;
//
//	//empty()
//	cout << endl << "bites3.empty() = " << bites3.empty() << endl;
//	
//
//	cout << (bites2 == bites3) << endl;
//	cout << (bites2 != bites3) << endl;
//
//	BitArray bites4(8, 4);
//
//	bites4 = (bites4 & bites3);
//	bites4.print_array();
//
//	bites4 = (bites4 | bites3);
//	bites4.print_array();
//
//	bites4 = (bites4 ^ bites3);
//	bites4.print_array();
//
//	return 0;
//}
