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
}

void Node::AddNeighbours(Node grid[][28],int x, int y)
{
	if (x < 50)
		neighbours.push_back(grid[x+1][y]);
	if (x > 0)
		neighbours.push_back(grid[x-1][y]);
	if (x < 28)
		neighbours.push_back(grid[x][y+1]);
	if (x > 0)
		neighbours.push_back(grid[x][y-1]);
	if (x < 50 && y < 28)
		neighbours.push_back(grid[x+1][y+1]);
	if (x > 0 && y < 28)
		neighbours.push_back(grid[x-1][y+1]);
	if (x < 50 && y > 0)
		neighbours.push_back(grid[x+1][y-1]);
	if (x > 0 && y > 0)
		neighbours.push_back(grid[x-1][y-1]);
}
