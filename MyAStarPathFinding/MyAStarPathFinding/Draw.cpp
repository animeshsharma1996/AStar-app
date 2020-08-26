#include "Draw.h"

  /*  sf::Texture cellTexture;
    sf::Texture startTexture;
    sf::Texture endTexture;
    sf::Texture pathTexture;
    sf::Texture wallTexture;

    sf::Sprite cell[50][28];*/

    
    Draw::Draw() {}

    void Draw::CreateGrid()
    {
        int size = 16; //each block is 16 width wide
        for (int i = 0; i < 50; ++i)
        {
            for (int j = 0; j < 28; ++j)
            {
                cell[i][j].setTexture(cellTexture);
                cell[i][j].setPosition(size * i, size * j);
            }
        }
    }

    void Draw::RefreshGrid()
    {
        for (int i = 0; i < 50; ++i)
        {
            for (int j = 0; j < 28; ++j)
            {
                cell[i][j].setTexture(cellTexture);
            }
        }
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

