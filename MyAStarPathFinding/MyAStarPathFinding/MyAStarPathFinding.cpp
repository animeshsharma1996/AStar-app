#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <iostream>
#include "Draw.h"
#include "EventHandler.h"
using namespace sf;



void MouseEvent(Event e, Draw* draw, Vector2i mousePosition)
{
    if (e.type == Event::MouseButtonPressed || e.type == Event::KeyPressed)
    {
        EventHandler::CheckEnterStart(e);
        if (!EventHandler::GetStarted())
        {    
             if(e.key.code == Mouse::Left )
             {  
                    draw->RefreshGrid();
                    EventHandler::SetStartPos(mousePosition);
                    draw->cell[EventHandler::GetStartPos().x][EventHandler::GetStartPos().y].setTexture(draw->startTexture);
             }
        }
        else
        {
            EventHandler::CheckEnterEnd(e);
            if (!EventHandler::GetEnded())
            {
                if (e.key.code == Mouse::Left)
                {
                    draw->RefreshGrid();
                    EventHandler::SetEndPos(mousePosition);
                    draw->cell[EventHandler::GetEndPos().x][EventHandler::GetEndPos().y].setTexture(draw->endTexture);
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
    draw->CreateGrid();

    while (window.isOpen())
    {
        Vector2i mousePosition = Mouse::getPosition(window);

        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed) window.close();
            MouseEvent(e, draw, mousePosition);
            std::cout << EventHandler::GetEnded() << std::endl;
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



