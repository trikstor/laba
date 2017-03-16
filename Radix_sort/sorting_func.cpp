#include <iostream>
#include <ctime>
#include <cmath>
#include <clocale>
#include "sorting_func.h"

using namespace std;

void rand_mass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 99;
	}
}

void print_mass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " | " << mass[i];
	}
	cout << endl;
}

int count_rang(int val)
{
	int n_val = val;
	int counter = 0;
	while (n_val >0)
	{
		n_val /= 10;
		counter++;
	}
	return counter;
}
int rang_size(int *mass, int size)
{
	int max = 0;
	int counter;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] > max)
			max = mass[i];
	}

	counter = count_rang(max);
	return counter;
}

int take_rang(int val, int rang, int max_rang)
{
	int res;
	int n_rang = count_rang(val);
	if (n_rang >= max_rang - rang)
	{
		if (max_rang == rang + 1)
		{
			res = val % 10;
		}
		else
		{
			res = ((val % int(pow(10, max_rang - rang))) - (val % int(pow(10, max_rang - rang - 1)))) / int(pow(10, max_rang - rang - 1));
		}
	}
	else
	{
		res = 999;
	}
	return res;
}

void radix_sort(int *mass, int size)
{
	int count = 0, count1 = 0;
	int max_rang = rang_size(mass, size);
	int *mass1 = new int[size];
	int *step_mass = new int[size];
	for (int rang = max_rang - 1; rang >= 0; rang--)
	{
		for (int i = 0; i < size; i++)
		{
			step_mass[i] = 999;
			mass1[i] = 0;
		}
		count = 0;
		count1 = 0;
		for (int n = 0; n < size; n++)
		{
			if (take_rang(mass[n], rang, max_rang) == 999)
			{
				step_mass[count1] = mass[n];
				count1++;
			}
		}
		print_mass(step_mass, size);
		for (int i = 0; i <= 9; i++)
		{
			for (int n = 0; n < size; n++)
			{
				cout << endl << mass[n] << "|" << take_rang(mass[n], rang, max_rang) << "|" << i;
				if (take_rang(mass[n], rang, max_rang) == i)
				{
					mass1[count] = mass[n];
					count++;
					cout << "<";
					print_mass(mass1, size);
				}
			}
		}
		count1 = 0;
		for (int i = 0; i < size; i++)
		{
			if (step_mass[i] == 999)
			{
				step_mass[i] = mass1[count1];
				count1++;
			}
		}
		for (int i = 0; i < size; i++)
		{
			mass[i] = step_mass[i];
		}
	}
}
