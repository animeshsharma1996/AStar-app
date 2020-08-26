#include "EventHandler.h"

bool EventHandler::hasStarted = false;
bool EventHandler::hasEnded = false;
sf::Vector2i EventHandler::startPos(0, 0);
sf::Vector2i EventHandler::endPos(0, 0);

void EventHandler::SetStarted(bool _hasEnded)
{
	hasStarted = _hasEnded;
}

bool EventHandler::GetStarted()
{
	return hasStarted;
}

void EventHandler::SetEnded(bool _hasEnded)
{
	hasEnded = _hasEnded;
}

bool EventHandler::GetEnded()
{
	return hasEnded;
}

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

sf::Vector2i EventHandler::GetStartPos()
{
	return startPos;
}

sf::Vector2i EventHandler::GetEndPos()
{
	return endPos;
}

void EventHandler::CheckEnterStart(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter)
	{
		SetStarted(true);
	}
}

void EventHandler::CheckEnterEnd(sf::Event e)
{
	if (e.key.code == sf::Keyboard::Enter && GetStarted())
	{
		SetEnded(true);
	}
}
