#pragma once
#include <iostream>
#include <cstring>
#include "common_func.h"

using namespace std;

template <typename T>

// Двусвязный список для работы с очередью
struct point
{
	T* key;														// Указатель на содержание элемента списка

	point<T> *next;												// Указатель на следующий элемент списка
	point<T> *pre;												// Указатель на предыдущий элемент списка
};

// ---------------------------------------------------------
// Создание корневого элемента списка (инициализация)
template <typename T>
point<T>* make_point_Q(T key)
{
	point<T> *first, *pre, *p;

	// Для записи значения в указатель создается динамический массив из одного элемента
	T *temp = new T(1);
	temp[0] = key;												// Ему присваивается ключевое значение

	first = NULL; // Указатель на следующий и предыдущий элементы списка равны NULL
	pre = NULL;													// Указатель на следующий и предыдущий элементы списка равны NULL

	p = new(point<T>);											// Создать корневой элемент списка

	p->key = temp;												// Указатель на ключевой элемент


	p->next = first;											// Присваивание соответствующих значений
	p->pre = pre;

	delete first, pre;


	return p;													// Возвращает указатель на последний элемент списка
}
// Перегруженная функция для работы с массивом
template <typename T>
point<T>* make_point_Q(T *key)
{
	point<T> *first, *pre, *p;


	first = NULL;// Указатель на следующий и предыдущий элементы списка равны NULL
	pre = NULL;														 // Указатель на следующий и предыдущий элементы списка равны NULL

	p = new(point<T>);													 // Создать корневой элемент списка

	p->key = key; // Указатель на ключевой элемент


	p->next = first;												 // Присваивание соответствующих значений
	p->pre = pre;

	delete first, pre;


	return p;														 // Возвращает укапоследний элемент
}
// ---------------------------------------------------------

// ---------------------------------------------------------
//вставка элемента в двунаправленный список
template <typename T>
point<T>* insert_elem_Q(point<T> *p, T item)
{
	point<T> *new_item = new(point<T>);								// Создание нового элемента списка

	// Для записи значения в указатель создается динамический массив из одного элемента
	T *temp = new T(1);												 
	temp[0] = item;													 // Ему присваивается ключевое значение

	new_item->key = temp;											 // Указатель на ключевой элемент
	new_item->pre = p;												 // Предыдущий элемент равен текущему


	p->next = new_item;												 // Предыдующий элемент равен новому

	p = new_item;													 // Текущий элемент равен новому


	return p;														 // Возвращает последний элемент
}
// Перегруженная функция для работы с массивом
template <typename T>
point<T>* insert_elem_Q(point<T> *p, T *str)
{
	point<T> *new_item = new(point<T>);							    // Создание нового элемента списка

	new_item->key = str;											// Присваивание значения элемента списка


	new_item->pre = p;												// Предыдущий элемент равен текущему
	p->next = new_item;												// Предыдующий элемент равен новому

	p = new_item;													// Текущий элемент равен новому


	return p;														// Возвращает последний элемент
}
// ---------------------------------------------------------


// Удаление элемента списка
template <typename T>
point<T>* delete_point_Q(point<T> *list, point<T> *root)
{

	point<T> *root1 = root;											// Временный элемент для удаления


	root1 = root;
	root = root->next;												// Записываем след элемент списка как текущий

	delete root1;													// Удаление элемента списка через временный элемент

	root->pre = NULL;												// Объявляем элемент корневым


	return root;													// Возвращает корневой элемент
}

// ---------------------------------------------------------
// Печать списка
template <typename T>
void listprint_Q(point<T> *p)
{
	// Временная структура для сохранения указателя на последний элемент в списке
	point<T> *temp = p;


	if (temp == NULL)													 // Если список не существует, то выводим соответствующее сообщение
		cout << "Список пуст.";
	else {
		while (temp != NULL)											 // Перебор всех элементов списка до конца
		{
			// Вывод элемента ключевого поля структуры, заданного как динамический массив из одного элемента
			cout << temp->key[0] << " ";


			temp = temp->pre;								      		 // Следующий элемент списка
		}
	}
	cout << endl;


	delete temp; // Удаление временной струкуры
}
// Перегруженная функция для работы с массивом
template <typename T>
void listprint_Q(point<T> *p, int flag)
{	// Временная структура для сохранения указателя на последний элемент в списке
	point<T> *temp = p;


	if (temp == NULL)													 // Если список не существует, то выводим соответствующее сообщение
		cout << "Список пуст.";
	else {
		while (temp != NULL)											 // Перебор всех элементов списка до конца
		{
			for (int i = 0; i < strlen(temp->key); i++)					 // Вывод массива ключевого значения структуры в консоль
				cout << temp->key[i];


			cout << endl;

			temp = temp->pre;								      		 // Следующий элемент списка
		}
	}
	cout << endl;


	delete temp; // Удаление временной струкуры
}
// ---------------------------------------------------------

