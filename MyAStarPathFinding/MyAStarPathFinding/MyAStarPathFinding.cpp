#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <iostream>
#include "Connector.hpp"
#include "Draw.h"
using namespace sf;

sf::Texture cellTexture;
sf::Texture startTexture;
sf::Texture endTexture;
sf::Texture pathTexture;
sf::Texture wallTexture;

sf::Sprite cell[50][28];    //grids

int main()
{
        sf::RenderWindow window(sf::VideoMode(800, 450), "The AStar! (press SPACE)");

        Draw::LoadBlockTexture(cellTexture);
        Draw::LoadStartTexture(startTexture);
        Draw::CreateGrid(cellTexture, cell);

        while (window.isOpen())
        {
            Vector2i mousePosition = Mouse::getPosition(window);

            sf::Event e;
            while (window.pollEvent(e))
            {
                if (e.type == sf::Event::Closed) window.close();

                if (e.type == Event::MouseButtonPressed)
                {
                    if (e.key.code == Mouse::Left)
                    {
                        cell[abs(mousePosition.x / 16)][abs(mousePosition.y / 16)].setTexture(startTexture);
                    }
                }
            }

            //draw cells
            window.clear();
            for (int i = 0; i < 50; ++i)
                for (int j = 0; j < 28; ++j)
                {
                    window.draw(cell[i][j]);
                }
            window.display();
        }

        return 0;
}



