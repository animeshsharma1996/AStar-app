#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

static class Draw
{
	public:
		static void CreateGrid(sf::Texture cellTexture, sf::Sprite cell[][28]);
		static int LoadBlockTexture(sf::Texture cellTexture);
		static int LoadStartTexture(sf::Texture startTexture);
		static int LoadEndTexture(sf::Texture endTexture);
		static int LoadPathTexture(sf::Texture pathTexture);
		static int LoadWallTexture(sf::Texture wallTexture);

};


