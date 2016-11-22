#define _CRT_SECURE_NO_WARNINGS										// ���������� ��������������

#include <iostream>
#include <cstdio>
#include <fstream>
#include <clocale>
#include "struct_func.h"

using namespace std;

struct patient{

	char name[2024];												// ��� ��������
	char address[2024];												// ����� ��������
	int medical_card;												// ����� ���.����� ��������
	int insurance_pol;												// ����� ���������� ������ ��������

};

/*9. ��������� "�������":
* - �������, ���, ��������;
* - �������� �����;
* - ����� ����������� �����;
* - ����� ���������� ������.
* ������� ������� � �������� ������� ����������� �����, �������� 2 �������� � ������ �����.*/
int main() {

	setlocale(LC_ALL, "Russian");									// ������� ���� � �������

	struct patient list;											// ������������� ���������
	list.medical_card = 111;
	int num, quo, res;												// ����������: ����� ���. ����� ������, ������� ����� �������; ���-�� �������� �������; ���-�� ��������� �������
	char *file = "file.dat";										// ��� ����� � ��������
	char *temp_file = "temp_file.dat";								// ��� ���������� �����

	printf("������� ���-�� �������.\n");

	scanf("%d", &quo);
	getchar();														// ������� ������ ����� ������ �� �������� ������

    insert_file(file, list, quo);									// ������ � ���� ������� �� ������

	printf("__________\n");
	
	while_read(file, list, quo);									// ����� ����������� ����� �� �����
	
	printf("������� ����� ���. ����� ��� ��������.\n");

    scanf("%d", &num);
    getchar();														// ������� ������ ����� ������ �� �������� ������

    res = while_reader(file, temp_file, list, num, quo);			 // ������ �� ��������� ���� ����������� �������

    insert_newfile(file, temp_file, list, quo - res);				 // ������� �����, ������ � ���� 2 ����� ������� �� ������

	filecpy(file, temp_file, list, quo);							 // ����������� ����������� ���������� ����� � ������� ���� � �������� ���������� �����

	printf("���������:\n");
	
	while_read(file, list, quo+2-res);								 // ����� ����������� �����

	system("pause");												 // �������� �������
	return 0;
}
