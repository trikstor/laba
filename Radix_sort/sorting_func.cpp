#include <iostream>
#include <ctime>
#include <cmath>
#include <clocale>
#include "sorting_func.h"

using namespace std;

/* Заполнение массива случайными числами. */
void rand_mass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 999;
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

void radix_sort(int *mass, int n)
{
	int max = 0;
	int size = 0;
	int middle;

	for(int i = 0; i < n; i++)
	{
		if(mass[i] > max)
			max = mass[i];
	}

	while(max > 10){
		max /= 10;
		size++;
	}

	for(int i = 0; i < n; i++)
	{

		if(int(mass[i]/pow(10, size)) == 0 && int(mass[n-i-1]/pow(10, size)) > 0)
		{
			cout << "!" << i << "|" << n-i-1 << "!";
			change(mass, n-i-1, i);
			middle = i;
		}
	}
}