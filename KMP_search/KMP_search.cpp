#include "KMP_func.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int count;
	int mass_l;
	int templa_l;
	cin >> mass_l;
	cin >> templa_l;

	char *mass = new char[mass_l];
	char *templa = new char[templa_l];
	int *prfx = new int[mass_l];
	int *result = new int[mass_l / templa_l];

	cin >> mass;
	cin >> templa;
	prefix(templa, prfx, templa_l);
	for (int i = 0; i < templa_l; i++)
	{
		cout << prfx[i] << endl;
	}
	count = kmp_search(mass, templa, prfx, result, mass_l, templa_l);
	for (int i = 0; i < count; i++)
	{
		cout << "Найдено совпадение c индекса " << result[i] << endl;
	}
	delete[] prfx;
	delete[] result;

	system("pause");

	return 0;
}
