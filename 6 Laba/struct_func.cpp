#define _CRT_SECURE_NO_WARNINGS												// ���������� ��������������


#include <iostream>
#include <cstdio>
#include <fstream>
#include <clocale>
#include "struct_func.h"

using namespace std;

struct patient{ 

	char name[2024];														// ��� ��������
	char address[2024];														// ����� ��������
	int medical_card;														// ����� ����������� �����
	int insurance_pol;														// ����� ������

};



// ���������� temp_file �������� �� file �� ����������� ������� � ��������� num
int while_reader(char* file, char *temp_file, struct patient list, int num, int quo){
	int res = 0;
	FILE *f;
	FILE *m;
	if ((f = fopen(file, "rb")) == NULL) {									// ��������� ����
		printf("�� ���������� ������� ����.\n");
	}
	if ((m = fopen(temp_file, "wb")) == NULL) {								// ������� ����
		printf("�� ���������� ������� ����.\n");
	}

	int i = 0;																// ������� ������� ������� � �����

	while (!feof(f) && i < quo){											// ���� �� ����� ��������� ����� ����� � �� ����� ����������� ��������� ������
		fread(&list, sizeof(patient), 1, f);								// ��������� ��������� �� �����
		if (ferror(f)){
			printf("�� ���������� �������� ����.\n");
		}

		if (list.medical_card != num){										// ���� ����� ���, ����� �� ����� ��������� ��������
				if (fwrite(&list, sizeof (patient), 1, m) != 1){			// ���������� � ����
					printf("�� ���������� �������� � ����.\n");
				}
		}else{
			res++;															// ������� ���-�� ������� � ����������� num
		}
		i++;
	}
	fclose(m);
	fclose(f);																// ��������� �����

	return res;																// ���������� ���-�� ��������� �������
}



// ���������� ������ �� ����� � �������
void while_read(char *file, struct patient list, int quo){
	FILE *f;

	if ((f = fopen(file, "rb")) == NULL) {									// ��������� ����
		printf("�� ���������� ������� ����.\n");
	}

	int i = 0;

	while (!feof(f) && i < quo){											// ���� �� ����� ��������� ����� ����� � �� ����� ����������� ��������� ������
		
		if(fread(&list, sizeof(patient), 1, f)!= 1){						// ������ � ����
			printf("�� ���������� �������� ����.\n");
		}
		print_struct(list);
		i++;
	}
	fclose(f);
}



// ������� ��� ����������� ������
void filecpy(char *file_w, char *file_r, struct patient list, int quo)
{
	FILE *f;
	FILE *m;
	int i = 0;

	if ((f = fopen(file_w, "ab")) == NULL) {								// ��������� ����
		printf("�� ���������� ������� ����.\n");
	}
	if ((m = fopen(file_r, "rb")) == NULL) {								// ��������� ����
		printf("�� ���������� ������� ����.\n");
	}
	while (!feof(m) && i < quo){											// ���� �� ����� ��������� ����� ����� � �� ����� ����������� ��������� ������
		
		if (fread(&list, sizeof (patient), 1, m) != 1){						// ������ ����
			printf("�� ���������� �������� � ����.\n");
		}
		if (fwrite(&list, sizeof (patient), 1, f) != 1){					// ���������� � ����
			printf("�� ���������� �������� � ����.\n");
		}
		i++;
	}
		fclose(f);															// ��������� �����
		fclose(m);

		delete_f(file_r);													// ������� ��������� ����
}



// �������� �����
void delete_f(char *file_r){

	if (remove(file_r) != 0){
		printf("�� ���������� ������� ����.\n");
	}
}



// ������� �������� ����� file_w, � ������ � ���� 2 ����� ������� �� ������
void insert_newfile(char *file_w, char *file_r, struct patient list, int quo){

	FILE *f;
	if ((f = fopen(file_w, "wb")) == NULL) {								// ��������� ���� (�������)
		printf("�� ���������� ������� ����.\n");
	}

	for (int i = 0; i <= 1; i++) {											// 2 ������
		list = cin_get(list);												// �������� ������ �� ������
		if (fwrite(&list, sizeof (patient), 1, f) != 1){					// ���������� � ����
			printf("�� ���������� �������� � ����.\n");
		}
	}
	fclose(f);
}



// ������� ������ ���, ���� �� ������ � ����
void insert_file(char *file_w, struct patient list, int quo){

	FILE *f;
	if ((f = fopen(file_w, "wb")) == NULL) {							// ������� ����
		printf("�� ���������� ������� ����.\n");
	}

	for (int i = 0; i < quo; i++) {										// ���� �� ����� ��������� ����� ����� � �� ����� ����������� ��������� ������

		list = cin_get(list);											// �������� ������ �� ������

		if (fwrite(&list, sizeof (patient), 1, f) != 1){				// ���������� ������ � ����
			printf("�� ���������� �������� � ����.\n");
		}
	}
	fclose(f);															// ��������� ����
}



// ������� ���������� ������ �� ������
patient cin_get(struct patient list){
	printf("name=");

	gets(list.name);

	printf("address=");

	gets(list.address);

	printf("medical card=");

	scanf("%d", &list.medical_card);

	printf("insurance police=");

	scanf("%d", &list.insurance_pol);

	getchar();															// ������� ������ ����� ������ �� �������� ������

	return list;
}



// ������ ���������
void print_struct(struct patient list){

	printf("name: %s\n", list.name);

	printf("address: %s\n", list.address);

	printf("med_card: %d\n", list.medical_card);

	printf("polis: %d\n", list.insurance_pol);

	printf("_______\n");
}
