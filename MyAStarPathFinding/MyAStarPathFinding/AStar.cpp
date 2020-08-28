#include "AStar.h"
#include <iostream>

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

vector<Node> AStar::FindPath(Node* start, Node* end)
{
	if (!IsValidPath(start, end))  cout << "Path is not valid" << endl;

	vector<Node> openList;
	vector<Node> closedList;
	openList.push_back(*start);

	while (!openList.empty())
	{
		vector<Node>::iterator it = openList.begin();
		int leastFNode = 0;                                                                  //a) find the node with the least f in open list
		for (int i = 0 ; i < openList.size() ; ++i, ++it)
		{
			if (openList[i].FCost() < openList[leastFNode].FCost()) { leastFNode = i;}
			else if (openList[i].FCost() == openList[leastFNode].FCost())					 //Tie breaker 							
			{
				if (openList[i].hCost < openList[leastFNode].hCost)
					leastFNode = i;
			}
		}
		
		Node currentNode = openList[leastFNode]; 
		openList.erase(it);															        //b) Pop leastFNode off the open list

		vector<Node> neighbours = currentNode.neighbours;								    //c) Generate neighbours for leastFNode
		for (int i = 0; i < neighbours.size(); ++i)
		{
			neighbours[i].previousNode = &currentNode;

			if (neighbours[i].isWall) { closedList.push_back(neighbours[i]); continue; }

			if (&neighbours[i] == end)												       //d) i) if successor is the goal, stop search
			{																				
				vector<Node> path;	
				Node tempCNode = currentNode;
				path.push_back(currentNode);
				while (tempCNode.previousNode != start)
				{
					path.push_back(*tempCNode.previousNode);
					tempCNode = *tempCNode.previousNode;
				}
				return path;
			}																				
		
			neighbours[i].gCost = currentNode.gCost + Heuristic(&neighbours[i], &currentNode);		//successor.g = q.g + distance between successor and q	
			neighbours[i].hCost = Heuristic(&neighbours[i], end);									//successor.h = distance from goal to successor
																									
			vector<Node>::iterator neighboursIt = std::find(openList.begin(), openList.end(), neighbours[i]);
			if (neighboursIt != openList.end())											        // ii) if a node with the same position as        
			{																					// successor is in the OPEN list which has a
				if (currentNode.FCost() < neighbours[i].FCost())								// lower f than successor, skip this successor
				{
					continue;
				}
			}

			if (neighboursIt != closedList.end())												// iii) if a node with the same position as 	
			{																					// successor  is in the CLOSED list which has 
				if (currentNode.FCost() < neighbours[i].FCost())								// a lower f than successor, skip this successor
				{																				// otherwise, add  the node to the open list
					continue;
				}
				else
				{
					openList.push_back(neighbours[i]);
				}
			}

		}

		closedList.push_back(currentNode);												    //e) push q on the closed list
	}

	return vector<Node>();
	cout << "No Path Found" << endl;
}
