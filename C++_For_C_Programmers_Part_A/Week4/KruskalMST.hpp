#ifndef KRUSKAL_MST_HPP
#define KRUSKAL_MST_HPP

#include "MST.hpp"
#include <vector>

class KruskalMST : public MST
{
    public:
        int makeMST(const Graph &graph, std::vector<Edge> &edges) const;

    private:
};

#endif //KRUSKAL_MST_HPP