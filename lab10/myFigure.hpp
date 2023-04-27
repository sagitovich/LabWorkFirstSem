#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.hpp"
#include <iostream>


int WindowX = 1200; int WindowY = 800;

class myFigure
{
    private:
        
    public:

        double m_x0;  double m_y0;
        double m_Vx;  double m_Vy; double m_R;

        sf::CircleShape m_CircleFigure;
        sf::RectangleShape m_RectangleFigure;
        sf::ConvexShape m_ConvexFigure;

        myFigure(sf::CircleShape figure) {m_CircleFigure = figure;}
        void setCircle(double x0, double y0, double Vx, double Vy, double R)
        {
            m_x0 = x0; m_y0 = y0; m_Vx = Vx; m_Vy = Vy; m_R = R;
                        
            m_CircleFigure.setFillColor(sf::Color(0,0,128));
            m_CircleFigure.setOrigin(2 * m_R, 2 * m_R); 
            m_CircleFigure.setPosition(m_x0, m_y0);
        }
        void MoveCircle(int time)
        {
            sf::Vector2f Position = m_CircleFigure.getPosition();
            if (Position.y < WindowY) {
                m_CircleFigure.setPosition(m_x0, m_y0 + m_Vy * ((int)time%(438)));
                std::cout << Position.x << " - " << Position.y << std::endl;
            }
            else {
                m_CircleFigure.setPosition(m_x0, m_y0);
            }
        }

        myFigure(sf::ConvexShape figure) {m_ConvexFigure = figure;}
        void setTriangle(double x0, double y0, double Vx, double Vy)
        {
            Triangle(m_ConvexFigure);
            m_x0 = x0; m_y0 = y0; m_Vx = Vx; m_Vy = Vy;
            m_ConvexFigure.setPosition(m_x0, m_y0);
            m_ConvexFigure.setOrigin(300, 200);
        }
        void MoveTriangle(double time)
        {
            bool stop = false; 
            sf::Vector2f Position = m_ConvexFigure.getPosition();
            if  (Position.x >=  WindowX || Position.y >= WindowY)
            {
                m_ConvexFigure.setPosition(Position);
            }
            else if (!stop) 
            {
                stop = true;
                {m_ConvexFigure.setPosition(m_x0 + m_Vx * time, m_y0 + m_Vy * time);} 
            }
        }

        void setStar(double x0, double y0, double Vx, double Vy)
        {
            Star(m_ConvexFigure);
            m_x0 = x0; m_y0 = y0; m_Vx = Vx; m_Vy = Vy;
            m_ConvexFigure.setPosition(m_x0, m_y0);
            m_ConvexFigure.setOrigin(110, 100);
        }
        void MoveStar(double time)
        {
            bool stop = false; 
            sf::Vector2f Position = m_ConvexFigure.getPosition();
            if  (Position.x >=  WindowX || Position.y >= WindowY)
            {
                m_ConvexFigure.setPosition(Position);
            }
            else if (!stop) 
            {
                stop = true;
                {m_ConvexFigure.setPosition(m_x0 + m_Vx * time, m_y0 + m_Vy * time);} 
            }
        }

        myFigure(sf::RectangleShape figure) {m_RectangleFigure = figure;}
        void setRectangle(double x0, double y0, double Vx, double Vy)
        {
            Square(m_RectangleFigure);
            m_x0 = x0; m_y0 = y0; m_Vx = Vx; m_Vy = Vy;
            m_RectangleFigure.setPosition(m_x0, m_y0);
            m_RectangleFigure.setOrigin(150, 150);
        }
        void MoveRectangle(double time)
        {
            bool stop = false; 
            sf::Vector2f Position = m_RectangleFigure.getPosition();
            if  (Position.x >=  WindowX || Position.y >= WindowY)
            {
                time = 0;
                m_RectangleFigure.setPosition(Position);
            }
            else if (!stop) 
            {
                stop = true;
                {m_RectangleFigure.setPosition(m_x0 + m_Vx * time, m_y0 + m_Vy * time);} 
            }
        }        
};







/*void MoveCircle(double time)
        {
            bool stop = false; 
            sf::Vector2f Position = m_CircleFigure.getPosition();
            if  ((Position.x >= WindowX || Position.y >= WindowY) ||
            (Position.x <=  0 || Position.y <= 0))
            {
                m_CircleFigure.setPosition(Position);
                //m_CircleFigure.setPosition(Position);
                std::cout << Position.x << " - " << Position.y << std::endl;
            }
            else if (!stop) 
            {
                stop = true;
                {m_CircleFigure.setPosition(m_x0 + m_Vx * time, m_y0 + m_Vy * time);} 
            }
        }*/