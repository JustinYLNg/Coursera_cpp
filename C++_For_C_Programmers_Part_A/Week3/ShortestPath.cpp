/*
 * Created on 23 April, 2023
 * Author: Justin Ng
 * Email: justinngyl@gmail.com
 */
#include <assert.h>
#include <algorithm>

#include "ShortestPath.hpp"

//compute the distance from source node to destination node
int ShortestPath::computeDijkstra(const Graph &graph, int u, int v)
{
    int numOfNodes = graph.getNumOfVertices();
    assert(u >= 0 && u < numOfNodes && v >= 0 && v < numOfNodes);

    markedNodes.clear();
    markedNodes.resize(numOfNodes, -1);

    PriorityQueue pq(graph.getNodes());
    pq.changePriority(pqNode(u, 0));

    while(pq.size() > 0)
    {
        pqNode topElement = pq.top();
        pq.minPriority();

        if(topElement.cost == INF)
        {
            return INF;
        }
        if(topElement.symbol == v)
        {
            return topElement.cost;
        }
        
        //find neighboring nodes
        auto adjacentNodes = graph.neighbors(topElement.symbol);
        //relax path
        pqNode tempNode;
        for (int i = 0; i < adjacentNodes.size(); i++)
        {
            tempNode.symbol = adjacentNodes[i];
            if (pq.doesContain(tempNode))
            {
                if(topElement.cost + graph.getEdgeValue(topElement.symbol,tempNode.symbol) < tempNode.cost)
                {
                    markedNodes[tempNode.symbol] = topElement.symbol;
                    tempNode.cost = topElement.cost + graph.getEdgeValue(topElement.symbol, tempNode.symbol);
                    pq.changePriority(tempNode);
                }
            }
                
        }
    }
    return INF;
}

//find shortest path between u-v and returns the sequence of vertices representing shorest path
std::vector<int> ShortestPath::getShortestPath(const Graph &graph, int u, int v)
{
    std::vector<int> path;
    if(computeDijkstra(graph, u, v) == INF)
    {
        return path;
    }
    int current = v;
    do
    {
        path.push_back(current);
        current = markedNodes[current];

    } while (current != -1);

    std::reverse(path.begin(), path.end());
    return path;
}

//return the path cost associated with the shortest path
int ShortestPath::getPathCost(const Graph &graph, int u, int v)
{
    return computeDijkstra(graph, u, v);
}