#include <iostream>
#include <ctime>
#include <clocale>
#include "sorting_func.h"

using namespace std;

/* Прогргамма пирамидальной сортировки массива.
Выбирается корневой элемент, для него определяются ответвления пирамиды.
Если ответвления не соответствуют правилу пирамиды, то она упорядочивается. */
int main()
{
	setlocale(LC_ALL, "Russian");								// Консоль на русском языке.
	srand(time(0));										// Обновление генератора случайных чисел.
	int num;										// Кол-во элементов массива.

	cout << "Введите кол-во элементов массива." << endl;
	cin >> num;

	int *mass = new int[num];								// Создание динамического массива

	rand_mass(mass, num);									// Заполнение массива случайными числами.
	print_mass(mass, num);

	heapsort(mass, num);						    			// Пирамидальная сортировка массива

	cout << endl << "Сортированный массив." << endl;

	print_mass(mass, num);

	delete[] mass;										// Удаление динамического массива.
	system("pause");									// Задержка консоли.
	return 0;
}
