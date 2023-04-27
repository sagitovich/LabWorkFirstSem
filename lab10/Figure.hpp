#include <SFML/Graphics.hpp>

void Square(sf::RectangleShape &square)
{
    square.setSize(sf::Vector2f(150, 150));     
    square.setFillColor(sf::Color(0,128,0));             
}

void Triangle(sf::ConvexShape &triangle)
{
    triangle.setPointCount(3);
    triangle.setFillColor(sf::Color(210,105,30));
    
    triangle.setPoint(0, sf::Vector2f(200, 0));
    triangle.setPoint(1, sf::Vector2f(300, 200));
    triangle.setPoint(2, sf::Vector2f(100, 200));
}

void Star(sf::ConvexShape &star)
{
    star.setPointCount(10);
    star.setFillColor(sf::Color::White);

    star.setPoint(0, sf::Vector2f(60, 0));
    star.setPoint(1, sf::Vector2f(72, 40));
    star.setPoint(2, sf::Vector2f(110, 40));
    star.setPoint(3, sf::Vector2f(80, 60));
    star.setPoint(4, sf::Vector2f(100, 100));
    star.setPoint(5, sf::Vector2f(60, 70));
    star.setPoint(6, sf::Vector2f(20, 100));
    star.setPoint(7, sf::Vector2f(40, 60));
    star.setPoint(8, sf::Vector2f(10, 40));
    star.setPoint(9, sf::Vector2f(48, 40));
}
