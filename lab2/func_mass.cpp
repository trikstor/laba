#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Функция генерации случайного числа.
int rand_value()
{
    int rand_val = rand()%9 + 1;// Натуральные числа от 1 до 9.
    return rand_val;
}

// Печать номера массива и элемент под предолженным номером.
void printr(int n, int *mass){
    for(int i=0; i<n; i++) {
    cout << "  " << i << "  " << mass[i] << endl;
    }
}

// Заполнение массива размера num случайными элементами.
void cycle_rand(int num, int *mass){
    for (int i = 0; i < num; i++) {
        mass[i] = rand_value();
    }
    printr(num, mass);
}

// Подсчет элементов, удовлетворяющих требованиям задачи.
int cycle_counter(int num, int *mass, int del_val){
    int n = 0;
    for (int i = 0; i < num; i++) {
        if(mass[i] != del_val)  // Если элемент массива не равен del_val.
        {
            if(mass[i]%2 == 0) n++;  // Если элемент четный, то n+1.
            n++; // Новый n.
        }
    }
        return n;
}

// Заполнение массива элементами, удовлетворяющими условию задачи, размещение нуля пред каждым четным элементом.
void cycle_fill(int num, int *mass, int del_val){
    int *newmass = new int[num];
    int n = 0;
    for (int i = 0; i < num; i++) {
        if(mass[i] != del_val && mass[i]%2 != 0)  // Если эелмент массива не равен del_val и он нечетный.
        {
            newmass[n] = mass[i];  // Пишем все как есть.
            n++;
        }
        if(mass[i] != del_val && mass[i]%2 == 0){  // Если эелмент массива не равен del_val и он четный.
            newmass[n] = 0;  // Вставляем ноль перед четным элементом массива.
            n++;
            newmass[n] = mass[i];
            n++;
        }
        }
    printr(n, newmass);
    delete [] newmass;  // Удаление массивов.
    }