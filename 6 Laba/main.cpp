#define _CRT_SECURE_NO_WARNINGS										// Отключение предупреждений

#include <iostream>
#include <cstdio>
#include <fstream>
#include <clocale>
#include "struct_func.h"

using namespace std;

struct patient{

	char name[2024];												// ФИО пациента
	char address[2024];												// Адрес пациента
	int medical_card;												// Номер мед.карты пациента
	int insurance_pol;												// Номер страхового полиса пациента

};

/*9. Структура "Пациент":
* - фамилия, имя, отчество;
* - домашний адрес;
* - номер медицинской карты;
* - номер страхового полиса.
* Удалить элемент с заданным номером медицинской карты, добавить 2 элемента в начало файла.*/
int main() {

	setlocale(LC_ALL, "Russian");									// Русский язык в консоли

	struct patient list;											// Инициализация структуры
	list.medical_card = 111;
	int num, quo, res;												// Переменные: номер мед. карты записи, которую нужно удалить; кол-во вводимых записей; кол-во удаленных записей
	char *file = "file.dat";										// Имя файла с записями
	char *temp_file = "temp_file.dat";								// Имя временного файла

	printf("Введите кол-во записей.\n");

	scanf("%d", &quo);
	getchar();														// Убирает символ новой строки из входного потока

    insert_file(file, list, quo);									// Запись в файл записей из потока

	printf("__________\n");
	
	while_read(file, list, quo);									// Вывод содержимого файла на экран
	
	printf("Введите номер мед. карты для удаления.\n");

    scanf("%d", &num);
    getchar();														// Убирает символ новой строки из входного потока

    res = while_reader(file, temp_file, list, num, quo);			 // Запись во временный файл неудаленных записей

    insert_newfile(file, temp_file, list, quo - res);				 // Очистка файла, запись в файл 2 новых записей из потока

	filecpy(file, temp_file, list, quo);							 // Копирование содержимого временного файла в главный файл и удаление временного файла

	printf("Результат:\n");
	
	while_read(file, list, quo+2-res);								 // Вывод содержимого файла

	system("pause");												 // Задержка консоли
	return 0;
}
