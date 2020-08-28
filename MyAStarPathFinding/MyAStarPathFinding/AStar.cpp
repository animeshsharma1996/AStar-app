#include "AStar.h"
#include <iostream>

vector<Node> AStar::openList;

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
	if (!IsValidPath(start, end))  
		cout << "Path is not valid" << endl;

	//vector<Node> openList;
	vector<Node> closedList;
	openList.push_back(*start);

	start->gCost = 0;
	start->hCost = Heuristic(start, end);

	while (!openList.empty())
	{
		int leastFNode = 0;                                                                  //a) find the node with the least f in open list
		for (size_t i = 0 ; i < openList.size() ; ++i)
		{
			if (openList[i].FCost() < openList[leastFNode].FCost()) 
			{ 
				leastFNode = i; 
			}
			else if (openList[i].FCost() == openList[leastFNode].FCost())					 //Tie breaker 							
			{
				if (openList[i].hCost < openList[leastFNode].hCost) 
				{ 
					leastFNode = i; 
				}
			}

		}
		Node currentNode = openList[leastFNode]; 
																							//d) i) if successor is the goal, stop search
		if (&currentNode == end)
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

		vector<Node>::iterator it = openList.begin() + leastFNode;
		openList.erase(it);															        //b) Pop leastFNode off the open list
		closedList.push_back(currentNode);

		currentNode.cell.setColor(sf::Color::Red);
		currentNode.AddNeighbours(grid,currentNode.gridX,currentNode.gridY);
		vector<Node> neighbours = currentNode.neighbours;								    //c) Generate neighbours for leastFNode
		for (size_t i = 0; i < neighbours.size(); ++i)
		{
			if (neighbours[i].isWall && &neighbours[i] != end)
			{ 
				closedList.push_back(neighbours[i]); 
				continue; 
			}							

	/*		std::cout << "Current" << currentNode.gridX << " " << currentNode.gridY << " ";
			std::cout << "Neighbour" <<neighbours[i].gridX << " " << neighbours[i].gridY << std::endl;*/

			vector<Node>::iterator iterator2 = std::find(closedList.begin(), closedList.end(), neighbours[i]);
			if (iterator2 == closedList.end())												// iii) if a node with the same position as 	
			{									
				int tempGCost = currentNode.gCost + 1;
				bool newPath = false;

				vector<Node>::iterator iterator1 = std::find(openList.begin(), openList.end(), neighbours[i]);
				if (iterator1 != openList.end())											        // ii) if a node with the same position as        
				{																					
					if (tempGCost < neighbours[i].gCost)
					{
						neighbours[i].gCost = tempGCost;
						newPath = true;
					}
				}
				else
				{
					neighbours[i].gCost = tempGCost;
					newPath = true;
					openList.push_back(neighbours[i]);
				}

				if (newPath)
				{
					neighbours[i].hCost = Heuristic(&neighbours[i],end);
					neighbours[i].previousNode = &currentNode;
				}
			}
		}

	}

	return vector<Node>();
}
