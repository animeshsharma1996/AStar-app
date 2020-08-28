#include "EventHandler.h"
#include <iostream>

bool EventHandler::hasStarted = false;
bool EventHandler::hasEnded = false;
bool EventHandler::areWallsSet = false;
sf::Vector2i EventHandler::startPos(-10, -10);
sf::Vector2i EventHandler::endPos(-10, -10);
std::vector<sf::Vector2i> EventHandler::wallsPositions;

void EventHandler::SetStartCheck(bool _hasEnded) { hasStarted = _hasEnded; }

bool EventHandler::GetStartCheck()  { return hasStarted; }

void EventHandler::SetEndCheck(bool _hasEnded) { hasEnded = _hasEnded; }

bool EventHandler::GetEndCheck()  { return hasEnded; }

void EventHandler::SetWallsCheck(bool _areWallsSet) { areWallsSet = _areWallsSet; }

bool EventHandler::GetWallsCheck() { return areWallsSet; }

void EventHandler::SetStartPos(sf::Vector2i mousePosition)
{
	startPos.x = floor(mousePosition.x / 16);
	startPos.y = (mousePosition.y / 16);
}

void EventHandler::SetEndPos(sf::Vector2i mousePosition)
{
	endPos.x = floor(mousePosition.x / 16);
	endPos.y = floor(mousePosition.y / 16);
}

void EventHandler::SetWallsPos(sf::Vector2i mousePosition)
{
	sf::Vector2i wallPos;
	wallPos.x = floor(mousePosition.x / 16);
	wallPos.y = floor(mousePosition.y / 16);
	wallsPositions.push_back(wallPos);
}

sf::Vector2i EventHandler::GetStartPos() { return startPos; }

sf::Vector2i EventHandler::GetEndPos() { return endPos; }

std::vector<sf::Vector2i> EventHandler::GetWallPos() { return wallsPositions; }

void EventHandler::CheckEnterStart(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && (GetStartPos().x >= 0))
	{
		SetStartCheck(true);
		std::cout << "Start is Set" << std::endl;
	}
}

void EventHandler::CheckEnterEnd(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && GetStartCheck() && (GetEndPos().x >= 0))
	{
		SetEndCheck(true);
		std::cout << "End is Set" << std::endl;
	}
}

void EventHandler::CheckEnterWallsSet(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && GetStartCheck() && GetEndCheck() && (!wallsPositions.empty()))
	{
		SetWallsCheck(true);
		std::cout << "Walls are Set" << std::endl;
	}
}

bool EventHandler::CheckWallsOverlap(sf::Vector2i mousePosition)
{
	bool startOvelapX = (floor(mousePosition.x / 16) == startPos.x);
	bool startOvelapY = (floor(mousePosition.y / 16) == startPos.y);

	bool endOvelapX = (floor(mousePosition.x / 16) == endPos.x);
	bool endOvelapY = (floor(mousePosition.y / 16) == endPos.y);

	return ((startOvelapX && startOvelapY) || (endOvelapX && endOvelapY));
}

