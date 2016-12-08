#ifndef d_stuct_func_h
#define d_stuct_func_h

struct point
{
	int key;									 // ���������� �������� ������
	point* next;								 // ��������� �� ��������� ������� ������
	point* pre;									 // ��������� �� ���������� ������� ������
};
/*
�������� ��������� �������� ������, ���������� �������� �������
*/
point* make_point(int);
/*
������� �������� � ����� ������, ���������� ��������� �� ��������� ������� ������
*/
point* insert_elem(point*, int);
/*
�������� �������� ������ � ��������������� ����������
*/
void delete_point(point*, point*);
/*
������ ������
*/
void listprint(point*, int);
/*
�������� ���� ��������� ������
*/
point* delete_all(point*);
/*
�������� ��������� ���������� ��������� �� ���������
*/
void delete_elem(point*, point*, int, int);
/*
������ ������ � ����
*/
void in_file(point*, char*, int);
/*
����� ������ �� �����
*/
point* from_file(char*);
/*
������ �������������� ��������� � ������ �����
*/
point *insert_root_elem(point*, int);

#endif