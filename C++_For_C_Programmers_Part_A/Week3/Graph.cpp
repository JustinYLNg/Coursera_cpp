/*
 * Created on 23 April, 2023
 * Author: Justin Ng
 * Email: justinngyl@gmail.com
 */

#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "Graph.hpp"

//parameterized constructor
Graph::Graph(int v, float density, int distanceRange) : 
numOfVertices(v), numOfEdges(0)
{
    if(v <= 0)
    {
        this->numOfVertices = 0;
        return;
    }

    graph = std::vector<std::vector<int>>(v, std::vector<int>(v));
    srand(time(0));

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if(i==j)
            {
                //assumed undirected graph, diagonal of adjacency matrix is zeroes
                graph[i][j] = 0;
                continue;
            }
            float prob = (rand() % 100) / 100.0;
            if(prob < density)
            {
                int value = rand() % distanceRange + 1;
                addEdge(i, j, value);
            }
            //initializing weight of each edge in adjacency matrix to zero
            addEdge(i, j, 0);
        }
    }
}   //end constructor

//tests whether there is an edge from node x to node y
bool Graph::isAdjacent(int x, int y) const
{
    assert(x >= 0 && x <= numOfVertices && y >= 0 && y <= numOfVertices);
    return graph[x][y] > 0;
}

//lists all nodes y such that there is an edge from x to y
std::vector<int> Graph::neighbors(int x) const
{
    assert(x >= 0 && x <= numOfVertices);
    std::vector<int> tempList;
    for(int j=0; j<numOfVertices; j++)
    {
        if(isAdjacent(x, j))
        {
            tempList.push_back(j);
        }
    }
    return tempList;
}

//adds to graph the edge from x to y, if it is not there
void Graph::addEdge(int x, int y, int value)
{
    assert(x >= 0 && x <= numOfVertices && y >= 0 && y <= numOfVertices);
    if(!isAdjacent(x, y))
    {
        graph[x][y] = value;
        graph[y][x] = value;
    }
}

//removes the edge from x to y, if it is there
void Graph::deleteEdge(int x, int y)
{
    assert(x >= 0 && x <= numOfVertices && y >= 0 && y <= numOfVertices);
    if (isAdjacent(x, y))
    {
        graph[x][y] = 0;
        graph[y][x] = 0;
    }
}

//returns the value associated witht the node x
// int Graph::getNodeValue(int x)
// {
//     assert(x >= 0 && x <= numOfVertices);
//     return nodes[x];
// }

//sets the value associated with the node x to a
// void Graph::setNodeValue(int x, int a)
// {
//     assert(x >= 0 && x <= numOfVertices);
//     nodes[x] = a;
// }

//return vector of nodes
std::vector<int> Graph::getNodes() const
{
    std::vector<int> nodeList;
    for(int i=0; i<numOfVertices; i++)
    {
        nodeList.push_back(i);
    }
    return nodeList;
}

//returns the value associated with the edge E(x, y)
int Graph::getEdgeValue(int x, int y) const
{
    assert(x >= 0 && x <= numOfVertices && y >= 0 && y <= numOfVertices);
    return graph[x][y];
}

//sets the value associated with the edge E(x, y) to a
bool Graph::setEdgeValue(int x, int y, int a)
{
    if(graph[x][y] <= 0.0 && graph[y][x] <= 0.0)
    {
        return false;
    }
    graph[x][y] = a;
    graph[y][x] = a;
    return true;
}

//display adjacency matrix
void Graph::printMatrix()
{
    for(int i=0; i<numOfVertices; i++)
    {
        for (int j = 0; j < numOfVertices; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}