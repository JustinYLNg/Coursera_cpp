/*
 * Created on 23 April, 2023
 * Author: Justin Ng
 * Email: justinngyl@gmail.com
 */

#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <assert.h>
#include <limits>
#include <unordered_map>
#include <vector>
const int INF = std::numeric_limits<int>::max();

struct pqNode
{
    int symbol;
    int cost;   //sum of costs to a node (sum of edge weights)
    pqNode(int index = -1, int dist = INF):symbol(index), cost(dist){}
};

class PriorityQueue
{
    public:
        //default constructor
        PriorityQueue(){}

        //parameterized constructor
        PriorityQueue(const std::vector<int> &nodeList);

        //changes priority of queue element
        void changePriority(const pqNode& node);

        //removes top element of queue
        void minPriority();

        //check queue contain queue element
        bool doesContain(pqNode& node);

        //insert element into queue
        bool insert(pqNode& node);

        //return top element of queue
        pqNode& top();

        //return number of queue elements
        int size() { return minHeap.size(); }

    private:
        void minHeapify();
        //shift a node upwards to maintain heap correctness
        void shiftUp(int i);

        //shift a node downwards to maintain heap correctness
        void shiftDown(int i);

        //swap between two nodes
        void swap(int a, int b);

        //return index of parent node
        inline int parent(int i);

        //return index of left child node
        inline int leftChild(int i);

        //return index of right child node
        inline int rightChild(int i);

        std::vector<struct pqNode> minHeap;

        std::unordered_map<int, int> symbolToIndex;
};

inline int PriorityQueue::parent(int i)
{
    return (i-1)/2;
}

inline int PriorityQueue::leftChild(int i)
{
    return 2*i+1;
}

inline int PriorityQueue::rightChild(int i)
{
    return 2*i+2;
}

#endif