#pragma once
#include <iostream>

using namespace std;

// Структура для хранения заданных пользователем параметров.
template <typename T>
struct for_input_params
{
	T in_val;													// Корневой элемент списка
	int counter;												// Кол-во элементов в списке
	int del_q;													// Кол-во удаляемых элементов списка
};

// ---------------------------------------------------------
// Функция для получения ключевого значения списка из потока
template <typename T>
T scan_elem()
{
	T in_val;
	cout << "Введите следующий элемент " << endl;
	cin >> in_val;


	return in_val;
}

template <typename T>
T *scan_elem(T *str)
{
	cout << "Введите следующий элемент " << endl;
	cin >> str;


	return str;
}
// ----------------------------------------------------------

// ----------------------------------------------------------
// Функция для получения кол ва элементов в списке, кол-ва удаляемых элементов, корневого элементов списка
template <typename T>
void input_params(for_input_params<T> *help_struct)
{
	int cntr, delq;
	T inval;


	cout << "Введите кол-во элементов в очереди" << endl;
	cin >> cntr;
	cout << "Введите кол-во удаляемых элементов" << endl;
	cin >> delq;

	// Получение ключевого элемента списка.
	inval = scan_elem<T>();

	// Данные записываются в структуру, так как функция не может возвращать несколько параметров.
	help_struct->counter = cntr;
	help_struct->del_q = delq;
	help_struct->in_val = inval;
}

template <typename T>
char *input_params(for_input_params<T> *help_struct, char *str)
{
	int cntr, delq;


	cout << "Введите кол-во элементов в очереди" << endl;
	cin >> cntr;
	cout << "Введите кол-во удаляемых элементов" << endl;
	cin >> delq;

	// Получение ключевого элемента списка.
	str = scan_elem<T>(str);

	// Данные записываются в структуру, так как функция не может возвращать несколько параметров.
	help_struct->counter = cntr;
	help_struct->del_q = delq;


	return str;													  // Возвращает полученную от пользователя строку(массив)
}
// ----------------------------------------------------------

