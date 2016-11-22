#define _CRT_SECURE_NO_WARNINGS												// Отключение предупреждений


#include <iostream>
#include <cstdio>
#include <fstream>
#include <clocale>
#include "struct_func.h"

using namespace std;

struct patient{ 

	char name[2024];														// ФИО пациента
	char address[2024];														// Адрес пациента
	int medical_card;														// Номер медицинской карты
	int insurance_pol;														// Номер полиса

};



// Заполнение temp_file записями из file за исключением записей с указанным num
int while_reader(char* file, char *temp_file, struct patient list, int num, int quo){
	int res = 0;
	FILE *f;
	FILE *m;
	if ((f = fopen(file, "rb")) == NULL) {									// Открываем файл
		printf("Не получается открыть файл.\n");
	}
	if ((m = fopen(temp_file, "wb")) == NULL) {								// Создаем файл
		printf("Не получается открыть файл.\n");
	}

	int i = 0;																// Счетчик текущих записей в файле

	while (!feof(f) && i < quo){											// Пока не будет достигнут конец файла и не будет проработана последняя запись
		fread(&list, sizeof(patient), 1, f);								// Считываем структуру из файла
		if (ferror(f)){
			printf("Не получается прочесть файл.\n");
		}

		if (list.medical_card != num){										// Если номер мед, карты не равен заданному значению
				if (fwrite(&list, sizeof (patient), 1, m) != 1){			// Записываем в файл
					printf("Не получается записать в файл.\n");
				}
		}else{
			res++;															// Подсчет кол-ва записей с совпадающим num
		}
		i++;
	}
	fclose(m);
	fclose(f);																// Закрываем файлы

	return res;																// Возвращает кол-во удаленных записей
}



// Считывание данных из файла в консоль
void while_read(char *file, struct patient list, int quo){
	FILE *f;

	if ((f = fopen(file, "rb")) == NULL) {									// Открываем файл
		printf("Не получается открыть файл.\n");
	}

	int i = 0;

	while (!feof(f) && i < quo){											// Пока не будет достигнут конец файла и не будет проработана последняя запись
		
		if(fread(&list, sizeof(patient), 1, f)!= 1){						// Запись в файл
			printf("Не получается прочесть файл.\n");
		}
		print_struct(list);
		i++;
	}
	fclose(f);
}



// Функция для копирования файлов
void filecpy(char *file_w, char *file_r, struct patient list, int quo)
{
	FILE *f;
	FILE *m;
	int i = 0;

	if ((f = fopen(file_w, "ab")) == NULL) {								// Открываем файл
		printf("Не получается открыть файл.\n");
	}
	if ((m = fopen(file_r, "rb")) == NULL) {								// Открываем файл
		printf("Не получается открыть файл.\n");
	}
	while (!feof(m) && i < quo){											// Пока не будет достигнут конец файла и не будет проработана последняя запись
		
		if (fread(&list, sizeof (patient), 1, m) != 1){						// Читаем файл
			printf("Не получается записать в файл.\n");
		}
		if (fwrite(&list, sizeof (patient), 1, f) != 1){					// Записываем в файл
			printf("Не получается записать в файл.\n");
		}
		i++;
	}
		fclose(f);															// Закрываем файлы
		fclose(m);

		delete_f(file_r);													// Удаляем временный файл
}



// Удаление файла
void delete_f(char *file_r){

	if (remove(file_r) != 0){
		printf("Не получается удалить файл.\n");
	}
}



// Функция очищения файла file_w, и записи в него 2 новых записей из потока
void insert_newfile(char *file_w, char *file_r, struct patient list, int quo){

	FILE *f;
	if ((f = fopen(file_w, "wb")) == NULL) {								// Открываем файл (очищаем)
		printf("Не получается открыть файл.\n");
	}

	for (int i = 0; i <= 1; i++) {											// 2 записи
		list = cin_get(list);												// Получаем данные из потока
		if (fwrite(&list, sizeof (patient), 1, f) != 1){					// Записываем в файл
			printf("Не получается записать в файл.\n");
		}
	}
	fclose(f);
}



// Функция записи мед, карт из потока в файл
void insert_file(char *file_w, struct patient list, int quo){

	FILE *f;
	if ((f = fopen(file_w, "wb")) == NULL) {							// Создаем файл
		printf("Не получается открыть файл.\n");
	}

	for (int i = 0; i < quo; i++) {										// Пока не будет достигнут конец файла и не будет проработана последняя запись

		list = cin_get(list);											// Получаем данные из потока

		if (fwrite(&list, sizeof (patient), 1, f) != 1){				// Записываем данные в файл
			printf("Не получается записать в файл.\n");
		}
	}
	fclose(f);															// Закрываем файл
}



// Функция считывания данных из потока
patient cin_get(struct patient list){
	printf("name=");

	gets(list.name);

	printf("address=");

	gets(list.address);

	printf("medical card=");

	scanf("%d", &list.medical_card);

	printf("insurance police=");

	scanf("%d", &list.insurance_pol);

	getchar();															// Убирает символ новой строки из входного потока

	return list;
}



// Печать структуры
void print_struct(struct patient list){

	printf("name: %s\n", list.name);

	printf("address: %s\n", list.address);

	printf("med_card: %d\n", list.medical_card);

	printf("polis: %d\n", list.insurance_pol);

	printf("_______\n");
}
