#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "matr_func.h"
using namespace std;
/* Вариант 9.
 * Написать функцию для вычисления суммы элементов квадратной матрицы, которые расположены ниже главной диагонали. 
 * С ее помощью найти максимальное значение такой суммы в n матрицах.
*/
int main() {
    srand(time(NULL));                          // Выполняет повторную инициализацию генератора случайных чисел rand.
    int size;                                   // Размер квадратной матрицы.
    int quantity;                               // Кол-во матриц
    int summ;                                   // Сумма элементов матрицы ниже главной диагонали.
    int maxmatr = 0;                            //Наивольшее значение summ.
    
    cout << "Введите кол- во матриц" << endl;
    cin >> quantity;
    
    for(int many = 0; many < quantity; many++){  //Цикл количества матриц.
        
    cout << "Введите размер матрицы " << endl;
    cin >> size;
    
    int **matrix = new int*[size];               // Инициализация динамического двумерного массива.
    for (int count = 0; count < size; count++)
        matrix[count] = new int[size];

    randomizer(matrix, size);                    // Заполнение матрицы случайными числами.

    show_matrix(matrix, size);                   // Распечатываем текущую матрицу.
    
    summ = matrix_summ(matrix, size);            //  Сумма элементов матрицы ниже главной диагонали.
    
    cout << "Сумма: " << summ << endl;
    
    maxmatr = maxmatrix(summ, maxmatr);          // Определение наибольшей summ .
    
    delete [] matrix;                            // Удаление двумерного динамического массива с текущей матрицей.
    }
    cout << "Наибольшая сумма " << maxmatr << endl;
    
    system("pause");                             // Для MVS
    return 0;
}

