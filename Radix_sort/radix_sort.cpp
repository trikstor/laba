#include <iostream>
#include <ctime>
#include <cmath>
#include <clocale>
#include "sorting_func.h"

using namespace std;

/* ���������� ������� ���������� �������.
���������� ������� ������� �������, ������������� �� ������ ����������.
����������� ���� ��������� ������� >= �������� - ������, � ��� �������� < �������� - �����.
����� ��������� ������ ������� ����������.
���� � ���������� ������ 2 ���������, ���������� ��������� ������������������� �������� ��� ����������. */
int main()
{
	setlocale(LC_ALL, "Russian");								// ������� �� ������� �����.
	srand(time(0));												// ���������� ���������� ��������� �����.
	int num;													// ���-�� ��������� �������.

	cout << "������� ���-�� ��������� �������." << endl;
	cin >> num;

	int *mass = new int[num];									// �������� ������������� �������

	rand_mass(mass, num);										// ���������� ������� ���������� �������.
	print_mass(mass, num);

	radix_sort(mass, num);						    // ������� ���������� �������

	cout << endl << "������������� ������." << endl;

	print_mass(mass, num);

	delete[] mass;												// �������� ������������� �������.
	system("pause");											// �������� �������.
	return 0;
}