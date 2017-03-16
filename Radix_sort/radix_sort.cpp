#include <iostream>
#include <ctime>
#include <cmath>
#include <clocale>
#include "sorting_func.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");								// Консоль на русском языке.
	srand(time(0));												// Обновление генератора случайных чисел.
	int num;													// Кол-во элементов массива.

	cout << "Введите кол-во элементов массива." << endl;
	cin >> num;

	int *mass = new int[num];									// Создание динамического массива

	rand_mass(mass, num);										// Заполнение массива случайными числами.
	print_mass(mass, num);

	radix_sort(mass, num);                                      // Быстрая сортировка массива

	cout << endl << "Сортированный массив." << endl;

	print_mass(mass, num);

	delete[] mass;

	system("pause");
	return 0;
}
