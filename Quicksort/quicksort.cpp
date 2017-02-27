#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

void quicksort(int *mass, int size, int left, int right)
{
	int middle = size >> 1;
		int l = left;
		int r = right;
		do
		{
			while (mass[l] < mass[middle])
				l++;
			while (mass[r] > mass[middle]) 
				r--;
			if (l <= r)
			{
				mass[l] = mass[l] ^ mass[r];
				mass[r] = mass[r] ^ mass[l];
				mass[l] = mass[l] ^ mass[r];
				l++;
				r--;
			}
		} while (l <= r);
		if (l < r)
			quicksort(mass, size, l, right);

		if (l < r)
			quicksort(mass, size, left, r);
}

int main() 
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");							 // Русский язык в консоли
	int *mass = new int[10];
	for (int i = 0; i < 10; i++)
	{
		mass[i] = rand() % 10;
		cout << mass[i] << endl;
	}
	quicksort(mass, 9, 0, 9);
	cout << "--------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		mass[i] = rand() % 10;
		cout << mass[i] << endl;
	}
	system("pause");
	return 0;
}
