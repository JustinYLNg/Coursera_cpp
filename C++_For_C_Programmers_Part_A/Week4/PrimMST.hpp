#ifndef PRIM_MST_HPP
#define PRIM_MST_HPP

#include "MST.hpp"
#include <vector>

class PrimMST : public MST
{
    public:
        int makeMST(const Graph& graph, std::vector<Edge>& edges) const;

    private:

};

#endif  //PRIM_MST_HPP