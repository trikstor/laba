#include <iostream>
#include <iostream>
#include <clocale>

#include "common_func.h"												// ����� �������
#include "Queue_func.h"													// ������� ��� ������ � ��������
#include "Stack_func.h"													// ������� ��� ������ �� ������

using namespace std;

/*
����� �����														  ��-160002
������������ ������ ����� � ������� � �������������� ��������� ����� ������.

���� - ������ ���������, �������������� �� �������� LIFO (��������� ������ - ������ �����).
������������ ����� ����������� �������� ������ � ��������� ����������, �������� ��������� �
������ ������ � �������.

������� - ������ ���������, �������������� �� �������� FIFO (������ ������ - ������ �����).
������������ ����� ���������� �������� ������ � ��������� ����������, �������� ��������� �
������ ������ � �������.

����������� �������: �������� ��������� ������, ���������� ��������� ������, �������� ����� -
���� ��������� ������, ������ ��������� ������.
*/
int main()
{
	setlocale(LC_ALL, "Russian");											// ������� � �������
	int variable;															// ����� ����� ��� �������
	int type;																// ��� �������� ������.

	cout << "��� ������������� ������� ������� 0, ��� ������������� ����� ������� 1." << endl;
	cin >> variable;

	if (variable == 0)
	{
		cout << "������� ��� ������: \n\t1 - int\n\t2 - double\n\t3 - char\n\t4 - ������� char" << endl;
		cin >> type;
		// ����� ��������� ������� ������ � ��������, ��������� ������ ���� ������
		switch (type)
		{
		case 1:
			Start_Queue<int>();
			break;
		case 2:
			Start_Queue<double>();
			break;
		case 3:
			Start_Queue<char>();
			break;
		case 4:
			Start_Queue_mass<char>();
			break;
		}
	}
	else
	{
		cout << "������� ��� ������: \n\t1 - int\n\t2 - double\n\t3 - char\n\t4 - ������� char" << endl;
		cin >> type;
		// ����� ��������� ������� ��� ������ �� ������, ��������� ������ ���� ������
		switch (type)
		{
		case 1:
			Start_Stack<int>();
			break;
		case 2:
			Start_Stack<double>();
			break;
		case 3:
			Start_Stack<char>();
			break;
		case 4:
			Start_Stack_mass<char>();
			break;
		}
	}


	system("pause");														// �������� �������
	return 0;
}