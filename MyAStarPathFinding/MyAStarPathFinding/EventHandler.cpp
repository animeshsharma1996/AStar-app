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
	startPos.x = abs(mousePosition.x / 16);
	startPos.y = abs(mousePosition.y / 16);
}

void EventHandler::SetEndPos(sf::Vector2i mousePosition)
{
	endPos.x = abs(mousePosition.x / 16);
	endPos.y = abs(mousePosition.y / 16);
}

void EventHandler::SetWallsPos(sf::Vector2i mousePosition)
{
	sf::Vector2i wallPos;
	wallPos.x = abs(mousePosition.x / 16);
	wallPos.y = abs(mousePosition.y / 16);
	wallsPositions.push_back(wallPos);
}

sf::Vector2i EventHandler::GetStartPos() { return startPos; }

sf::Vector2i EventHandler::GetEndPos() { return endPos; }

std::vector<sf::Vector2i> EventHandler::GetWallPos() { return wallsPositions; }

void EventHandler::CheckEnterStart(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && (GetStartPos().x >= 0)) 
		SetStartCheck(true);
}

void EventHandler::CheckEnterEnd(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && GetStartCheck() && (GetEndPos().x >= 0))
		SetEndCheck(true);
}

void EventHandler::CheckEnterWallsSet(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && GetStartCheck() && GetWallsCheck() && (!wallsPositions.empty()))
		SetWallsCheck(true);
}

