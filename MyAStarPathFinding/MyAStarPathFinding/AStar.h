#pragma once
#include "Node.h"
#include <list>
#include "Draw.h"

static class AStar
{
public :
	static vector<Node> FindPath(Draw* draw,Node grid[][28], Node* start, Node* end);
	static vector<Node> openList;
private:
	static bool IsValidPath(Node* start, Node* end);
	static int Heuristic(Node* a, Node* b);
};

