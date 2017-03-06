#include <iostream>
#include <ctime>
#include <clocale>
#include "sorting_func.h"

using namespace std;

/* ���������� ������� ���������� �������. */
void rand_mass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 10;
	}
}

/* ������ ������� */
void print_mass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " | " << mass[i];
	}
}

/* �������� ������� i-�� ������� �������, � ��������� �� ���. */
void change(int *mass, int i, int step)
{
	mass[i] ^= mass[step];							// 0+1 = 1; a = 1
	mass[step] ^= mass[i];							// 1+1 = 0; b = 0
	mass[i] ^= mass[step];							// 1+0 = 1; a = 1
}

void heapsort(int *mass, int n)
{
	int b, i;
	int sh = 0;
	int left_cld, right_cld;
	while (sh + 2 != n)
	{
		b = 0; // ���� �� ����� ���������, �� ������ �� ���������
		for (i = 0; i < n; ++i) // ������� ������� (������� i ��������� �� �������� � ������� ���������)
		{
			left_cld = i * 2 + 1 + sh; // ����� �����������
			right_cld = i * 2 + 2 + sh; // ������ �����������
			if (right_cld < n) // ���� ������ ����������� ������ ���-�� ��������� ������� (����� �� ������� �� ������� �������)
			{
				if (mass[left_cld] < mass[right_cld] && mass[left_cld] < mass[i + sh]) // ���� ������ ����������� ������ ������ � �������� ������� � ������������ �� ��� �������������
					{
						change(mass, i + sh, left_cld); // ������ ������� ����� ����������� � 
						b = 1; // ����������� ���������
					}
					else if (mass[left_cld] > mass[right_cld] && mass[right_cld] < mass[i + sh]) // ���� ����� ����������� ������ ������� �
					{
						change(mass, i + sh, right_cld); // ������ ������� ������ ����������� �
						b = 1; // ����������� ���������
					}
			}
			if (mass[i + sh] > mass[left_cld] && left_cld < n) // ���� ����� ����������� ������ ���-�� ��������� ������� (����� �� ������� �� ������� �������)
				{
					change(mass, i + sh, left_cld); // ������ ������� ����� ����������� �
					b = 1; // ����������� ���������
				}
			}
		if (b == 0) sh++; // ������� ��������� � ��������
	}
}