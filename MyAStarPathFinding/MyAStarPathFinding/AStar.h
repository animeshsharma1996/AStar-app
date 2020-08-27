#pragma once
#include "Node.h"
#include <list>

static class AStar
{
public :
	static vector<Node> FindPath(Node* start, Node* end);

private:
	static bool IsValidPath(Node* start, Node* end);
	static int Heuristic(Node* a, Node* b);

};

