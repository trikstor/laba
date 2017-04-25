#define _CRT_SECURE_NO_WARNINGS										// ���������� ��������������.
#include <iostream>
#include "RK_func.h"
#include <cstring>

using namespace std;

// �������� ��������� �������� ������ (�������������)
point* make_point(int key)
{
	point *first, *pre, *p;

	first = NULL;
	pre = NULL;														 // ��������� �� ��������� � ���������� �������� ������ ����� NULL

	p = new(point);													 // ������� �������� ������� ������

	p->key = key;
	p->next = first;												 // ������������ ��������������� ��������
	p->pre = pre;

	return p;														 // ���������� ��������� �������
}

//������� �������� � ��������������� ������
point* insert_elem(point *p, int item)
{
	point *newitem = new(point);									 // �������� ������ �������� ������

	newitem->key = item;											 // ������������ �������� �������� ������
	newitem->pre = p;												 // ���������� ������� ����� ��������
	newitem->next = NULL;
	p->next = newitem;												 // ����������� ������� ����� ������

	p = newitem;													 // ������� ������� ����� ������
	return p;														 // ���������� ��������� �������
}

// ������ ������
void listprint(point *p)
{
	if (p->key == -1)												// ���� ������ �� ����������, �� ������� ��������������� ���������
		printf("��� ����������.\n");
	else {

		while (p != NULL)											// ������� ���� ��������� ������ � ������������ � �� �����������
		{
			if (p->key != -1)										// ���� ������� ������� ������ �� ����� �������� ��������.
				printf("���������� � %d\n", p->key);

			p = p->pre;												// ��������� ������� ������
		}
	}
}

// ������ ������.
void print_str(char *mass, int mass_l)
{
	for (int i = 0; i < mass_l; i++)
	{
		printf("%c", mass[i]);
	}
	printf("\n");
}

// ���������� ���� ��� ��������� � ������ � start_index � ���-�� quantity ��������.
unsigned long long int RK_hash(char *str, int start_index, int quantity)
{
	unsigned long long int result = 0;

	/* ������� �������� ��������� � �������������� �� � �������� ����. 
	������� ��������� �������� ������� � ������� ��������� � ���������� 13.
	*/
	for (int i = start_index; i < start_index + quantity; i++)
		result += (unsigned long long int)((int)(str[i]) * pow(13, i - start_index));

	return result;
}

// �������������� �������� ���������� ������ � ���������.
bool RK_check(char *str, char *templa, int num, int templa_l)
{
	for (int i = num; i < templa_l; i++)												// ������������ �������� ������ � ���������.
	{
		if (str[i] != templa[i - num])													// ���� �����-�� �������� �� �������, �� ���������� ����, ����� - ������.
			return false;
	}
	return true;
}

// ����� ������ - ����� ��������� � ������, ������ str ������ � str_l �������� � ��������� templa ������ � templa_l ��������.
void RK_search(char *str, char *templa, int str_l, int templa_l)
{
	point *sovp = make_point(-1);														// �������� ��������� ������ (�������� �������).

	unsigned long long int last_hash = RK_hash(str, 0, templa_l);						// ���������� ���� �� ������ ��������� ������, ����� templa_l.
	unsigned long long int templa_hash = RK_hash(templa, 0, templa_l);					// ���������� ���� �� �������.

	for (int i = 0; i + templa_l <= str_l; i++)											// ������� �������� ������ ��� ��������� �� ������ ���������.
	{
		// ���� ������� ��� ��������� ����� ���� �������, ��, ����������������, ��������� ����� �������.
		if (last_hash == templa_hash)
			if(RK_check(str, templa, i, templa_l) == true)
				sovp = insert_elem(sovp, i);											// ��������� � ������ ������ ������� ������, � �������� �������� ���������.

		last_hash -= (unsigned long long int)(RK_hash(str, i, 1));						// �������� ��� ��������� �� ��������� �������.
		last_hash /= 13;																// ������� ������� 13 ��� ���������� ����������� �������.
		// ��������� ��� ����������� ������� �� ������.
		last_hash += (unsigned long long int)(RK_hash(str, i + templa_l, 1) * pow(13, templa_l - 1));
	}

	listprint(sovp);																	// ������ ������.

	delete sovp;																		// �������� ������
}

// ���������� ������ � ������ ������� ��� �������������������� ������.
void lower(char *mass, int mass_l)
{
	for (int i = 0; i < mass_l; i++)
	{
		mass[i] = tolower(mass[i]);
	}
}

// ���������� ���������� ����� ��������� � ����� ������� ������ ��� ������ ������.
void RFile(char *filename, char *templa, int templa_l)
{
	FILE *fp;
	int mass_l;
	fp = fopen(filename, "r+");										// �������� ����� � ������ ������.
	if (fp == NULL)													// ���������������, ���� ���� �� �����������.
	{
		printf("���� �� �����������.\n");
	}
	else
	{
		while (!feof(fp))											// ���� �� ����� ��������� ����� �����.
		{
			char *mass = new char[255];								// ������ ��� ������.
			fgets(mass, 255, fp);									// ���������� ������ �� �����, ������������ ����� � 255 ��������.
			mass_l = strlen(mass);									// ����� ������.

			lower(mass, mass_l);									// ���������� ����� � ������ �������.
			lower(templa, templa_l);

			print_str(mass, mass_l);								// ������ ������� ������.
			RK_search(mass, templa, mass_l, templa_l);
			delete[] mass;											// �������� ������.
		}
		fclose(fp);													// �������� �����.
	}
														
}