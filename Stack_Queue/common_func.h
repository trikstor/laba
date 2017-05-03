#pragma once
#include <iostream>

using namespace std;

// ��������� ��� �������� �������� ������������� ����������.
template <typename T>
struct for_input_params
{
	T in_val;													// �������� ������� ������
	int counter;												// ���-�� ��������� � ������
	int del_q;													// ���-�� ��������� ��������� ������
};

// ---------------------------------------------------------
// ������� ��� ��������� ��������� �������� ������ �� ������
template <typename T>
T scan_elem()
{
	T in_val;
	cout << "������� ��������� ������� " << endl;
	cin >> in_val;


	return in_val;
}

template <typename T>
T *scan_elem(T *str)
{
	cout << "������� ��������� ������� " << endl;
	cin >> str;


	return str;
}
// ----------------------------------------------------------

// ----------------------------------------------------------
// ������� ��� ��������� ��� �� ��������� � ������, ���-�� ��������� ���������, ��������� ��������� ������
template <typename T>
void input_params(for_input_params<T> *help_struct)
{
	int cntr, delq;
	T inval;


	cout << "������� ���-�� ��������� � �������" << endl;
	cin >> cntr;
	cout << "������� ���-�� ��������� ���������" << endl;
	cin >> delq;

	// ��������� ��������� �������� ������.
	inval = scan_elem<T>();

	// ������ ������������ � ���������, ��� ��� ������� �� ����� ���������� ��������� ����������.
	help_struct->counter = cntr;
	help_struct->del_q = delq;
	help_struct->in_val = inval;
}

template <typename T>
char *input_params(for_input_params<T> *help_struct, char *str)
{
	int cntr, delq;


	cout << "������� ���-�� ��������� � �������" << endl;
	cin >> cntr;
	cout << "������� ���-�� ��������� ���������" << endl;
	cin >> delq;

	// ��������� ��������� �������� ������.
	str = scan_elem<T>(str);

	// ������ ������������ � ���������, ��� ��� ������� �� ����� ���������� ��������� ����������.
	help_struct->counter = cntr;
	help_struct->del_q = delq;


	return str;													  // ���������� ���������� �� ������������ ������(������)
}
// ----------------------------------------------------------

