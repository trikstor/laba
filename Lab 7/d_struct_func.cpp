#define _CRT_SECURE_NO_WARNINGS		

#include <iostream>
#include <clocale>
#include "d_struct_func.h"

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

//������� �������� � �������� ������� � ��������������� ������
point* insert_elem(point *p, int item)
{
	point *newitem = new(point);									 // �������� ������ �������� ������

	newitem->key = item;											 // ������������ �������� �������� ������
	newitem->pre = p;												 // ���������� ������� ����� ��������
	p->next = newitem;												 // ����������� ������� ����� ������

	p = newitem;													 // ������� ������� ����� ������

	return p;														 // ���������� ��������� �������
}

// �������� �������� ������
void delete_point(point *p, point *root){
	point *pre_elem, *next_elem;

	if (p == root)													 // ���� �������� �������
	{
		// �� ��������
		point *temp;
		temp = p->next;												 // ��� ���������� �������� ��������� �� ������� �� ����������
		temp->pre = NULL;
		free(p);
		p = temp;
	}
	else
	{
		pre_elem = p->pre;											 // ��������� � ���������� ��������
		next_elem = p->next;

		pre_elem->next = p->next;									 // ������ ���������
		next_elem->pre = p->pre;
		free(p);
	}
}

// ������ ������
void listprint(point *p, int elems)
{
	point *temp = p;												 // ��������� ���������
	if (p == NULL)													 // ���� ������ �� ����������, �� ������� ��������������� ���������
		cout << "������ ����.";
	else{
		int cnt = 0;
		while (cnt < elems)											 // ������� ���� ��������� ������ � ������������ � �� �����������
		{
			printf("! %d !", temp->key);
			temp = temp->next;										 // ��������� ������� ������
			cnt++;
		}
	}
	cout << endl;
}

// ������� ������
point* delete_all(point *p)
{
	while (p != NULL)												 // ���� ������ �� ����������
	{
		point *temp = p->pre;										 // ��������� ��������� ������������� ��������� �������� ������
		delete p; 
		p = temp;													 // ���������� �������� ������ ������������� ����� ����������� ��������� ������� ������
	}
	return p;
}

// ������� �������� �������� ���-�� ��������� ������ �� ��������� ��������
void delete_elem(point *p, point *root, int del_num, int quantity){
	int security = 0;												 // ��������� ��������� �������� del_num
	int i = 0;														 // ������� ��������� ���������

	do {
		if (security == 1 && i < quantity){							 // ���� �������� del_num ������� � ��� �� ������� �������� ���-�� ���������
			delete_point(p, root);
			i++;
		}

			if (p->key == del_num){									 // ���� �������� �������� �������� ����� ���������
				security = 1;
			}

		p = p->pre;

	} while (p != NULL);
}

//�������� ������ � ����
void in_file(point *p, char *filename, int elems){
	FILE *fs;
	int n = 0;
	fs = fopen(filename, "wb");
	if (fs != NULL){												 // �������� �� ������� �������� � �����
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
point *insert_root_elem(point *p, int elems)
{
	point *temp_list;
	point *root;
	root = p;														 // ���������� ��������� �������� � ����� ���������
	for (int i = 0; i < elems; i++)									 // ������������ �������������� ���������
	{
		temp_list = new(point);										 // ����� ������� ������
		temp_list->pre = NULL;
		temp_list->key = i;
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
	if (fs != NULL){												 // �������� �� ������� �������� � �����
		while (!feof(fs))											 // ���� ���� �� ����������
		{
				fread(curr_strct, sizeof(point), 1, fs);
				strct = insert_elem(strct, curr_strct->key);		 // �������� ��������� �������
		}
	}
	fclose(fs);

	return p;														 // ���������� �������� �������
}