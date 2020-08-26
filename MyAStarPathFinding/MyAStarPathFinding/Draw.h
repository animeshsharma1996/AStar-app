#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

class Draw
{
	public:
		static sf::Texture cellTexture;
		static sf::Texture startTexture;
		static sf::Texture endTexture;
		static sf::Texture pathTexture;
		static sf::Texture wallTexture;

		sf::Sprite cell[50][28];

		static void CreateGrid(sf::Texture cellTexture, sf::Sprite cell[][28]);
		static int LoadBlockTexture(sf::Texture cellTexture);
		static int LoadStartTexture(sf::Texture startTexture);
		static int LoadEndTexture(sf::Texture endTexture);
		static int LoadPathTexture(sf::Texture pathTexture);
		static int LoadWallTexture(sf::Texture wallTexture);

};


