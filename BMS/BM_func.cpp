#define _CRT_SECURE_NO_WARNINGS										// ���������� ��������������.
#include <iostream>
#include "BM_func.h"
#include <cstring>

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
	else{

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

// ������� ����������� ������� ��� ������ ����� ��������.
void Shift(char *templa, int templa_l, int *alphabet, int *shift, int counter)
{
	int flag = 0;													// ����, ����������� �� ������� ������� ������� � ������� �������.
	int count = 0;													// ������� ������ ��� ������������� �������.

	for (int i = 0; i < templa_l; i++)								// ������� ������� �������.
	{
		if (shift[(int)templa[i]] >= 0)								// ���� ������ ������ ��� ���� � ������� �������.
			flag = 1;												// �������� ����, ����� �� �������������� ����� ��� ������� �������.

		if (flag == 0)												// ���� ������ ������� ��� ��� � ������� �������.
		{
			for (int n = templa_l - 2; n >= 0; n--)					// ���� ���������� � �������������� ������� ������ �������.
			{
				count++;											// ������� ������.
				if (templa[i] == templa[n] && count > 0)			// ���� ����� ������ ����������, �� ����������� �����.
				{
					shift[(int)templa[i]] = count;
					count = -255;									// ����������� ��������, �������������� ��������� ������� ��� ����������.
				}
			}
		}
		count = 0;													// �������� �����.
		flag = 0;													// �������� ����.
	}
	// ����������� ����������� �������� � ������� ������������ ��������, �����, ������ ����� �������.
	for (int i = 0; i < 255; i++)
	{
		if (alphabet[i] == 1 && shift[i] < 0)
		{
			shift[i] = templa_l;
		}
	}
}

// ���������� ������ � ������ ������� ��� �������������������� ������.
void lower(char *mass, int mass_l)
{
	for (int i = 0; i < mass_l; i++)
	{
		mass[i] = tolower(mass[i]);
	}
}

// ���������� �������� ��� ������.
int alphabetcnt(char *mass, int mass_l, int *alphabet)
{
	int counter = 0;												// ������� ���-�� ���� � ��������.
	for (int i = mass_l - 1; i >= 0; i--)
	{
		if (alphabet[(int)mass[i]] != 1)							// ���� ����� ����� ��� �� ���� � ��������.
		{
			// ���������� �������� ������� 1 � �������� ��������, ������������� ����� ��������.
			alphabet[(int)mass[i]] = 1;
			counter++;
		}
	}
	return counter;
}

// ����� ������ - ���� ��������� � ������.
int BM_search(char *mass, int mass_l, char *templa, int templa_l)
{
	point *sovp = make_point(-1);									// �������� ����� ���������������� ������.

	int *shift = new int[255];										// ������ �������.
	int *alphabet = new int[255];									// ������ ��������.

	int word;														// ����� ��������.
	int sign = templa_l - 1;										// ������ ���������� �� ������ ������, ���������� ����������� ����� ����� �������.
	int sovpad = 0;													// ���-�� ����� �� ������� �������.
	int flag = 0;													// ���� ������� ������� ����������.

	word = alphabetcnt(mass, mass_l, alphabet);						// ���������� �������� ��� ������.
	Shift(templa, templa_l, alphabet, shift, word);					// ����������� ������� ������� ��� ������.
	while (sign < mass_l)											// ���� �� ����� ��������� ����� ������.
	{

		if (mass[sign] == templa[templa_l - 1])						// ���� ��������� ������ ������� ����� ���������������� ������� ������.
		{
			for (int n = 0; n < templa_l; n++)						// �������� ��� �� ���������, ������ ������ �������.
			{
				if (mass[sign - n] != templa[templa_l - n - 1])		// ���� ���� ������������.
				{
					if (flag != 1) {
						sovpad = shift[(int)mass[sign - n]];		// �����, ��������������� ������������ ������� ������.
					}
					flag = 1;										// ������ ����, ����� �������� ����������.
				}
			}

			if (flag == 0)											// ���� ��� ������� �������, �� ����������� ����������.
				sovp = insert_elem(sovp, sign - templa_l + 1);		// ���������� �������� � ������.

			flag = 0;												// ��������� ����.
		}
		else
		{
			// ���� ������ �� ������ �� ������, �� ����� ������������� ������������ ������� ������.
			sovpad = shift[(int)mass[sign]];
		}

		if (sovpad == 0) {											// ������ �� ������������.
			sovpad++;
		}

		sign += sovpad;												// ����������� ���������� �� ������ ������ �� �����.
	}

	listprint(sovp);												// ������ ������ � ������������.

	delete[] shift;													// �������� ������������ ��������.
	delete[] alphabet;
	delete sovp;

	return 0;
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
			BM_search(mass, mass_l, templa, templa_l);				// ����� ��������� � ������.
			delete[] mass;											// �������� ������.
		}
	}
	fclose(fp);														// �������� �����.
}