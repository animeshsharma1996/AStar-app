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
        bool isWall;
        std::vector<Node> neighbours;
        Node* previousNode;
        sf::Sprite cell;
        void AddNeighbours(Node grid[][28],int x, int y);
        int FCost();
        int GetGCost();
        int GetHCost();
        void SetGCost(int value);
        void SetHCost(int value);

        bool operator ==(const Node& B);
    private :
        int gCost;
        int hCost;
};

