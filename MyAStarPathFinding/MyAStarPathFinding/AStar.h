#pragma once
#include "Node.h"
#include <list>
#include "Draw.h"

static class AStar
{
public :
	static vector<Node> FindPath(Node grid[][28], Node start, Node end);
	static vector<Node> openList;
	static vector<Node> closedList;
private:
	static bool IsValidPath(Node* start, Node* end);
	static bool Comparer(Node* a, Node* b);
	static int Heuristic(Node* a, Node* b);
	static vector<Node> ReturnFoundPath(vector<Node> path, Node currentNode, Node start, Node end);
	static int LeastFNodeOpenList();
	static void SearchNeighbours(std::vector<Node> neighbours, Node currentNode, Node end);
};

