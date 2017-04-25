#define _CRT_SECURE_NO_WARNINGS										// Отключение предупреждений.
#include <iostream>
#include "RK_func.h"
#include <cstring>

using namespace std;

// Создание корневого элемента списка (инициализация)
point* make_point(int key)
{
	point *first, *pre, *p;

	first = NULL;
	pre = NULL;														 // Указатель на следующий и предыдущий элементы списка равны NULL

	p = new(point);													 // Создать корневой элемент списка

	p->key = key;
	p->next = first;												 // Присваивание соответствующих значений
	p->pre = pre;

	return p;														 // Возвращает последний элемент
}

//вставка элемента в двунаправленный список
point* insert_elem(point *p, int item)
{
	point *newitem = new(point);									 // Создание нового элемента списка

	newitem->key = item;											 // Присваивание значения элемента списка
	newitem->pre = p;												 // Предыдущий элемент равен текущему
	newitem->next = NULL;
	p->next = newitem;												 // Предыдующий элемент равен новому

	p = newitem;													 // Текущий элемент равен новому
	return p;														 // Возвращает последний элемент
}

// Печать списка
void listprint(point *p)
{
	if (p->key == -1)												// Если список не существует, то выводим соответствующее сообщение
		printf("Нет совпадений.\n");
	else {

		while (p != NULL)											// Перебор всех элементов списка в соответствии с их количеством
		{
			if (p->key != -1)										// Если текущий элемент списка не равен нулевому значению.
				printf("Совпадение с %d\n", p->key);

			p = p->pre;												// Следующий элемент списка
		}
	}
}

// Печать строки.
void print_str(char *mass, int mass_l)
{
	for (int i = 0; i < mass_l; i++)
	{
		printf("%c", mass[i]);
	}
	printf("\n");
}

// Вычисление хеша для подстроки в строке с start_index в кол-ве quantity символов.
unsigned long long int RK_hash(char *str, int start_index, int quantity)
{
	unsigned long long int result = 0;

	/* Перебор символов подстроки и проедставление их в числовом виде. 
	Перевод числового варианта символа в систему счисления с основанием 13.
	*/
	for (int i = start_index; i < start_index + quantity; i++)
		result += (unsigned long long int)((int)(str[i]) * pow(13, i - start_index));

	return result;
}

// Дополнительная проверка совпадения строки и подстроки.
bool RK_check(char *str, char *templa, int num, int templa_l)
{
	for (int i = num; i < templa_l; i++)												// Сравниваются элементы строки и подстроки.
	{
		if (str[i] != templa[i - num])													// Если какие-то элементы не совпали, то возвращаем ложь, иначе - истину.
			return false;
	}
	return true;
}

// Поиск Рабина - Карпа подстроки в строке, строка str длиной в str_l символов и подстрока templa длиной в templa_l символов.
void RK_search(char *str, char *templa, int str_l, int templa_l)
{
	point *sovp = make_point(-1);														// Создание линейного списка (корневой элемент).

	unsigned long long int last_hash = RK_hash(str, 0, templa_l);						// Вычисление хеша от первой подстроки строки, длины templa_l.
	unsigned long long int templa_hash = RK_hash(templa, 0, templa_l);					// Вычисление хеша от шаблона.

	for (int i = 0; i + templa_l <= str_l; i++)											// Перебор символов строки для выделения из строки подстроки.
	{
		// Если текущий хеш подстроки равен хешу шаблона, то, предположительно, подстрока равна шаблону.
		if (last_hash == templa_hash)
			if(RK_check(str, templa, i, templa_l) == true)
				sovp = insert_elem(sovp, i);											// Добавляем в список индекс массива строки, с которого началось вхождение.

		last_hash -= (unsigned long long int)(RK_hash(str, i, 1));						// Вычитаем хеш уходящего из подстроки символа.
		last_hash /= 13;																// Смещаем степени 13 для добавления приходящего символа.
		// Добавляем хеш приходящего символа из строки.
		last_hash += (unsigned long long int)(RK_hash(str, i + templa_l, 1) * pow(13, templa_l - 1));
	}

	listprint(sovp);																	// Печать списка.

	delete sovp;																		// Удаление списка
}

// Приведение строки в нижний регистр для регистронезависимого поиска.
void lower(char *mass, int mass_l)
{
	for (int i = 0; i < mass_l; i++)
	{
		mass[i] = tolower(mass[i]);
	}
}

// Считывание текстового файла построчно и вызов функции поиска для каждой строки.
void RFile(char *filename, char *templa, int templa_l)
{
	FILE *fp;
	int mass_l;
	fp = fopen(filename, "r+");										// Открытие файла в режиме чтения.
	if (fp == NULL)													// Предупрпеждение, если файл не открывается.
	{
		printf("Файл не открывается.\n");
	}
	else
	{
		while (!feof(fp))											// Пока не будет достигнут конец файла.
		{
			char *mass = new char[255];								// Массив для строки.
			fgets(mass, 255, fp);									// Извлечение строки из файла, максимальной длины в 255 символов.
			mass_l = strlen(mass);									// Длина строки.

			lower(mass, mass_l);									// Приведение строк в нижний регистр.
			lower(templa, templa_l);

			print_str(mass, mass_l);								// Печать текущей строки.
			RK_search(mass, templa, mass_l, templa_l);
			delete[] mass;											// Удаление строки.
		}
		fclose(fp);													// Закрытие файла.
	}
														
}