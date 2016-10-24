#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Функция для определения суммы элементов квадратной матрицы ниже главной диагонали.
int matrix_summ(int **matrix, int size) {
    int summ = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {             // Цикл перечисления элементов главной диагонали
        for (int n = i; n + 1 < size; n++) {     // Цикл перечисления элементов матрицы, ниже i элемента главной диагонали.
            summ += matrix[n + 1][i];            // Прибавление элемента к сумме.
        }
    }
    return summ;
}

// Заполнение квадратной матрицы указанного размера случайными числами.
void randomizer(int **matrix, int size){
    for (int i = 0; i < size; i++)               // Перечисление элементов матрицы.
        for (int n = 0; n < size; n++)
            matrix[i][n] = rand() % 9 + 0;       // Генератор случайного числа от 0 до 9.
}

// Вывод квадратной матрицы в консоль.
void show_matrix(int **matrix, int size){
        for (int i = 0; i < size; i++) {         // Перечисление элементов матрицы.
        for (int n = 0; n < size; n++) {
            cout << setw(3) << matrix[i][n];    // Форматированный вывод элемента матрицы.
        }
        cout << endl;
    }
}

                                                // Определение максимальной суммы элементов квадратной матрицы после главной диагонали.
int maxmatrix(int summ, int maxmatr){
    if(summ > maxmatr)                          // Если summ больше maxmatr, то maxmatr присваивается значение summ.
        maxmatr = summ;
    return maxmatr;
}