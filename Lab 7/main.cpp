#define _CRT_SECURE_NO_WARNINGS								 // ���������� �������������� ��� fopen

#include <iostream>
#include <clocale>
#include "d_struct_func.h"

using namespace std;

/*
9 �������.

1.	�������� ������.
2.	���������� �������� � ������ (� ������������ �� ����� ���������).
3.	�������� �������� �� ������ (� ������������ �� ����� ���������).
4.	������ ������.
5.	������ ������ � ����.
6.	����������� ������.
7.	�������������� ������ �� �����.

������ � �������� ������ �������� �������� ����� ���� int. ������������ ��������������� ������. 
������� �� ���� � ��������� ����� ��������� � �������� �������,
�������� � ��������� � ������ ������
*/
int main() {

	setlocale(LC_ALL, "Russian");							 // ������� ���� � �������

	point *end, *root;										 // ���������� �������� � ��������� ��������� ������

	int elems;												 // ���������� ���������

	cout << "������� ���-�� ���������" << endl;
	cin >> elems;

	root = make_point(0);
	end = root;

	for (int n = 1; n <= elems; n++)						 // ������� ���������
		end = insert_elem(end, n);							 // ������� ���������� �������� ������ �� ���������, ������ ������ ��������; ������������ p ����� ��������� ������

	listprint(root, elems);									 // ������ ������


	int del_num, quantity;									 // ������� ��� ��������; ���������� ��������� ���������; ���������� ��������� ���������



	cout << "������� ������� ��� ��������" << endl;
	cin >> del_num;

	cout << "������� ���-�� ��������� ��� �������� � ����������" << endl;
	cin >> quantity;



	delete_elem(end, root, del_num, quantity);					 // �������� ��������� � ���������������� �����������

	listprint(root, elems - quantity);						// ������ ������



	root = insert_root_elem(root, quantity);

	listprint(root, elems);									 // ������ ������



	in_file(root, "file.txt", elems);						 // ������ ������ � ����

	root = delete_all(root);								 // �������� ������ 

	listprint(root, elems);									 // ������ ������� ������

	end = from_file("file.txt");							 // �������������� ������ �� �����

    listprint(end, elems);									 // ������ ������



	delete end;												 // �������� ����������
	delete root;

	system("pause");										 // �������� �������

	return 0;
}
