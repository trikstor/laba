#ifndef templates_func_h
#define templates_func_h

template <typename T>
struct point
{
	T key;									 // ���������� �������� ������
	point *next;								 // ��������� �� ��������� ������� ������
	point *pre;									 // ��������� �� ���������� ������� ������
};
/*
�������� ��������� �������� ������, ���������� �������� �������
*/
template <typename T>
point *make_point(T);
/*
������� �������� � ����� ������, ���������� ��������� �� ��������� ������� ������
*/
template <typename T>
point *insert_elem(point*, T);
/*
�������� �������� ������ � ��������������� ����������
*/
point *delete_point(point*, point*);
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
template <typename T>
point* delete_elem(point*, point*, T, int);
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
point* insert_root_elem(point*, int);
/*
������ ��������� � ����� ������
*/
point* insert_end_elem(point*, int);
/*
������� ��� ��������� ��������� �������� ������ �� ������
*/
template <typename T>
T scan_elem(T);

#endif
