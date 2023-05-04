#include "DisjointSet.hpp"
#include "Graph.hpp"
#include "KruskalMST.hpp"

#include <algorithm>

int KruskalMST::makeMST(const Graph &graph, std::vector<Edge>& edges) const
{
    //get data from adjacent matrix
    int numOfNodes = graph.getNumOfVertices();

    std::vector<Edge> candidateEdges;

    //traverse half of the adjacency matrix, cutoff at diagonal where cells contain zeroes
    //assumed undirected graph
    for(int i=0; i<numOfNodes-1; i++)
    {
        for(int j=i+1; j<numOfNodes; j++)
        {
            //check if there is edge
            if (graph.isAdjacent(i, j))
            {
                candidateEdges.push_back(Edge(i, j, graph.getEdgeValue(i, j)));
            }
        }
    }
    //sort vector of edge objects according to their costs.
    //edge with lighter cost will be added first
    std::sort(candidateEdges.begin(), candidateEdges.end(), Edge());

    //create a disjoint set object
    DisjointSet djSet(numOfNodes);

    int totalCost = 0;

    for (int i = 0; i<candidateEdges.size(); i++)
    {
        if(edges.size() >= numOfNodes-1)
        {
            break;
        }
        if (djSet.findSet(candidateEdges[i].src) != djSet.findSet(candidateEdges[i].dest))
        {
            totalCost += candidateEdges[i].cost;
            edges.push_back(candidateEdges[i]);
            djSet.unionSets(candidateEdges[i].src, candidateEdges[i].dest);
        }
    }
        

    return totalCost;
}