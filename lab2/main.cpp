#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    const int N = 65535;

    int n;
    cout << "Задайте количество элементов массива и заполните его \n";
    cin >> n;

    //заполнение массива
    int m[N];
    for (int i = 0; i < n; i++)
        cin >> m[i];

    //задание переменных произведения, минимального эл-та и его номера
    double pr = 1, minm = 1;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        //выделение дробной части
        double a, b;
        a = modf(m[i], &b);

        if (a < 0)  //проверка
        {
            pr *= m[i];
            if (m[i] < minm)
            {
                minm = m[i];
                index = i;
            }
        }
    }

    if (pr == 1 || minm == 1 || index == -1)
        cout << "Дробные отрицательные числа не были заданы";
    else
        cout << pr << " - произведение \nминимальное " << minm << " под номером " << index + 1;

    return 0;

}
