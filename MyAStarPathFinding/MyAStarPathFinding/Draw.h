#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "Node.h"

class Draw
{
	public:
		Draw()
		{
			for (int i = 0; i < 50; ++i)
			{
				for (int j = 0; j < 28; ++j)
				{
					Node* node = new Node(i, j);
					grid[i][j] = *node;
				}
			}
		}

		sf::Texture cellTexture;
		sf::Texture startTexture;
		sf::Texture endTexture;
		sf::Texture pathTexture;
		sf::Texture wallTexture;
		sf::Texture nodeTexture;

		Node grid[50][28];

		void CreateGrid();
		void RefreshGrid();
		void CreatePath(vector<Node> path);
		void CreateOpenNodes(vector<Node> nodes);
		int LoadBlockTexture();
		int LoadStartTexture();
		int LoadEndTexture();
		int LoadPathTexture();
		int LoadNodesTexture();
		int LoadWallTexture();

};


