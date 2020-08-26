#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <time.h>
#include <iostream>
#include "Connector.hpp"
#include "Draw.h"
using namespace sf;



int main()
{
        sf::RenderWindow window(sf::VideoMode(800, 450), "The AStar! (press SPACE)");

        Draw *draw = new Draw();

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

                if (e.type == Event::MouseButtonPressed)
                {
                    if (e.key.code == Mouse::Left)
                    {
                        draw->cell[abs(mousePosition.x / 16)][abs(mousePosition.y / 16)].setTexture(draw->startTexture);
                    }
                }
            }

            //draw cells
            window.clear();
            for (int i = 0; i < 50; ++i)
                for (int j = 0; j < 28; ++j)
                {
                    window.draw(draw->cell[i][j]);
                }
            window.display();
        }

        return 0;
}



