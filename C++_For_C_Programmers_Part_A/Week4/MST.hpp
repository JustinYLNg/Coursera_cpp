#ifndef MST_HPP
#define MST_HPP

#include "Graph.hpp"
#include <vector>

struct Edge
{
    int src;
    int dest;
    int cost;
    Edge(int s = -1, int d = -1, int c = 0) : src(s), dest(d), cost(c) {}
    bool operator()(const Edge &a, const Edge &b) { return a.cost < b.cost; }
};

class MST
{
    public:
        virtual int makeMST(const Graph &graph, std::vector<Edge> &edges) const = 0;
};

#endif  //MST_HPP