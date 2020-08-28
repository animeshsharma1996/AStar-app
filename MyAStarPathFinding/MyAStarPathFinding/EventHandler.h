#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class EventHandler
{
	public :
		static void SetStartCheck(bool _hasStarted);
		static bool GetStartCheck();
		static void SetEndCheck(bool _hasEnded);
		static bool GetEndCheck(); 
		static void SetWallsCheck(bool _areWallsSet);
		static bool GetWallsCheck(); 
		static void SetStartPos(sf::Vector2i mousePosition);
		static void SetEndPos(sf::Vector2i mousePosition);
		static void SetWallsPos(sf::Vector2i mousePosition);
		static sf::Vector2i GetStartPos();
		static sf::Vector2i GetEndPos();
		static std::vector<sf::Vector2i> GetWallPos();

		static void CheckEnterStart(sf::Event e);
		static void CheckEnterEnd(sf::Event e);
		static void CheckEnterWallsSet(sf::Event e);

		static bool CheckWallsOverlap(sf::Vector2i mousePosition);

	private :
		static bool hasStarted ;
		static bool hasEnded ;
		static bool areWallsSet ;
		static sf::Vector2i startPos;
		static sf::Vector2i endPos;
		static std::vector<sf::Vector2i> wallsPositions;
};

