#include "KMP_func.h"
#include <iostream>

using namespace std;

void prefix(char *mass, int *prfx, int mass_l)
{
	int len = mass_l;

	prfx[0] = 0;

	int k = 0;
	for (int i = 1; i < len; ++i) {
		while ((k > 0) && (mass[k] != mass[i]))
			k = prfx[k - 1];
		if (mass[k] == mass[i])
			++k;
		prfx[i] = k;
	}
}

int kmp_search(char *mass, char *templa, int *prfx, int *result, int mass_l, int templa_l)
{
	int i = 0;
	int n = 0;
	int p = 0;
	int sgn = 0;
	int count = 0;
	int sovpalo = 0;
	while (n + templa_l < mass_l)
	{
		for (i = 0; i < templa_l; i++)
		{
			if (mass[i + n + p] != templa[i] && sgn == 0)
			{
				sgn = 1;
			}
			else
			{
				sovpalo++;
				if (i == templa_l - 1 && sgn == 0 && mass[i + n + p] == templa[i])
				{
					result[count] = n + p;
					count++;
				}
			}
		}
		if (sgn == 0)
		{
			p = templa_l-1;
		}
		else
		{
			if (sovpalo == 0)
			{
				p = 1;
			}
			else
			{
				p = sovpalo - prfx[sovpalo];
			}
		}
		sovpalo = 0;
		sgn = 0;
		n++;
	}
	return count;
}
