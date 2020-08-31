#include "AStar.h"
#include <iostream>

vector<Node> AStar::openList;
vector<Node> AStar::closedList;

bool AStar::IsValidPath(Node* start, Node* end)
{
	if (end == NULL)
		return false;
	if (start == NULL)
		return false;
	if (start == end)
		return false;
	if (end->isWall)
		return false;

	return true;
}

bool AStar::Comparer(Node* a, Node* b)
{
	return (a->GetX() == b->GetX() && a->GetY() == b->GetY());
}

int AStar::Heuristic(Node* a, Node* b)
{
	int distanceX = abs(a->GetX() - b->GetX());
	int distanceY = abs(a->GetY() - b->GetY());
	return (14 * std::min(distanceX, distanceY) + 10 * abs(distanceX - distanceY));
}

vector<Node> AStar::FindPath(Draw* draw, Node grid[][28], Node start, Node end)
{
	vector<Node> path;

	if (!IsValidPath(&start, &end))
		cout << "Path is not valid" << endl;

	start.SetGCost(0);
	start.SetHCost(Heuristic(&start, &end));


	openList.push_back(start);

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
		if (Comparer(&currentNode, &end))
		{
			Node tempCNode = currentNode;
			path.push_back(currentNode);
			while (!Comparer(&tempCNode.GetPreviousNode(), &start))
			{
				tempCNode = tempCNode.GetPreviousNode();
				//cout << tempCNode.GetX() << "  " << tempCNode.GetY() << endl;
				path.push_back(tempCNode);
			}

			return path;
		}

		vector<Node>::iterator it = std::find(openList.begin(), openList.end(), currentNode);
		openList.erase(it);															        //b) Pop leastFNode off the open list
		closedList.push_back(currentNode);

		currentNode.AddNeighbours(grid, currentNode.GetX(), currentNode.GetY());
		vector<Node> neighbours = currentNode.neighbours;								    //c) Generate neighbours for leastFNode

		for (size_t i = 0; i < neighbours.size(); ++i)
		{
			if (neighbours[i].isWall)
			{
				//closedList.push_back(neighbours[i]);
				continue;
			}

			vector<Node>::iterator iterator2 = std::find(closedList.begin(), closedList.end(), neighbours[i]);
			if (iterator2 != closedList.end()) continue;

			int tempGCost = currentNode.GetGCost() + Heuristic(&currentNode, &neighbours[i]);

			if (tempGCost < neighbours[i].GetGCost())
			{
				neighbours[i].SetPreviousNode(currentNode);
				neighbours[i].SetGCost(tempGCost);
				neighbours[i].SetHCost(Heuristic(&neighbours[i], &end));

				vector<Node>::iterator iterator1 = std::find(openList.begin(), openList.end(), neighbours[i]);
				if (iterator1 == openList.end())
				{
					openList.push_back(neighbours[i]);
				}
			}

		}

	}

	openList.erase(std::find(openList.begin(), openList.end(), end));
	closedList.erase(std::find(closedList.begin(), closedList.end(), start));

	return path;
}