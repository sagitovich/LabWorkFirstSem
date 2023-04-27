#include <iostream>
#include <cmath>
using namespace std;

double auto_credit(double sum, int time) 
{
    double first;
    first = sum / 10;
    cout << "Первый взнос: " << first << endl;
    sum = sum - first;
    double sum_mon, overpayment;
    sum_mon = (sum * (0.15 / 12) * pow((1 + 0.15 / 12), time * 12)) / (pow((1 + 0.15 / 12), time * 12) - 1);
    overpayment = sum_mon * time * 12 - sum - first;
    cout << "Переплата: " << overpayment << endl;
    cout << "double-int" << endl;
    return sum_mon;
}

double auto_credit(double sum, double time) 
{
    double first;
    first = sum / 10;
    cout << "Первый взнос: " << first << endl;
    sum = sum - first;
    double sum_mon, overpayment;
    sum_mon = (sum * (0.15 / 12) * pow((1 + 0.15 / 12), time * 12)) / (pow((1 + 0.15 / 12), time * 12) - 1);
    overpayment = sum_mon * time * 12 - sum - first;
    cout << "Переплата: " << overpayment << endl;
    cout << "double-double" << endl;
    return sum_mon;
    
}

double house_credit(int sum, int time)
{
    double first;
    first = sum / 10;
    cout << "Первый взнос: " << first << endl;
    sum = sum - first;
    double sum_mon, overpayment;
    sum_mon = (sum * (0.1 / 12) * pow((1 + 0.1 / 12), time * 12)) / (pow((1 + 0.1 / 12), time * 12) - 1);
    overpayment = sum_mon * time * 12 - sum - first;
    cout << "Переплата: " << overpayment << endl;
    cout << "int-int" << endl;
    return sum_mon;
}

double house_credit(int sum, double time)
{
    double first;
    first = sum / 10;
    cout << "Первый взнос: " << first << endl;
    sum = sum - first;
    double sum_mon, overpayment;
    sum_mon = (sum * (0.1 / 12) * pow((1 + 0.1 / 12), time * 12)) / (pow((1 + 0.1 / 12), time * 12) - 1);
    overpayment = sum_mon * time * 12 - sum - first;
    cout << "Переплата: " << overpayment << endl;
    cout << "int-double" << endl;
    return sum_mon;
}