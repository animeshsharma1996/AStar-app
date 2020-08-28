#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <iostream>
#include <chrono>
#include "Draw.h"
#include "EventHandler.h"
using namespace sf;

void HandleStartCheck(Event e, Draw* draw, Vector2i mousePosition, Vector2i startPos)
{
    EventHandler::CheckEnterStart(e);
    if (e.key.code == Mouse::Left)
    {
        draw->RefreshGrid();
        EventHandler::SetStartPos(mousePosition);
        draw->grid[startPos.x][startPos.y].cell.setTexture(draw->startTexture);
    }
}

void HandleEndCheck(Event e, Draw* draw, Vector2i mousePosition, Vector2i endPos)
{
    EventHandler::CheckEnterEnd(e);
    if (e.key.code == Mouse::Left)
    {
        draw->RefreshGrid();
        EventHandler::SetEndPos(mousePosition);
        draw->grid[endPos.x][endPos.y].cell.setTexture(draw->endTexture);
    }
}

void HandleWallsCheck(Event e, Draw* draw, Vector2i mousePosition, Vector2i startPos, Vector2i endPos)
{
    EventHandler::CheckEnterWallsSet(e);
    if (e.key.code == Mouse::Left && mousePosition != 16 * startPos && mousePosition != 16 * endPos)
    {
        EventHandler::SetWallsPos(mousePosition);
        draw->grid[abs(mousePosition.x / 16)][abs(mousePosition.y / 16)].cell.setTexture(draw->wallTexture);
    }
}

void MouseEvent(Event e, Draw* draw, Vector2i mousePosition)
{
    bool startBlock = EventHandler::GetStartCheck();
    bool endBlock = EventHandler::GetEndCheck();
    bool wallsBlock = EventHandler::GetWallsCheck();
    Vector2i startPos = EventHandler::GetStartPos();
    Vector2i endPos = EventHandler::GetEndPos();

    if (e.type == Event::MouseButtonPressed || e.type == Event::KeyPressed)
    {
        if (!startBlock)
        {
            HandleStartCheck(e,draw,mousePosition,startPos);
        }
        else  if (!endBlock)
        {
            HandleStartCheck(e, draw, mousePosition, endPos);
        }
        else  if (!wallsBlock)
        {
            HandleWallsCheck(e, draw, mousePosition, startPos, endPos);
        }
    }
}

void DrawWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "The AStar! (Press Enter to complete each event)");

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
        std::cout << EventHandler::GetStartPos << std::endl;
        //draw cells
        window.clear();
        for (int i = 0; i < 50; ++i)
        {
            for (int j = 0; j < 28; ++j)
            {
                window.draw(draw->grid[i][j].cell);
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