// Удалить элементы заданное кол-во элементов списка
template <typename T>
point<T>* delete_elem_Q(point<T> *p, point<T> *root, int quantity)
{
	// Временная структура для сохранения указателя на последний элемент в списке
	point<T> *temp = p;
	int i = 0;															// Счетчик удаленных элементов

	// Пока не будет удалено нужное кол-во элементов и не закончится список
	while (i < quantity && temp != NULL) {						
		if (i > 0)														// Если не первый удаляемый элемент
			temp = temp->pre;											// Переходим к предыдущему элементу
		root = delete_point_Q<T>(temp, root);							// Удаление элемента списка
		i++;															// Увеличение счетчика удаленных элементов списка
		}

	return root;														// Возвращает корневой элемент списка
}

// ---------------------------------------------------------
// Заполнение списка элементами
template <typename T>
point<T> *fill_queue(point<T> *list, int quantity)
{
	T in_val;															// Элемент, введенный пользователем
	int counter = 0;													// Счетчик кол-ва введенных элементов
	while (counter < quantity - 1)										// Пока кол-во введенных элементов меньше заданного
	{
		in_val = scan_elem<T>();										// Получаем элемент от пользователя
		list = insert_elem_Q<T>(list, in_val);							// Запись элемента в очередь
		counter++;														// Увеличение счетчика кол-ва введенных элементов
	}
	return list;														// Возвращает указатель на конец списка
}
// Перегруженная функция для работы с массивом
template <typename T>
point<T> *fill_queue(point<T> *list, int quantity, int flag)
{
	int counter = 0;													// Счетчик кол-ва введенных элементов

	while (counter < quantity - 1)										// Пока кол-во введенных элементов меньше заданного
	{
		T *str = new T(255);											// Создание динамического массива
		str = scan_elem<T>(str);										// Получаем массив от пользователя


		list = insert_elem_Q<T>(list, str);								// Запись элемента в очередь
		counter++;														// Увеличение счетчика кол-ва введенных элементов
	}
	return list;														// Возвращает указатель на конец списка
}
// ---------------------------------------------------------

// ---------------------------------------------------------
// Основная функция работы с очередью (создание, удаление элементов, вывод)
template <typename T>
bool Queue(point<T> *list, point<T> *root)
{
	int counter = 0;													// Кол-во элементов в списке
	int del_q = 0;														// Кол-во удаляемых элементов из списка
	T in_val = NULL;													// Корневой элемент списка

	for_input_params<T> *help_struct = new(for_input_params<T>);		// Вспомогательная структура
	input_params<T>(help_struct);										// Пользовательские параметры


	counter = help_struct->counter;										// Извлечение пользовательских данных, заданных в структуре
	del_q = help_struct->del_q;
	in_val = help_struct->in_val;

	if (counter == 0 || del_q == 0 || del_q > counter)					// При некоррнектных данных, заданных пользователем
		return false;													// Выход из программы

	list = make_point_Q<T>(in_val);										// Создание корневого элемента списка
	root = list;														// Сохранение корня списка


	list = fill_queue<T>(list, counter);								// Заполнение очереди

	root = delete_elem_Q<T>(list, root, del_q);							// Удаление заданного кол-ва элементов 

	listprint_Q<T>(list);												// Печать списка в консоль


	delete help_struct;													// Удаление вспомогательной структуры

	return true;														// Если все нормально - возвращает true
}

template <typename T>
bool Queue(point<T> *list, point<T> *root, char *str)
{
	int counter = 0;													// Кол-во элементов в списке
	int del_q = 0;														// Кол-во удаляемых элементов из списка


	for_input_params<T> *help_struct = new(for_input_params<T>);		// Вспомогательная структура
	str = input_params<T>(help_struct, str);							// Пользовательские параметры

	counter = help_struct->counter;										// Извлечение пользовательских данных, заданных из структуры
	del_q = help_struct->del_q;

	if (counter == 0 || del_q == 0 || del_q > counter)					// При некоррнектных данных, заданных пользователем
		return false;													// Выход из функции


	list = make_point_Q<T>(str);										// Создание корневого элемента списка
	root = list;														// Сохранение корня списка

	list = fill_queue<T>(list, counter, 1);								// Заполнение очереди

    root = delete_elem_Q<T>(list, root, del_q);							// Удаление заданного кол-ва элементов 

	listprint_Q<T>(list, 1);											// Печать списка в консоль

	delete help_struct;													// Удаление вспомогательной структуры

	return true;														// Если все нормально - возвращает true
}
// ---------------------------------------------------------

// ---------------------------------------------------------
// Функция создает структуры для работы с очередью и вызывает основную функцию работы с очередью
template <typename T>
void Start_Queue()
{
	point<T> *list = 0;											// Структуры для конца списка и корня списка
	point<T> *root = 0;
	// Флаг для завершения работы программы при неверных пользовательских данных
	bool flag;

	flag = Queue<T>(list, root);								// Вызов основной функции для работы с очередью

	delete list;												// Удаление динамических структур
	delete root;
}

// Функция для работы с массивом
template <typename T>
void Start_Queue_mass()
{
	point<T> *list = 0;											// Структуры для конца списка и корня списка
	point<T> *root = 0;
	char *str = new char(255);									// Массив данных, задаваемых пользователем
	// Флаг для завершения работы программы при неверных пользовательских данных
	bool flag;

	flag = Queue<T>(list, root, str);							// Вызов основной функции для работы с очередью

	delete list;												// Удаление динамических структур
	delete root;
}
// ---------------------------------------------------------