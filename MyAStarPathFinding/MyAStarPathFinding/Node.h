#pragma once
using namespace std;
#include <list> 
#include <SFML\Graphics\Sprite.hpp>
#include <vector>

class Node
{
    public :
        Node();
        Node(int* x, int* y);  //: gridX(x), gridY(y) , gCost(0), hCost(0), isWall(0), previousNode(NULL)
        bool isWall;
        std::vector<Node> neighbours;
        sf::Sprite cell;
        void AddNeighbours(Node grid[][28],int x, int y);
        int FCost();
        int GetX();
        int GetY();
        int GetGCost();
        int GetHCost();
        Node* GetPreviousNode();
        void SetGCost(int value);
        void SetHCost(int value);  
        void SetX(int value);
        void SetY(int value);
        void SetPreviousNode(Node* node);

        bool operator ==(const Node& B);
    private :
        int gCost;
        int hCost;
        int gridX;
        int gridY;
        Node* previousNode;
};

