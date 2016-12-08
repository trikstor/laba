#define _CRT_SECURE_NO_WARNINGS								 // Отключение предупреждений для fopen

#include <iostream>
#include <clocale>
#include "d_struct_func.h"

using namespace std;

/*
9 Вариант.

1.	Создание списка.
2.	Добавление элемента в список (в соответствии со своим вариантом).
3.	Удаление элемента из списка (в соответствии со своим вариантом).
4.	Печать списка.
5.	Запись списка в файл.
6.	Уничтожение списка.
7.	Восстановление списка из файла.

Записи в линейном списке содержат ключевое слово типа int. Сформировать двунаправленный список. 
Удалить из него К элементов перед элементом с заданным номером,
добавить К элементов в начало списка
*/
int main() {

	setlocale(LC_ALL, "Russian");							 // Русский язык в консоли

	point *end, *root;										 // Объявление корневых и последних элементов списка

	int elems;												 // Количество элементов

	cout << "Введите кол-во элементов" << endl;
	cin >> elems;

	root = make_point(0);
	end = root;

	for (int n = 1; n <= elems; n++)						 // Перебор элементов
		end = insert_elem(end, n);							 // Вставка следующего элемента списка со значением, равным номеру элемента; присваивание p новой структуры списка

	listprint(root, elems);									 // Печать списка


	int del_num, quantity;									 // Элемент для удаления; количество удаляемых элементов; количество удаляемых элементов



	cout << "Введите элемент для удаления" << endl;
	cin >> del_num;

	cout << "Введите кол-во элементов для удаления и дополнения" << endl;
	cin >> quantity;



	root = delete_elem(end, root, del_num, quantity);					 // Удаление элементов с соответствующими параметрами

	listprint(root, elems - quantity);						// Печать списка



	root = insert_root_elem(root, quantity);

	listprint(root, elems);									 // Печать списка



	in_file(root, "file.txt", elems);						 // Запись списка в файл

	root = delete_all(root);								 // Удаление списка 

	listprint(root, elems);									 // Печать пустого списка

	end = from_file("file.txt");							 // Восстановление списка из файла

    listprint(end, elems);									 // Печать списка



	delete end;												 // Удаление указателей
	delete root;

	system("pause");										 // Задержка консоли

	return 0;
}
