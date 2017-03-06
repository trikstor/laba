#include <iostream>
#include <ctime>
#include <clocale>
#include "sorting_func.h"

using namespace std;

/* Заполнение массива случайными числами. */
void rand_mass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 10;
	}
}

/* Печать массива */
void print_mass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " | " << mass[i];
	}
}

/* Поменять местами i-ый элемент массива, и следующий за ним. */
void change(int *mass, int i, int step)
{
	mass[i] ^= mass[step];							// 0+1 = 1; a = 1
	mass[step] ^= mass[i];							// 1+1 = 0; b = 0
	mass[i] ^= mass[step];							// 1+0 = 1; a = 1
}

void heapsort(int *mass, int n)
{
	int b, i;
	int sh = 0;
	int left_cld, right_cld;
	while (sh + 2 != n)
	{
		b = 0; // Если не будет изменений, то счетик не изменится
		for (i = 0; i < n; ++i) // Перебор массива (элемент i считается за корневой в даннном состоянии)
		{
			left_cld = i * 2 + 1 + sh; // Левое ответвление
			right_cld = i * 2 + 2 + sh; // Правое ответвление
			if (right_cld < n) // Если правое ответвление меньше кол-ва элементов массива (чтобы не выехало за границы массива)
			{
				if (mass[left_cld] < mass[right_cld] && mass[left_cld] < mass[i + sh]) // Если правое ответвление больше левого и корневой элемент с погрешностью на уже расположенный
					{
						change(mass, i + sh, left_cld); // Меняем местами левое ответвление и 
						b = 1; // Засчитываем изменение
					}
					else if (mass[left_cld] > mass[right_cld] && mass[right_cld] < mass[i + sh]) // Если левое ответвление больше правого и
					{
						change(mass, i + sh, right_cld); // Меняем местами правое ответвление и
						b = 1; // Засчитываем изменение
					}
			}
			if (mass[i + sh] > mass[left_cld] && left_cld < n) // Если левое ответвление меньше кол-ва элементов массива (чтобы не выехало за границы массива)
				{
					change(mass, i + sh, left_cld); // Меняем местами левое ответвление и
					b = 1; // Засчитываем изменение
				}
			}
		if (b == 0) sh++; // Счетчик изменений в пирамиде
	}
}