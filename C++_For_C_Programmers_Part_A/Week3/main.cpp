#include <iostream>
#include <limits>

#include "Graph.hpp"
#include "PriorityQueue.hpp"
#include "ShortestPath.hpp"

int main()
{
    float densities[2] = {0.2, 0.4};
    int range = 10;
    int V = 50;
    int src = 0;
    float average = 0.0;

    ShortestPath route;
    for(int i=0; i<2; i++)
    {
        int sum = 0;
        int count = 0;
        Graph g(V, densities[i], range);

        for (int dest = 0; dest < V; dest++)
        {
            int pathCost = route.getPathCost(g, src, dest);
            if(pathCost != INF)
            {
                sum += pathCost;
                count++;
            }
        }
        average = sum / count;
        std::cout << "For density " << densities[i] << ", average path length is " << average << std::endl;
    }
    return 0;
}
