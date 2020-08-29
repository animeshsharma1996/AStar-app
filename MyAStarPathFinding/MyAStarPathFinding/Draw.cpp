#include "Draw.h"
#include "EventHandler.h"

  /*  sf::Texture cellTexture;
    sf::Texture startTexture;
    sf::Texture endTexture;
    sf::Texture pathTexture;
    sf::Texture wallTexture;

    sf::Sprite cell[50][28];*/   

void Draw::CreateGrid()
{
    int size = 16; //each block is 16 px wide
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 28; ++j)
        {
            grid[i][j].cell.setTexture(cellTexture);
            grid[i][j].cell.setPosition(size * i, size * j);
            grid[i][j].SetX(i); 
            grid[i][j].SetY(j);
        }
    }
}

void Draw::RefreshGrid()
{
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 28; ++j)  grid[i][j].cell.setTexture(cellTexture);
    }

    if (EventHandler::GetStartPos().x >= 0 && EventHandler::GetStartCheck()) 
        grid[EventHandler::GetStartPos().x][EventHandler::GetStartPos().y].cell.setTexture(startTexture);

    if (EventHandler::GetEndPos().x >= 0 && EventHandler::GetEndCheck())
        grid[EventHandler::GetEndPos().x][EventHandler::GetEndPos().y].cell.setTexture(endTexture);
}

void Draw::CreatePath(vector<Node> path)
{
    for (int i = 0; i < path.size(); ++i)
    {
        grid[path[i].GetX()][path[i].GetY()].cell.setTexture(pathTexture);
        std::cout << path[i].GetX() << path[i].GetY() << std::endl;
    }
    
}

void Draw::CreateOpenNodes(Node node)
{
    node.cell.setTexture(nodeTexture);    
}

int Draw::LoadBlockTexture()
{
    if (!cellTexture.loadFromFile("images/block_idle.bmp"))
    {
        std::cout << "Could not load block texture" << std::endl;
        return 0;
    }
}

int Draw::LoadStartTexture()
{
    if (!startTexture.loadFromFile("images/block_start.bmp"))
    {
        std::cout << "Could not load start texture" << std::endl;
        return 0;
    }
}

int Draw::LoadEndTexture()
{
    if (!endTexture.loadFromFile("images/block_dest.bmp"))
    {
        std::cout << "Could not load end texture" << std::endl;
        return 0;
    }
}

int Draw::LoadWallTexture()
{
    if (!wallTexture.loadFromFile("images/block_wall.bmp"))
    {
        std::cout << "Could not load wall texture" << std::endl;
        return 0;
    }
}

int Draw::LoadPathTexture()
{
    if (!pathTexture.loadFromFile("images/block_path.bmp"))
    {
        std::cout << "Could not load path texture" << std::endl;
        return 0;
    }
}


int Draw::LoadNodesTexture()
{
    if (!nodeTexture.loadFromFile("images/block_open.bmp"))
    {
        std::cout << "Could not Node texture" << std::endl;
        return 0;
    }
}