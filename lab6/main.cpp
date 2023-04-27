/*
+ Доп 1) В программе обязательно должна присутствовать процедура.
+ Доп 2) Рассмотреть и реализовать передачу параметров по ссылке 
и по значениям (в одном случае данные не изменяются, в другом меняются). Показать на примере матрицы.

+ Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если суммы цифр минимального и максимального элементов матрицы одинаковы, 
упорядочить строки матрицы по возрастанию суммы элементов.
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include "main_func.hpp"
using namespace std;

int main() 
{
    ofstream out("matrix_out.txt");

    int A[100][100]; 
    int row;                           // число строк
    int colums;                        // число столбцов
    
    read(A, row, colums);              // считывание матрицы

    int max_element = INT32_MIN;    // максимальный элемент
    int min_element = INT32_MAX;         // минимальный элемент
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colums; j++) {
            if (A[i][j] > max_element)
                max_element = A[i][j];    // присвоение максимального элемента
            if (A[i][j] < min_element)
                min_element = A[i][j];    // присвоение минимального элемента
        }
    }
    
    min_max(min_element, max_element);    // вывод максимального и минимального элемента 
    
 
    int sum_digit_max = sum_digit(max_element);     // сумма цифр макс элемента
    int sum_digit_min = sum_digit(min_element);     // сумма цифр мин элемента

    if (sum_digit_max != sum_digit_min) {       // если суммы цифр макс и мин не равны
        error();
        return 0;
    }

    cout << "Min sum: " << sum_digit_min << endl;
    cout << "Max sum: " << sum_digit_max << endl;

    int sum_of_row[row];                        // суммa каждой строки
    for (int i = 0; i < row; i++) {
        int time_sum = 0;
        for (int j = 0; j < colums; j++) {
            time_sum = time_sum + A[i][j];
        }
        sum_of_row[i] = time_sum;
        cout << sum_of_row[i] << " ";
    }

    for (int i = 0; i < row; i++) {             // сортировка матрицы
        if ((i < row - 1) && sum_of_row[i] >= sum_of_row[i + 1]) {        
            swap(sum_of_row[i], sum_of_row[i + 1]);
            for (int j = 0; j < colums; j++) {
                swap(A[i][j], A[i + 1][j]);
            }
        }
        if ((i > 0) && sum_of_row[i] < sum_of_row[i - 1]) {
            swap(sum_of_row[i], sum_of_row[i - 1]);
            for (int j = 0; j < colums; j++) {
                swap(A[i][j], A[i - 1][j]);
            }
        }
    }

    for (int i = 0; i < row; i++) {             // вывод матрицы
        for (int j = 0; j < colums; j++) {
            out << A[i][j] << " ";           
        }
        out << endl;
    }
    
    cout << endl << "Program is comleted!" << endl;
    return 0;
}
