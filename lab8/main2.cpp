#include <iostream>
using namespace std;
int main()
{
    int* cnt = new int; int* cnt_ = new int;    // задаём переменные кол-ва строк и столбцов
    int **a;                                     // описание двойных указателей для матрицы A
    cout << "Число строк = "; cin >> *cnt;
    cout << "Число столбцов = "; cin >> *cnt_;

    if (*cnt < 2 || *cnt_ < 2) {
        cout << "Error" << endl;
        return 0;
    }

    a = new int *[*cnt];                         // выделение памяти для массива А
    for (int i = 0; i < *cnt; i++) {
        a[i] = new int [*cnt_];                 // выделение памяти для каждого элемента
    }
    
    cout << "Введите матрицу А" << endl;         // ввод матрицы А
    for (int i = 0; i < *cnt; i++)
        for (int j = 0; j < *cnt_; j++)
            cin >> a[i][j];

    cout << "Матрица A " << endl;               
    for (int i = 0; i < *cnt; cout << endl , i++)       // вывод матрицы A
        for (int j = 0; j < *cnt_; j++)
            cout << a[i][j]<< "\t";

    delete cnt_;
            
    for (int i = 0; i < *cnt; i++)              // освобождаем память от неиспользованных а[i]
        delete [] a[i];                 
    delete cnt;

    delete a;                                   // освобождаем память от А
    return 0;
}
