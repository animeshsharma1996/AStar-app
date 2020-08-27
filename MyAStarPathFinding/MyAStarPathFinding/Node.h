#pragma once
using namespace std;
#include <list> 
#include <SFML\Graphics\Sprite.hpp>
#include <vector>

class Node
{
    public :
        Node();
        Node(int x, int y);  //: gridX(x), gridY(y) , gCost(0), hCost(0), isWall(0), previousNode(NULL)
        int gridX;
        int gridY;
        int gCost;
        int hCost;
        bool isWall;
        std::vector<Node> neighbours;
        Node* previousNode;
        sf::Sprite cell;
        void AddNeighbours(Node grid[][28],int x, int y);
        int FCost();
    private :
        
};

