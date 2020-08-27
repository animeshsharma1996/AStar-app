#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <iostream>
#include <chrono>
#include "Draw.h"
#include "EventHandler.h"
using namespace sf;

void MouseEvent(Event e, Draw* draw, Vector2i mousePosition)
{
    if (e.type == Event::MouseButtonPressed || e.type == Event::KeyPressed)
    {
        if (!EventHandler::GetStarted())
        {
             EventHandler::CheckEnterStart(e);
             if(e.key.code == Mouse::Left)
             {  
                    draw->RefreshGrid();
                    EventHandler::SetStartPos(mousePosition);
                    draw->cell[EventHandler::GetStartPos().x][EventHandler::GetStartPos().y].setTexture(draw->startTexture);
             }
        }
        else
        {
            if (!EventHandler::GetEnded())
            {
                EventHandler::CheckEnterEnd(e);
                if (e.key.code == Mouse::Left)
                {
                    draw->RefreshGrid();
                    EventHandler::SetEndPos(mousePosition);
                    draw->cell[EventHandler::GetEndPos().x][EventHandler::GetEndPos().y].setTexture(draw->endTexture);
                }
            }
            else
            {
                if (e.key.code == Mouse::Left)
                {
                    EventHandler::SetWallPos(mousePosition);
                    draw->cell[abs(mousePosition.x/16)][abs(mousePosition.y/16)].setTexture(draw->wallTexture);
                }
            }
        }
    }
}

void DrawWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "The AStar! (press SPACE)");

    Draw* draw = new Draw();

    draw->LoadBlockTexture();
    draw->LoadStartTexture();
    draw->LoadEndTexture();
    draw->LoadWallTexture();
    draw->CreateGrid();

    while (window.isOpen())
    {
        Vector2i mousePosition = Mouse::getPosition(window);

        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed) window.close();
            MouseEvent(e, draw, mousePosition);
            
        }

        //draw cells
        window.clear();
        for (int i = 0; i < 50; ++i)
        {
            for (int j = 0; j < 28; ++j)
            {
                window.draw(draw->cell[i][j]);
            }
        }
        window.display();
    }
}

int main()
{
    DrawWindow();
    return 0;
}



