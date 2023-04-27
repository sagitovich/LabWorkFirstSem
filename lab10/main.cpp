// Создать 4 фигуры. Разные: форма, цвет, размер, скорость. 
// Движение по диагонали вниз вправо. Остановка при касании границы окна.

#include <SFML/Graphics.hpp>
#include "myFigure.hpp"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    int WindowX = 1200; int WindowY = 800;
    sf::RenderWindow window(sf::VideoMode(WindowX, WindowY), "Sagitov lab10");
        
    double C_Vx, C_Vy, T_Vx, T_Vy, R_Vx, R_Vy, S_Vx, S_Vy;
    C_Vx = 0, C_Vy = 2, T_Vx = 0, T_Vy = 4, R_Vx = 0, R_Vy = 3, S_Vx = 0, S_Vy = 2;

    float CircleR = 75;
    myFigure Circle = myFigure(sf::CircleShape(CircleR));   // создание круга
    Circle.setCircle(250, -75, C_Vx, C_Vy, CircleR);

    myFigure Triangle = myFigure(sf::ConvexShape());       // создание треугольника
    Triangle.setTriangle(1000, 450, T_Vx, T_Vy);
    
    myFigure Rectangle = myFigure(sf::RectangleShape());   // cоздание квадрата
    Rectangle.setRectangle(500, 450, R_Vx, R_Vy);

    myFigure Star = myFigure(sf::ConvexShape());           // создание звезды
    Star.setStar(750, 450, S_Vx, S_Vy);

    int time = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
            (event.type == sf::Event::KeyPressed)) /*&& event.key.code == sf::Keyboard::Escape*/
                window.close();
        }

        Circle.MoveCircle(time);
        Triangle.MoveTriangle(time);
        Star.MoveStar(time);
        Rectangle.MoveRectangle(time);
        
        window.clear(sf::Color(135,206,250));
        window.draw(Circle.m_CircleFigure);
        window.draw(Triangle.m_ConvexFigure);
        window.draw(Star.m_ConvexFigure);
        window.draw(Rectangle.m_RectangleFigure);
        window.display();

        time += 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return 0;
}
