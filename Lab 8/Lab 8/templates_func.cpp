#define _CRT_SECURE_NO_WARNINGS								         // ���������� �������������� ��� fopen

#include <iostream>
#include <clocale>
#include "templates_func.h"

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

	delete first, pre;
	return p;														 // ���������� ��������� �������
}

//������� �������� � ��������������� ������
point* insert_elem(point *p, T item)
{
	point *new_item = new(point);									 // �������� ������ �������� ������

	new_item->key = item;											 // ������������ �������� �������� ������
	new_item->pre = p;												 // ���������� ������� ����� ��������
	p->next = new_item;												 // ����������� ������� ����� ������

	p = new_item;													 // ������� ������� ����� ������

	return p;														 // ���������� ��������� �������
}

// �������� �������� ������
point* delete_point(point *p, point *root) {
	point *pre_elem, *next_elem;

	if (p == root)													 // ���� �������� �������
	{
		root = root->next;										     // ��� ���������� �������� ��������� �� ������� �� ����������
		root->pre = NULL;
	}
	else
	{
		pre_elem = p->pre;											 // ��������� � ���������� ��������
		next_elem = p->next;

		pre_elem->next = p->next;									 // ������ ���������
		next_elem->pre = p->pre;
	}

	return root;													// ���������� �������� �������
}

// ������ ������
void listprint(point *p, int elems)
{
	if (p == NULL)													 // ���� ������ �� ����������, �� ������� ��������������� ���������
		cout << "������ ����.";
	else {
		int cnt = 0;
		while (cnt < elems)											 // ������� ���� ��������� ������ � ������������ � �� �����������
		{
			printf("! %d !", p->key);
			p = p->next;								      		 // ��������� ������� ������
			cnt++;
		}
	}
	cout << endl;
}

// ������� ������
point* delete_all(point *p)
{
	point *temp = NULL;												 // ��������� ���������

	while (p != NULL)												 // ���� ������ �� ����������
	{
		temp = p->pre;										         // ��������� ��������� ������������� ���������� �������� ������
		delete p;
		p = temp;													 // ���������� �������� ������ ������������� ����� ����������� ���������� ������� ������
	}

	delete temp;
	return p;
}

// ������� �������� �������� ���-�� ��������� ������ �� ��������� ��������
point* delete_elem(point *p, point *root, T del_num, int quantity) {

	int security = 0;												 // ��������� ��������� �������� del_num
	int i = 0;														 // ������� ��������� ���������

	do {
		if (security == 1 && i < quantity) {							 // ���� �������� del_num ������� � ��� �� ������� �������� ���-�� ���������
			root = delete_point(p, root);
			i++;
		}

		if (p->key == del_num) {									    // ���� �������� �������� �������� ����� ���������
			security = 1;
		}

		p = p->pre;												   // ���������� �������

	} while (p != NULL);

	return root;												   // ���������� �������� ������� ������
}

//�������� ������ � ����
void in_file(point *p, char *filename, int elems) {
	FILE *fs;
	int n = 0;
	fs = fopen(filename, "wb");
	if (fs != NULL) {												 // �������� �� ������� �������� � �����
		while (n < elems)											 // ����������� ��� �������� ������ � ������
		{
			fwrite(p, sizeof(point), 1, fs);
			p = p->next;											 // ��������� ������� ������
			n++;
		}
	}
	fclose(fs);
}

// ������ �������������� ��������� � ������ �����
point* insert_root_elem(point *root, int elems)
{
	point *temp_list;

	for (int i = 0; i < elems; i++)									 // ������������ �������������� ���������
	{
		temp_list = new(point);										 // ����� ������� ������
		temp_list->pre = NULL;
		temp_list->key = scan_elem();
		root->pre = temp_list;										 // ���������� ������� ��� ���������, ��� ����� ������� ������
		temp_list->next = root;										 // ��������� � ��������� ��������
		root = temp_list;											 // ����� �������� ������� ������
	}

	return root;													 // ���������� �������� �������
}

// ������� ������ �� �����
point* from_file(char * filename)
{

	FILE *fs;
	point *strct, *curr_strct, *p;
	curr_strct = make_point(0);										 // ������������� ��������� ��������� ��� ���������� � ��� ��������� ����
	fs = fopen(filename, "rb");

	fread(curr_strct, sizeof(point), 1, fs);
	strct = make_point(curr_strct->key);							 // �������� �������
	p = strct;														 // �������� ������� ����������� � ��������� p
	if (fs != NULL) {												 // �������� �� ������� �������� � �����
		while (!feof(fs))											 // ���� ���� �� ����������
		{
			fread(curr_strct, sizeof(point), 1, fs);
			strct = insert_elem(strct, curr_strct->key);		     // �������� ��������� �������
		}
	}
	fclose(fs);
	delete curr_strct, strct;
	return p;														 // ���������� �������� �������
}

// ������ ��������� � ����� ������
point* insert_end_elem(point *p, int elems) {
	int in_val;

	for (int n = 1; n < elems; n++) {								 // ������� ���������
		in_val = scan_elem();										 // ��������� ��������
		p = insert_elem(p, in_val);								   	 // ������� ���������� �������� ������ �� ���������, ������ ������ ��������; ������������ p ����� ��������� ������
	}

	return p;
}

// ������� ��� ��������� ��������� �������� ������ �� ������
template <typename T>
T scan_elem(T val) {
	T in_val;
	cout << "������� ��������� ������� " << endl;
	cin >> in_val;

	return in_val;
}
