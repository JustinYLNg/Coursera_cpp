
#include <iostream>
#include <limits>

#include "Graph.hpp"
#include "PrimMST.hpp"
#include "KruskalMST.hpp"
#include "PriorityQueue.hpp"

void runMST(const Graph& graph, const MST& mst)
{
    //vector to store the output
    std::vector<Edge> tree;

    int cost = mst.makeMST(graph, tree);
    std::cout << "The cost of MST is " << cost << std::endl;
    for (int i = 0; i < tree.size(); i++)
    {
        std::cout << "(" << tree[i].src << " -- " << tree[i].dest << ", cost = " << tree[i].cost
                  << ")\t";

        //output in lines of three
        if (i % 3 == 0)
        {
            std::cout << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    //initialize a graph by reading from the given formatted data
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " sample_data_file" << std::endl;
        return 1;
    }
    //std::ifstream inputFile("sample_data.txt");   //for testing
    std::ifstream inputFile(argv[1]);
    Graph g(inputFile);
    inputFile.close(); //close the file after reading

    std::cout << "Output using Kruskal's algorithm: " << std::endl;
    runMST(g, KruskalMST());

    //std::cout << "Output using Prim's algorithm: " << std::endl;
    //runMST(g, PrimMST());

    return 0;
}