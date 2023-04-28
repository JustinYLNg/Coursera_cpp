/*
 * Created on 23 April, 2023
 * Author: Justin Ng
 * Email: justinngyl@gmail.com
 */
#ifndef SHORTEST_PATH_HPP
#define SHORTEST_PATH_HPP

#include <limits>
#include <vector>

#include "Graph.hpp"
#include "PriorityQueue.hpp"

//Implements Dijkstra's Algorithm
class ShortestPath
{
    public:
        //find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w
        std::vector<int> getShortestPath(const Graph& graph, int u, int v);

        //return the path cost associated with the shortest path
        int getPathCost(const Graph& graph, int u, int v);

    private:
        //list of vertices gone through
        std::vector<int> markedNodes;

        //compute the distance from source node to destination node
        int computeDijkstra(const Graph &graph, int u, int v);
};

#endif