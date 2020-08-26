#pragma once
#include <SFML/Graphics.hpp>

class EventHandler
{
public :
	static void SetStarted(bool _hasStarted);
	static bool GetStarted();
	static void SetEnded(bool _hasEnded);
	static bool GetEnded();
	static void SetStartPos(sf::Vector2i mousePosition);
	static void SetEndPos(sf::Vector2i mousePosition);
	static sf::Vector2i GetStartPos();
	static sf::Vector2i GetEndPos();

	static void CheckEnterStart(sf::Event e);
	static void CheckEnterEnd(sf::Event e);

private:
	static bool hasStarted ;
	static bool hasEnded ;
	static sf::Vector2i startPos;
	static sf::Vector2i endPos;
};

