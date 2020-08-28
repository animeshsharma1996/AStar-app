#include "Node.h"

Node::Node(int x, int y)
{
	gridX = x;
	gridY = y;
	gCost = 0;
	hCost = 0;
	previousNode = NULL;
	isWall = false;
}

int Node::FCost() {	return (gCost+hCost); }


Node::Node()
{
	gridX = 0;
	gridY = 0;
	gCost = 0;
	hCost = 0;
	previousNode = NULL;
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
	return ((this->gridX == B.gridX) && (this->gridY == B.gridY));
}
