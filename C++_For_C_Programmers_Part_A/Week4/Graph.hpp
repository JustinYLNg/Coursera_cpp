/*
 * Created on 27 April, 2023
 * Author: Justin Ng
 * Email: justinngyl@gmail.com
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <fstream>
#include <unordered_map>
#include <vector>

//ADT for graph class using adjacency matrix
class Graph
{
    public:
        //default constructor
        Graph(){}

        //parameterized constructor
        Graph(int v, float density, int distanceRange);

        //Constructor for reading from file for MST
        //The file format will be an initial integer that is the node size of the graph
        //and the further values will be integer triples: (i, j, cost)
        Graph(std::ifstream &input);

        int getNumOfVertices() const { return numOfVertices; }

        int getNumOfEdges() const { return numOfEdges; }

        //tests whether there is an edge from node x to node y
        bool isAdjacent(int x, int y) const;

        //lists all nodes y such that there is an edge from x to y
        std::vector<int> neighbors(int x) const;

        //adds to graph the edge from x to y, if it is not there
        void addEdge(int x, int y, int value);

        //removes the edge from x to y, if it is there
        void deleteEdge(int x, int y);

        //return pointer to array of nodes
        std::vector<int> getNodes() const;

        //returns the value associated with the edge E(x, y)
        int getEdgeValue(int x, int y) const;

        //sets the value associated with the edge E(x, y) to a
        bool setEdgeValue(int x, int y, int a);

        //display adjacency matrix
        void printMatrix();

    private:
        int numOfVertices;
        int numOfEdges;
        std::vector<std::vector<int>> graph;
};

#endif