#include <iostream>
using namespace std;

void sort_array(int *a, int size)              // сортировка массива 
{
    for (int i = 0; i < size; i++)  {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) 
                swap(a[i], a[j]);
        }
    }
}

void print_array(int *a, int size)              // вывод старого массива 
{
    cout << "Sequence: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print_new_array(int *a, int size)          // вывод нового массива
{
    cout << "New sequence: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter count number in sequence: ";
    int n;  
    cin >> n;  // ввод длины массива

    int *a;  // создание массива
    cout << "Enter number of sequence: " << endl;
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort_array(a, n);

    print_array(a, n);

    int add_n;  // количество добавочных чисел
    cout << "How many numbers do you want to add?" << endl;
    cin >> add_n;
    if (add_n != 0) {  
        if (add_n > 0) {      
            a = (int *)realloc(a, sizeof(int) * (add_n + n));  // выделяем память на расширеный массив
        
            cout << "Enter additional number of sequence: ";   // вводим добавочные числа
            for (int i = n; i < n+add_n; i++) {
                cin >> a[i];
            }
            print_new_array(a, n + add_n);
        }
        if (add_n < 0) {
            print_new_array(a, n - abs(add_n));
        }        
    }   
    else {cout << "Program is completed!" << endl; return 0;}

    delete a; 

    cout << "Program is completed!" << endl; return 0;
}
