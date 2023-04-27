#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void read(int A[100][100], int& row, int& colums)   // заполнение матрицы
{
    ifstream in("matrix_in.txt");
    in >> row;
    in >> colums;    

    while (!in.eof()) {                         // считывание матрицы
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colums; j++) {
                in >> A[i][j];           
            }
        }
    }
}

void min_max(int min, int max)
{
    
    cout << "Min element: " << min << endl;
    cout << "Max element: " << max << endl;
}

void error()
{
    cout << "Sum of the digits of elemets max and min is not equal." << endl;
}

int sum_digit(int num)
{
    int sum = 0;
    while (num != 0) {
        if (num < 0) {
            num = abs(num);     // убираем минус перед числом
        } 
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}