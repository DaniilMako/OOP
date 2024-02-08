//#pragma once
//#include <iostream>
//#include <string>
//using namespace std;
//
//class BitArray
//{
//public:
//	BitArray() = default;
//	~BitArray();
//
//	//������������ ������, �������� �������� ���������� ���.
//	//������ sizeof(long) ��� ����� ��������������� � ������� ��������� value.
//	explicit BitArray(int num_bits, unsigned long value = 0);
//	BitArray(const BitArray& b);
//
//
//	//���������� �������� ���� ������� ��������.
//	void swap(BitArray& b);
//
//	BitArray& operator=(const BitArray& b);
//
//
//	//�������� ������ �������. � ������ ����������, ����� �������� 
//	//���������������� ��������� value.
//	void resize(int num_bits, bool value = false);
//	//������� ������.
//	void clear();
//	//��������� ����� ��� � ����� �������. � ������ ������������� 
//	//���������� ����������������� ������.
//	void push_back(bool bit);
//
//
//	//������� �������� ��� ���������.
//	//�������� ������ �� �������� ����������� �������.
//	//����������� ������� �� �������� ��������� ������� ������ � ������.
//	BitArray& operator&=(const BitArray& b);
//	BitArray& operator|=(const BitArray& b);
//	BitArray& operator^=(const BitArray& b);
//
//	//������� ����� � ����������� ������.
//	BitArray& operator<<=(int n);
//	BitArray& operator>>=(int n);
//	BitArray operator<<(int n) const;
//	BitArray operator>>(int n) const;
//
//
//	//������������� ��� � �������� n � �������� val.
//	BitArray& set(int n, bool val = true);
//	//��������� ������ �������.
//	BitArray& set();
//
//	//������������� ��� � �������� n � �������� false.
//	BitArray& reset(int n);
//	//��������� ������ �����.
//	BitArray& reset();
//
//	//true, ���� ������ �������� �������� ���.
//	bool any() const;
//	//true, ���� ��� ���� ������� �����.
//	bool none() const;
//	//������� ��������
//	BitArray operator~() const;
//	//������������ ���������� ��������� ���.
//	int count() const;
//
//
//	//���������� �������� ���� �� ������� i.
//	bool operator[](int i) const;
//
//	int size() const;
//	bool empty() const;
//
//	//���������� ��������� ������������� �������.
//	std::string to_string() const;
//private:
//	unsigned int* bites;
//};
//
//bool operator==(const BitArray& a, const BitArray& b);
//bool operator!=(const BitArray& a, const BitArray& b);
//
//BitArray operator&(const BitArray& b1, const BitArray& b2);
//BitArray operator|(const BitArray& b1, const BitArray& b2);
//BitArray operator^(const BitArray& b1, const BitArray& b2);
