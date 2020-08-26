#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

class Draw
{
	public:
		Draw();

		sf::Texture cellTexture;
		sf::Texture startTexture;
		sf::Texture endTexture;
		sf::Texture pathTexture;
		sf::Texture wallTexture;

		sf::Sprite cell[50][28];

		void CreateGrid();
		void RefreshGrid();
		int LoadBlockTexture();
		int LoadStartTexture();
		int LoadEndTexture();
		int LoadPathTexture();
		int LoadWallTexture();

};


