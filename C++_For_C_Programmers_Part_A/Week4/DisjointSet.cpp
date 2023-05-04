#include "DisjointSet.hpp"

//parameterized constructor
DisjointSet::DisjointSet(int size) : _size(size)
{
    parent.resize(_size);
    rank.resize(_size);
    createSet();
}

//create set
void DisjointSet::createSet()
{
    for (int i = 0; i < _size; i++)
    {
        parent[i] = -1;
    }
}

//recursively traverse the vector parent to find the representative of node u
int DisjointSet::findSet(int u)
{
    //TODO - modify
    //if(parent[u] == -1)?
    if(parent[u] < 0)
    {
        return u;
    }
    else
    {
        return findSet(parent[u]);
    }
}

//merge sets each containing the element u and v respectively into one common set
void DisjointSet::unionSets(int u, int v)
{
    //find representative of u
    int uRep = findSet(u);
    //find representative of v
    int vRep = findSet(v);

    //return if both u & v have the same representative
    if(uRep == vRep) return;

    //attaching subtree to representative based on rank
    if(rank[uRep] < rank[vRep])
    {
        //attach set containing u to set containing v because rank of set with v is higher
        parent[uRep] = vRep;
    }
    else if(rank[uRep] > rank[vRep])
    {
        //attach set containing v to set containing u because rank of set with u is higher
        parent[vRep] = uRep;
    }
    else
    {
        parent[vRep] = uRep;
        rank[uRep] = rank[uRep] + 1;
    }
}