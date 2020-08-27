#include "EventHandler.h"
#include <iostream>

bool EventHandler::hasStarted = false;
bool EventHandler::hasEnded = false;
sf::Vector2i EventHandler::startPos(-10, -10);
sf::Vector2i EventHandler::endPos(-10, -10);
std::vector<sf::Vector2i> EventHandler::wallPositions;

void EventHandler::SetStarted(bool _hasEnded) { hasStarted = _hasEnded; }

bool EventHandler::GetStarted()  { return hasStarted; }

void EventHandler::SetEnded(bool _hasEnded) { hasEnded = _hasEnded; }

bool EventHandler::GetEnded()  { return hasEnded; }

void EventHandler::SetStartPos(sf::Vector2i mousePosition)
{
	startPos.x = abs(mousePosition.x / 16);
	startPos.y = abs(mousePosition.y / 16);
}

void EventHandler::SetEndPos(sf::Vector2i mousePosition)
{
	endPos.x = abs(mousePosition.x / 16);
	endPos.y = abs(mousePosition.y / 16);
}

void EventHandler::SetWallPos(sf::Vector2i mousePosition)
{
	sf::Vector2i wallPos;
	wallPos.x = abs(mousePosition.x / 16);
	wallPos.y = abs(mousePosition.y / 16);
	wallPositions.push_back(wallPos);
}

sf::Vector2i EventHandler::GetStartPos() { return startPos; }

sf::Vector2i EventHandler::GetEndPos() { return endPos; }

std::vector<sf::Vector2i> EventHandler::GetWallPos() { return wallPositions; }

void EventHandler::CheckEnterStart(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && (GetStartPos().x >= 0)) 
		SetStarted(true);
}

void EventHandler::CheckEnterEnd(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && GetStarted() && (GetEndPos().x >= 0))
		SetEnded(true);
	
}

