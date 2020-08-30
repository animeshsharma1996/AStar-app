#include "Node.h"

Node::Node(int x, int y)
{
	gridX = x;
	gridY = y;
	gCost = 10000;
	hCost = 0;
	isWall = false;
}

int Node::FCost() {	return (gCost+hCost); }

int Node::GetX() { return gridX; }

int Node::GetY() { return gridY; }

int Node::GetGCost() { return gCost; }

int Node::GetHCost() { return hCost; }

Node Node::GetPreviousNode() {	return previousNode[0]; }

void Node::SetGCost(int value) { gCost = value; }

void Node::SetHCost(int value) { hCost = value; }

void Node::SetX(int value) { gridX = value; }

void Node::SetY(int value) { gridY = value; }

void Node::SetPreviousNode(Node node) { previousNode.push_back(node);}

Node::Node()
{
	gridX = 0;
	gridY = 0;
	gCost = 0;
	hCost = 0;
	isWall = false;
}

void Node::AddNeighbours(Node grid[][28],int x, int y)
{
	if (x < 49)
		neighbours.push_back(grid[x+1][y]);
	if (x > 0)
		neighbours.push_back(grid[x-1][y]);
	if (y < 27)
		neighbours.push_back(grid[x][y+1]);
	if (y > 0)
		neighbours.push_back(grid[x][y-1]);
	if (x < 49 && y < 27)
		neighbours.push_back(grid[x+1][y+1]);
	if (x > 0 && y < 27)
		neighbours.push_back(grid[x-1][y+1]);
	if (x < 49 && y > 0)
		neighbours.push_back(grid[x+1][y-1]);
	if (x > 0 && y > 0)
		neighbours.push_back(grid[x-1][y-1]);
}

bool Node::operator ==(const Node& B)
{
	return ((gridX == B.gridX) && (gridY == B.gridY));
}
