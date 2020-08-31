#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <iostream>
#include <chrono>
#include "Draw.h"
#include "EventHandler.h"
#include "AStar.h"
using namespace sf;

void HandleStartCheck(Event e, Draw* draw, Vector2i mousePosition)
{
    EventHandler::CheckEnterStart(e);
    if (e.key.code == Mouse::Left)
    {
        draw->RefreshGrid();
        EventHandler::SetStartPos(mousePosition);
        Vector2i startPos = EventHandler::GetStartPos();
        draw->grid[startPos.x][startPos.y].cell.setTexture(draw->startTexture);
    }
}

void HandleEndCheck(Event e, Draw* draw, Vector2i mousePosition)
{
    EventHandler::CheckEnterEnd(e);
    if (e.key.code == Mouse::Left)
    {
        draw->RefreshGrid();
        EventHandler::SetEndPos(mousePosition);
        Vector2i endPos = EventHandler::GetEndPos();
        draw->grid[endPos.x][endPos.y].cell.setTexture(draw->endTexture);
    }
}

void HandleWallsCheck(Event e, Draw* draw, Vector2i mousePosition)
{
    EventHandler::CheckEnterWallsSet(e);
    if (e.key.code == Mouse::Left && (!EventHandler::CheckWallsOverlap(mousePosition)))
    {
        EventHandler::SetWallsPos(mousePosition);
        int X = floor(mousePosition.x / 16);
        int Y = floor(mousePosition.y / 16);
        draw->grid[X][Y].cell.setTexture(draw->wallTexture);
        draw->grid[X][Y].isWall = true;
    }
}

void GeneratePath(Draw* draw)
{
    Vector2i startPos = EventHandler::GetStartPos();
    Vector2i endPos = EventHandler::GetEndPos();

    Node* start = new Node(startPos.x,startPos.y);
    Node* end = new Node(endPos.x, endPos.y);

    vector<Node> pathFound = AStar::FindPath(draw, draw->grid, *start, *end);
    draw->CreateOpenList(AStar::openList);
    draw->CreateClosedList(AStar::closedList);
    draw->CreatePath(pathFound);
}

void MouseEvent(Event e, Draw* draw, Vector2i mousePosition)
{
    bool startBlock = EventHandler::GetStartCheck();
    bool endBlock = EventHandler::GetEndCheck();
    bool wallsBlock = EventHandler::GetWallsCheck();

    if (e.type == Event::MouseButtonPressed || e.type == Event::KeyPressed)
    {
        if (!startBlock)
        {
            HandleStartCheck(e,draw,mousePosition);
        }
        else  if (!endBlock)
        {
            HandleEndCheck(e,draw,mousePosition);
        }
        else  if (!wallsBlock)
        {
            HandleWallsCheck(e,draw,mousePosition);
        }
    }

    if (wallsBlock) 
        GeneratePath(draw);
}

void DrawWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "The AStar! (Press Enter to complete each event)");

    Draw* draw = new Draw();

    draw->LoadBlockTexture();
    draw->LoadStartTexture();
    draw->LoadEndTexture();
    draw->LoadWallTexture();
    draw->LoadOpenNodeTexture();
    draw->LoadClosedNodeTexture();
    draw->LoadPathTexture();
    draw->CreateGrid();

    while (window.isOpen())
    {
        Vector2i mousePosition = Mouse::getPosition(window);

        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed) 
                window.close();

            MouseEvent(e, draw, mousePosition);
        }
        
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



