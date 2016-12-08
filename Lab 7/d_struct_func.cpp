#define _CRT_SECURE_NO_WARNINGS		

#include <iostream>
#include <clocale>
#include "d_struct_func.h"

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

//вставка элемента с заданным номером в двунаправленный список
point* insert_elem(point *p, int item)
{
	point *newitem = new(point);									 // Создание нового элемента списка

	newitem->key = item;											 // Присваивание значения элемента списка
	newitem->pre = p;												 // Предыдущий элемент равен текущему
	p->next = newitem;												 // Предыдующий элемент равен новому

	p = newitem;													 // Текущий элемент равен новому

	return p;														 // Возвращает последний элемент
}

// Удаление элемента списка
point* delete_point(point *p, point *root){
	point *pre_elem, *next_elem;

	if (p == root)													 // Если корневой элемент
	{
		root = root->next;
		root->pre = NULL;
	}
	else
	{
		pre_elem = p->pre;											 // Следующий и предыдущий элементы
		next_elem = p->next;

		pre_elem->next = p->next;									 // Меняем указатели
		next_elem->pre = p->pre;
		free(p);
	}
	return root;
}

// Печать списка
void listprint(point *p, int elems)
{
	point *temp = p;												 // Временная структура
	if (p == NULL)													 // Если список не существует, то выводим соответствующее сообщение
		cout << "Список пуст.";
	else{
		int cnt = 0;
		while (cnt < elems)											 // Перебор всех элементов списка в соответствии с их количеством
		{
			printf("! %d !", temp->key);
			temp = temp->next;										 // Следующий элемент списка
			cnt++;
		}
	}
	cout << endl;
}

// Удалить список
point* delete_all(point *p)
{
	while (p != NULL)												 // Пока список не закончится
	{
		point *temp = p->pre;										 // Временной структуре присваивается следующее значение списка
		delete p; 
		p = temp;													 // Удаляемому элементу списка присваивается ранее сохраненный следующий элемент списка
	}
	return p;
}

// Удалить элементы заданное кол-во элементов списка до заданного значения
point* delete_elem(point *p, point *root, int del_num, int quantity){
	int security = 0;												 // Индикатор заданного значения del_num
	int i = 0;														 // Счетчик удаленных элементов

	do {
		if (security == 1 && i < quantity){							 // Если значение del_num найдено и еще не удалено заданное кол-во элементов
			root = delete_point(p, root);
			i++;
		}

			if (p->key == del_num){									 // Если значение текущего элемента равно заданному
				security = 1;
			}

		p = p->pre;

	} while (p != NULL);
	return root;
}

//Записать список в файл
void in_file(point *p, char *filename, int elems){
	FILE *fs;
	int n = 0;
	fs = fopen(filename, "wb");
	if (fs != NULL){												 // Проверка на наличие элемента в файле
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
point *insert_root_elem(point *p, int elems)
{
	point *temp_list;
	point *root;
	root = p;														 // Сохранение корневого элемента в новой структуре
	for (int i = 0; i < elems; i++)									 // Перечисление дополнительных элементов
	{
		temp_list = new(point);										 // Новый элемент списка
		temp_list->pre = NULL;
		temp_list->key = i;
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
	if (fs != NULL){												 // Проверка на наличие элемента в файле
		while (!feof(fs))											 // Пока файл не закончился
		{
				fread(curr_strct, sizeof(point), 1, fs);
				strct = insert_elem(strct, curr_strct->key);		 // Вставить следующий элемент
		}
	}
	fclose(fs);

	return p;														 // Возвращает корневой элемент
}
