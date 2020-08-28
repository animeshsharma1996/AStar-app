#include "AStar.h"
#include <iostream>

//vector<Node> AStar::openList;

bool AStar::IsValidPath(Node* start, Node* end)
{
	if(end == NULL)
		return false;
	if(start == NULL)
		return false;
	if(start == end)
		return false;
	if(end->isWall)
		return false;

	return true;
}

int AStar::Heuristic(Node* a, Node* b)
{
	return (abs(a->gridX - b->gridX) + abs(a->gridY - b->gridY));
}

vector<Node> AStar::FindPath(Draw* draw,Node grid[][28], Node* start, Node* end)
{
	vector<Node> path;

	if (!IsValidPath(start, end))  
		cout << "Path is not valid" << endl;

	vector<Node> openList;
	vector<Node> closedList;
	openList.push_back(*start);

	start->SetGCost(0);
	start->SetHCost(Heuristic(start, end));

	while (!openList.empty())
	{
		int leastFNode = 0;                                                                  //a) find the node with the least f in open list
		for (size_t i = 0; i < openList.size(); ++i)
		{
			if (openList[i].FCost() < openList[leastFNode].FCost())
			{
				leastFNode = i;
			}
			else if (openList[i].FCost() == openList[leastFNode].FCost())					 //Tie breaker 							
			{
				if (openList[i].GetHCost() < openList[leastFNode].GetHCost())
				{
					leastFNode = i;
				}
			}

		}
		Node currentNode = openList[leastFNode];
		//d) i) if successor is the goal, stop search
		if (&currentNode == end)
		{
			Node tempCNode = currentNode;
			path.push_back(currentNode);
			while (tempCNode.previousNode != start)
			{
				path.push_back(*tempCNode.previousNode);
				tempCNode = *tempCNode.previousNode;
			}
			return path;
		}

		draw->CreateOpenNodes(currentNode);
		vector<Node>::iterator it = openList.begin() + leastFNode;
		openList.erase(it);															        //b) Pop leastFNode off the open list
	
		closedList.push_back(currentNode);

		currentNode.AddNeighbours(grid,currentNode.gridX,currentNode.gridY);
		vector<Node> neighbours = currentNode.neighbours;								    //c) Generate neighbours for leastFNode
		for (size_t i = 0; i < neighbours.size(); ++i)
		{
			if (neighbours[i].isWall && &neighbours[i] != end)
			{
				closedList.push_back(neighbours[i]);
				continue;
			}

			vector<Node>::iterator iterator2 = std::find(closedList.begin(), closedList.end(), neighbours[i]);
			if (iterator2 != closedList.end()) continue;

			int tempGCost = currentNode.GetGCost() + Heuristic(&currentNode, &neighbours[i]);

			if (tempGCost < neighbours[i].GetGCost())
			{
				neighbours[i].previousNode = &currentNode;
				neighbours[i].SetHCost(Heuristic(&neighbours[i], end));
				cout << neighbours[i].GetHCost() << endl;
				vector<Node>::iterator iterator1 = std::find(openList.begin(), openList.end(), neighbours[i]);
				if (iterator1 != openList.end())
				{
					openList.push_back(neighbours[i]);
				}
			}

			cout << neighbours[i].GetHCost() << endl;
		}

	}

	return path;
}
