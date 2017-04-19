#define _CRT_SECURE_NO_WARNINGS										// Отключение предупреждений.
#include <iostream>
#include "BM_func.h"
#include <cstring>

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
	else{

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

// Функция определения сдвигов для каждой буквы алфавита.
void Shift(char *templa, int templa_l, int *alphabet, int *shift, int counter)
{
	int flag = 0;													// Флаг, указывающий на наличие данного символа в таблице сдвигов.
	int count = 0;													// Счетчик сдвига для определенного символа.

	for (int i = 0; i < templa_l; i++)								// Перебор массива шаблона.
	{
		if (shift[(int)templa[i]] >= 0)								// Если данный символ уже есть в таблице сдвигов.
			flag = 1;												// Изменяем флаг, чтобы не перезаписывать сдвиг для данного символа.

		if (flag == 0)												// Если такого символа еще нет в таблице сдвигов.
		{
			for (int n = templa_l - 2; n >= 0; n--)					// Ищем совпадение с предпоследнего символа строки шаблона.
			{
				count++;											// Подсчет сдвига.
				if (templa[i] == templa[n] && count > 0)			// Если нашли первое совпадение, то засчитываем сдвиг.
				{
					shift[(int)templa[i]] = count;
					count = -255;									// Присваиваем значение, препятствующее выполненю условия для перезаписи.
				}
			}
		}
		count = 0;													// Обнуляем сдвиг.
		flag = 0;													// Обнуляем флаг.
	}
	// Присваиваем ненайденным символам в шаблоне относительно алфавита, сдвиг, равный длине шаблона.
	for (int i = 0; i < 255; i++)
	{
		if (alphabet[i] == 1 && shift[i] < 0)
		{
			shift[i] = templa_l;
		}
	}
}

// Приведение строки в нижний регистр для регистронезависимого поиска.
void lower(char *mass, int mass_l)
{
	for (int i = 0; i < mass_l; i++)
	{
		mass[i] = tolower(mass[i]);
	}
}

// Вычисление алфавита для строки.
int alphabetcnt(char *mass, int mass_l, int *alphabet)
{
	int counter = 0;												// Счетчик кол-ва бука в алфавите.
	for (int i = mass_l - 1; i >= 0; i--)
	{
		if (alphabet[(int)mass[i]] != 1)							// Если такой буквы еще не было в алфавите.
		{
			// Присвоение элементу массива 1 с числовым индексом, эквивалентным букве алфавита.
			alphabet[(int)mass[i]] = 1;
			counter++;
		}
	}
	return counter;
}

// Поиск Бойера - Мура подстроки в строке.
int BM_search(char *mass, int mass_l, char *templa, int templa_l)
{
	point *sovp = make_point(-1);									// Создание корня двунаправленного списка.

	int *shift = new int[255];										// Массив сдвигов.
	int *alphabet = new int[255];									// Массив алфавита.

	int word;														// Длина алфавита.
	int sign = templa_l - 1;										// Индекс расстоняия от начала строки, изначально расстояниен равно длине шаблона.
	int sovpad = 0;													// Кол-во сдвиг на текущей позиции.
	int flag = 0;													// Флаг наличия полного совпадения.

	word = alphabetcnt(mass, mass_l, alphabet);						// Вычисление алфавита для строки.
	Shift(templa, templa_l, alphabet, shift, word);					// Выичслениие таблицы сдвигов для строки.
	while (sign < mass_l)											// Пока не будет достигнут конец строки.
	{

		if (mass[sign] == templa[templa_l - 1])						// Если последний символ шаблона равен соответствующему символу строки.
		{
			for (int n = 0; n < templa_l; n++)						// Обратный ход по подстроке, равной длинне шаблона.
			{
				if (mass[sign - n] != templa[templa_l - n - 1])		// Если есть несовпадение.
				{
					if (flag != 1) {
						sovpad = shift[(int)mass[sign - n]];		// Сдвиг, соответствующий несовпавшему символу строки.
					}
					flag = 1;										// Меняем флаг, чтобы избежать перезаписи.
				}
			}

			if (flag == 0)											// Если все символы совпали, то засчитываем совпадение.
				sovp = insert_elem(sovp, sign - templa_l + 1);		// Добавление элемента в список.

			flag = 0;												// Обенуляем флаг.
		}
		else
		{
			// Если первый же символ не совпал, то сдвиг соответствует несовпавшему символу строки.
			sovpad = shift[(int)mass[sign]];
		}

		if (sovpad == 0) {											// Защита от зацикливания.
			sovpad++;
		}

		sign += sovpad;												// Увеличиваем расстояние от начала строки на сдвиг.
	}

	listprint(sovp);												// Печать списка с совпадениями.

	delete[] shift;													// Удаление динамических массивов.
	delete[] alphabet;
	delete sovp;

	return 0;
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
			BM_search(mass, mass_l, templa, templa_l);				// Поиск подстроки в строке.
			delete[] mass;											// Удаление строки.
		}
	}
	fclose(fp);														// Закрытие файла.
}