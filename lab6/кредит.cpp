// + Cделать перегрузку функций по 2-3 наборам параметров, эти функции можно 
// не привязывать к заданию и написать отдельно, например, сумма целых/сумма не целых.

/*
Расчёт ежемесячной выплаты автокредита, при 15% годовых.   

Расчёт ипотечной ежемесячной выплаты, при 10% годовых.
*/

#include <iostream>
#include <cmath>
#include "credit_func.hpp"
using namespace std;

int main()
{
    double sum, first, time, percent, sum_mon;
    int V;      // вариант кредита 
    cout << "Программа предлагает расчёт двух типов кредита:" << endl;
    cout << "Первый тип - автокредит. Второй тип - ипотека." << endl;
    cout << "Какой тип кредита Вас интересует, 1 или 2? Мой ответ: ";
    cin >> V;
    if (V == 1) {
        cout << "Ставка - 15% годовых" << endl;
        cout << "Сумма кредита: ";
        cin >> sum;
        cout << "Срок кредита: ";
        cin >> time;
        if (time == (int)time) {
            sum_mon = auto_credit(sum, (int)time);
            cout << "Ежемесячный платёж: " << sum_mon << endl;
            return 0;
        }
        else {
            sum_mon = auto_credit(sum, time);
            cout << "Ежемесячный платёж: " << sum_mon << endl;
            return 0;
        }
    }

    if (V == 2) {
        cout << "Ставка - 10% годовых" << endl;
        cout << "Сумма кредита: ";
        cin >> sum;
        cout << "Срок кредита: ";
        cin >> time;
        if (time == (int)time) {
            sum_mon = house_credit(sum, (int)time);
            cout << "Ежемесячный платёж: " << sum_mon << endl;
            return 0;
        }
        else {
            sum_mon = house_credit(sum, time);
            cout << "Ежемесячный платёж: " << sum_mon << endl;
            return 0;
        }
    }

    else {
        return 0;
    }

}
