#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Выбор случайного числа.
int rand_value();

// Функция для печати массива.
void printr(int, int*);

// Заполнение масива случайными элементами.
void cycle_rand(int, int*);

/* Подсчет кол-ва элементов массива размера num без элементов, совпадающих с del_val 
* и дополнительная размерность для нулей перед четными элементами. 
*/
int cycle_counter(int, int*, int);

/*
* Заполнение массива размера num, элементами совпадающими с del_val 
* и размещение нулей перед четными элементами.
*/
void cycle_fill(int, int*, int);
#endif

