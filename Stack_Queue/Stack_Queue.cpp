#include <iostream>
#include <iostream>
#include <clocale>

#include "common_func.h"												// Общие функции
#include "Queue_func.h"													// Функции для работы с очередью
#include "Stack_func.h"													// Функции для работы со стеком

using namespace std;

/*
Зотов Антон														  ФО-160002
Демонстрация работы стека и очереди с использованием различных типов данных.

Стек - список элементов, организованных по принципу LIFO (последним пришел - первым вышел).
Представляет собой односвязный линейный список с функциями добавления, удаления элементов и
печати списка в консоль.

Очередь - список элементов, организованных по принципу FIFO (первый пришел - первый вышел).
Представляет собой двусвязный линейный список с функциями добавления, удаления элементов и
печати списка в консоль.

Реализованы функции: создание линейного списка, заполнение линейного списка, удаление элеме -
нтов линейного списка, печать линейного списка.
*/
int main()
{
	setlocale(LC_ALL, "Russian");											// Русский в консоли
	int variable;															// Выбор стека или очереди
	int type;																// Тип вводимых данных.

	cout << "Для использования очереди введите 0, для использования стека введите 1." << endl;
	cin >> variable;

	if (variable == 0)
	{
		cout << "Введите тип данных: \n\t1 - int\n\t2 - double\n\t3 - char\n\t4 - масссив char" << endl;
		cin >> type;
		// Вызов шаблонной функции работы с очередью, используя разные типы данных
		switch (type)
		{
		case 1:
			Start_Queue<int>();
			break;
		case 2:
			Start_Queue<double>();
			break;
		case 3:
			Start_Queue<char>();
			break;
		case 4:
			Start_Queue_mass<char>();
			break;
		}
	}
	else
	{
		cout << "Введите тип данных: \n\t1 - int\n\t2 - double\n\t3 - char\n\t4 - масссив char" << endl;
		cin >> type;
		// Вызов шаблонной функции для работы со стеком, используя разные типы данных
		switch (type)
		{
		case 1:
			Start_Stack<int>();
			break;
		case 2:
			Start_Stack<double>();
			break;
		case 3:
			Start_Stack<char>();
			break;
		case 4:
			Start_Stack_mass<char>();
			break;
		}
	}


	system("pause");														// Задержка консоли
	return 0;
}