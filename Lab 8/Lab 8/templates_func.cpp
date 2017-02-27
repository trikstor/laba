#define _CRT_SECURE_NO_WARNINGS								         // Отключение предупреждений для fopen

#include <iostream>
#include <clocale>
#include "templates_func.h"

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

	delete first, pre;
	return p;														 // Возвращает последний элемент
}

//вставка элемента в двунаправленный список
point* insert_elem(point *p, T item)
{
	point *new_item = new(point);									 // Создание нового элемента списка

	new_item->key = item;											 // Присваивание значения элемента списка
	new_item->pre = p;												 // Предыдущий элемент равен текущему
	p->next = new_item;												 // Предыдующий элемент равен новому

	p = new_item;													 // Текущий элемент равен новому

	return p;														 // Возвращает последний элемент
}

// Удаление элемента списка
point* delete_point(point *p, point *root) {
	point *pre_elem, *next_elem;

	if (p == root)													 // Если корневой элемент
	{
		root = root->next;										     // Для следующего элемента указатель на текущий не существует
		root->pre = NULL;
	}
	else
	{
		pre_elem = p->pre;											 // Следующий и предыдущий элементы
		next_elem = p->next;

		pre_elem->next = p->next;									 // Меняем указатели
		next_elem->pre = p->pre;
	}

	return root;													// Возвращает корневой элемент
}

// Печать списка
void listprint(point *p, int elems)
{
	if (p == NULL)													 // Если список не существует, то выводим соответствующее сообщение
		cout << "Список пуст.";
	else {
		int cnt = 0;
		while (cnt < elems)											 // Перебор всех элементов списка в соответствии с их количеством
		{
			printf("! %d !", p->key);
			p = p->next;								      		 // Следующий элемент списка
			cnt++;
		}
	}
	cout << endl;
}

// Удалить список
point* delete_all(point *p)
{
	point *temp = NULL;												 // Временная структура

	while (p != NULL)												 // Пока список не закончится
	{
		temp = p->pre;										         // Временной структуре присваивается предыдущее значение списка
		delete p;
		p = temp;													 // Удаляемому элементу списка присваивается ранее сохраненный предыдущий элемент списка
	}

	delete temp;
	return p;
}

// Удалить элементы заданное кол-во элементов списка до заданного значения
point* delete_elem(point *p, point *root, T del_num, int quantity) {

	int security = 0;												 // Индикатор заданного значения del_num
	int i = 0;														 // Счетчик удаленных элементов

	do {
		if (security == 1 && i < quantity) {							 // Если значение del_num найдено и еще не удалено заданное кол-во элементов
			root = delete_point(p, root);
			i++;
		}

		if (p->key == del_num) {									    // Если значение текущего элемента равно заданному
			security = 1;
		}

		p = p->pre;												   // Предыдущий элемент

	} while (p != NULL);

	return root;												   // Возвращает корневой элемент списка
}

//Записать список в файл
void in_file(point *p, char *filename, int elems) {
	FILE *fs;
	int n = 0;
	fs = fopen(filename, "wb");
	if (fs != NULL) {												 // Проверка на наличие элемента в файле
		while (n < elems)											 // Перечисляем все элементы списка с начала
		{
			fwrite(p, sizeof(point), 1, fs);
			p = p->next;											 // Следующий элемент списка
			n++;
		}
	}
	fclose(fs);
}

// Запись дополнительных элементов в начало файла
point* insert_root_elem(point *root, int elems)
{
	point *temp_list;

	for (int i = 0; i < elems; i++)									 // Перечисление дополнительных элементов
	{
		temp_list = new(point);										 // Новый элемент списка
		temp_list->pre = NULL;
		temp_list->key = scan_elem();
		root->pre = temp_list;										 // Предыдущий элемент для корневого, это новый элемент списка
		temp_list->next = root;										 // Указатель к корневому элементу
		root = temp_list;											 // Новый корневой элемент списка
	}

	return root;													 // Возвращает корневой элемент
}

// Извлечь список из файла
point* from_file(char * filename)
{

	FILE *fs;
	point *strct, *curr_strct, *p;
	curr_strct = make_point(0);										 // Инициализация временной структуры для считывания в нее ключевого поля
	fs = fopen(filename, "rb");

	fread(curr_strct, sizeof(point), 1, fs);
	strct = make_point(curr_strct->key);							 // Корневой элемент
	p = strct;														 // Корневой элемент переносится в структуру p
	if (fs != NULL) {												 // Проверка на наличие элемента в файле
		while (!feof(fs))											 // Пока файл не закончился
		{
			fread(curr_strct, sizeof(point), 1, fs);
			strct = insert_elem(strct, curr_strct->key);		     // Вставить следующий элемент
		}
	}
	fclose(fs);
	delete curr_strct, strct;
	return p;														 // Возвращает корневой элемент
}

// Запись элементов в конец списка
point* insert_end_elem(point *p, int elems) {
	int in_val;

	for (int n = 1; n < elems; n++) {								 // Перебор элементов
		in_val = scan_elem();										 // Получение элемента
		p = insert_elem(p, in_val);								   	 // Вставка следующего элемента списка со значением, равным номеру элемента; присваивание p новой структуры списка
	}

	return p;
}

// Функция для получения ключевого значения списка из потока
template <typename T>
T scan_elem(T val) {
	T in_val;
	cout << "Введите следующий элемент " << endl;
	cin >> in_val;

	return in_val;
}
