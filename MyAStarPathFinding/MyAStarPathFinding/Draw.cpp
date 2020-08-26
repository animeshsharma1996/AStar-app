#include "Draw.h"

    void Draw::CreateGrid(sf::Texture cellTexture, sf::Sprite cell[][28])
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

    int Draw::LoadBlockTexture(sf::Texture cellTexture)
    {
        if (!cellTexture.loadFromFile("images/block_idle.bmp"))
        {
            std::cout << "Could not load block texture" << std::endl;
            return 0;
        }
    }

    int Draw::LoadStartTexture(sf::Texture startTexture)
    {
        if (!startTexture.loadFromFile("images/block_start.bmp"))
        {
            std::cout << "Could not load start texture" << std::endl;
            return 0;
        }
    }

    int Draw::LoadEndTexture(sf::Texture endTexture)
    {
        if (!endTexture.loadFromFile("images/block_dest.bmp"))
        {
            std::cout << "Could not load end texture" << std::endl;
            return 0;
        }
    }

    int Draw::LoadWallTexture(sf::Texture wallTexture)
    {
        if (!wallTexture.loadFromFile("images/block_wall.bmp"))
        {
            std::cout << "Could not load wall texture" << std::endl;
            return 0;
        }
    }

    int Draw::LoadPathTexture(sf::Texture pathTexture)
    {
        if (!pathTexture.loadFromFile("images/block_path.bmp"))
        {
            std::cout << "Could not load path texture" << std::endl;
            return 0;
        }
    }

