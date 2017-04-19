/*
��������� ������ ��� ������ ����������.
*/
struct point
{
	int key;									 // ���������� �������� ������
	point* next;								 // ��������� �� ��������� ������� ������
	point* pre;									 // ��������� �� ���������� ������� ������
};
/*
�������� ��������� �������� ������, ���������� �������� �������
*/
point* make_point(int key);
/*
������� �������� � ����� ������, ���������� ��������� �� ��������� ������� ������
*/
point* insert_elem(point *p, int item);
/*
������ ������
*/
void listprint(point *p);
/*
������ ������.
*/
void print_str(char *mass, int mass_l);
/*
������� ����������� ������� ��� ������ ����� ��������. ���� ������ ����� �������� �� ������ � ������, ��
�� ����� ����� ����� �������. � ������ ������� ����� ����� ���������� �� �������������� ������� �������
�� ������� �������.
*/
void Shift(char *templa, int templa_l, int *alphabet, int *shift, int);
/*
����� �������� ��� ������. ���� ������ ����� ��������� � ������, �� �������� ������� � ��������, ������ 
��������� ������������� ������� ������� ������������� �������� 1.
*/
int alphabetcnt(char *mass, int mass_l, int *alphabet);
/*
����� ������ - ���� ��������� � ������.
����� ��������� � ������ �������������� � ����� �������, ������������ ���������
������ �������, ���� �� ��������� � ��������������� ��������, �� ��������� ���
������� � ����������� � ������ �������. ���� ��� ������� ������� - ����������
���������� � �������� ������ �� ��� ��� �����, ����� �������� ������ �� ������
������ ���������������� ������� �� ������.
*/
int BM_search(char *mass, int mass_l, char *templa, int templa_l);
/*
���������� ���������� ����� ��������� � ����� ������� ������ ��� ������ ������.
*/
void RFile(char *filename, char *templa, int templa_l);