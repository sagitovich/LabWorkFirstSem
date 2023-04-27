#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{   
    private:
        double m_A{}, m_B{}, m_C{};       // стороны треугольника
    public:
        Triangle () = default;

        ~Triangle() = default;

    bool SetABC(double A, double B, double C)
    {   // проверка на корректность ввода данных
        if (A <= 0 || B <= 0 || C <= 0) {cout << "Error side!" << endl; return false;}
        // присвоение введеённых значений
        m_A = A; m_B = B; m_C = C;
        return true;
    }

    double getA() const {return m_A;}
    double getB() const {return m_B;}
    double getC() const {return m_C;}

    double getFigureArea() const
    {
        if (m_A+m_B <= m_C || m_B+m_C <= m_A || m_A+m_C <= m_B) 
        // условие существования треугольника
        {cout << "Error area!" << endl; return 0;}
        

        else {
            double p = (m_A + m_B + m_C) / 2;   // полупериметр
            double m_Area = sqrt(p*(p - m_A)*(p - m_B)*(p - m_C));
            return m_Area;}     // находим площадь треугольника
    }

    void ShowAll() const
    {
        cout << "Sides: " << m_A << " "  << m_B << " " << m_C << endl;
    }
};

int main()
{
    Triangle Figure1;

    cout << "Enter three side of triangle: ";
    double A, B, C, S;
    cin >> A >> B >> C;
    Figure1.SetABC(A, B, C);

    S = Figure1.getFigureArea();

    if (S > 0 && A > 0 && B > 0 && C > 0) {Figure1.ShowAll();}

    cout << "Area = " << Figure1.getFigureArea() << endl;

    return 0;
}
