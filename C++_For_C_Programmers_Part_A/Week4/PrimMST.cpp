#include "Graph.hpp"
#include "PrimMST.hpp"
#include "PriorityQueue.hpp"

int PrimMST::makeMST(const Graph& graph, std::vector<Edge>& edges) const
{
    std::vector<int> visitedNodes(graph.getNumOfVertices(), -1);

    PriorityQueue pq(graph.getNodes());
    pqNode node(0, 0);
    pq.changePriority(node);

    int totalCost = 0;

    while(pq.size() > 0)
    {
        pqNode topElement = pq.top();
        pq.minPriority();

        int currSymbol = topElement.symbol;
        int currCost = topElement.cost;

        if(visitedNodes[currSymbol]!=-1)
        {
            totalCost+=currCost;
            edges.push_back(Edge(visitedNodes[currSymbol], currSymbol, currCost));
        }
        //get vector of neighboring nodes
        std::vector<int> adjacentNodes = graph.neighbors(currSymbol);

        //for each neighboring node
        for(int n=0; n<adjacentNodes.size(); n++)
        {
            int v = adjacentNodes[n];
            node.symbol = v;

            if(pq.doesContain(node))
            {
                if(node.cost > graph.getEdgeValue(currSymbol, v))
                {
                    node.cost = graph.getEdgeValue(currSymbol, v);
                    pq.changePriority(node);
                    visitedNodes[v] = currSymbol;
                }
            }
        }
    }
    return totalCost;
}