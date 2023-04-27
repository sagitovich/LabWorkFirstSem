/*
Дана последовательность натуpальных чисел {Aj}. 
Hайти произведение чисел, не делящихся на 5, 
наибольшее из таких чисел и номеp этого числа в последовательности.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter count number in sequence: ";
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << "Error: incorrect sequence length" << endl;
        return 1;
    }
     
    // Создать переменную произведения
    // Создать переменную max
    // Создать переменную индекса max

    double product, Max, Id_Max;
    product = 1;
    Max = -1 * pow(2, 100);
    Id_Max = 0;

    bool result = false; 
    double a;
    bool event5 = true; // 1 str
    cout << "Enter number of sequence: " << endl;
    for (int i = 0; i < n; i++)
    { 
        cin >> a;
        if (fmod(a, 5) != 0) // 2 str
        {
            event5 = false;  // 3 str
        }
        

        if (fmod(a, 5) != 0)  // Проверка на делимость
        {
            product *= a;  // Обновление произведения
            result = true;

            if (a > Max)  // Если эл-т больше максимума
                Max = a;  // Он становится максимумом
        }
        if (a == Max)   // Если проверяется индекс max эл-та 
        {
            Id_Max = i + 1;  // Запоминаем его (+1 потому что отсчёт от 0)    
        } 
    }

    if (event5 == true)  // 4 str 
    {
        cout << "All numbers are divisible by 5" << endl;
        return 1;
    }

    if (result == true)
    {
        cout << "Product of the elements = " << product << endl;
        cout << "Maximum element of the sequence: " << Max << endl;
        cout << "Maximum element number: " << Id_Max << endl;
    }
    return 0;
}

