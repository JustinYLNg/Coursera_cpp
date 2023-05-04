#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <vector>

class DisjointSet
{
    public:

        //parameterized constructor
        DisjointSet(int size);

        //create set
        void createSet();

        //recursively traverse the vector parent to find the representative of node u
        int findSet(int u);

        //merge sets each containing the element u and v respectively into one common set
        void unionSets(int u, int v);

    private:
        int _size;
        std::vector<int> parent;
        std::vector<int> rank;
};

#endif //DISJOINT_SET_HPP