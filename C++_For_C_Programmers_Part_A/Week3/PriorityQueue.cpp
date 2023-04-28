/*
 * Created on 23 April, 2023
 * Author: Justin Ng
 * Email: justinngyl@gmail.com
 */
#include <math.h>

#include "PriorityQueue.hpp"

//parameterized constructor
PriorityQueue::PriorityQueue(const std::vector<int>& nodeList)
{
    for (int i = 0; i < nodeList.size(); i++)
    {
        if(symbolToIndex.count(nodeList[i]) == 0)
        {
            minHeap.push_back(pqNode(nodeList[i]));
            symbolToIndex[nodeList[i]] = i;
        }
    }
    minHeapify();
}

void PriorityQueue::minHeapify()
{
    int start = std::round((size() - 2.0) / 2.0);

    for(int i=start; i>=0; i--)
    {
        shiftDown(i);
    }
}

void PriorityQueue::shiftUp(int i)
{
    if(i <= 0){return;}
    int p = parent(i);
    if(minHeap[i].cost < minHeap[p].cost)
    {
        swap(i, p);
        shiftUp(p);
    }
}

//shift a node downwards to maintain heap correctness
void PriorityQueue::shiftDown(int i)
{
    int left = leftChild(i);
    int right = rightChild(i);
    int minIndex = i;
    if(left <= size() && minHeap[left].cost < minHeap[i].cost)
    {
        minIndex = left;
    }
    if(right <= size() && minHeap[right].cost < minHeap[i].cost)
    {
        minIndex = right;
    }
    if(i!=minIndex)
    {
        swap(i, minIndex);
        shiftDown(minIndex);
    }
}

void PriorityQueue::swap(int a, int b)
{
    int node1 = minHeap[a].symbol;
    int node2 = minHeap[b].symbol;

    minHeap[a].symbol = node2;
    minHeap[b].symbol = node1;

    int temp = minHeap[a].cost;
    minHeap[a].cost = minHeap[b].cost;
    minHeap[b].cost = temp;

    symbolToIndex[node1] = b;
    symbolToIndex[node2] = a;
}

//changes priority of queue element
void PriorityQueue::changePriority(const pqNode& node)
{
    if(symbolToIndex.count(node.symbol) == 0)
    {
        return;
    }
    if (minHeap[node.symbol].cost < node.cost)
    {
        minHeap[node.symbol].cost = node.cost;
        shiftDown(node.symbol);
    }
    if (minHeap[node.symbol].cost > node.cost)
    {
        minHeap[node.symbol].cost = node.cost;
        shiftUp(node.symbol);
    }
}

//removes top element of queue
void PriorityQueue::minPriority()
{
    if(size()<=1)
    {
        minHeap.clear();
        return;
    }
    
    pqNode &lastNode = minHeap.back();
    minHeap[0].symbol = lastNode.symbol;
    minHeap[0].cost = lastNode.cost;
    minHeap.pop_back();
    shiftDown(0);
    
}

//check queue contain queue element
bool PriorityQueue::doesContain(pqNode& node)
{
    if(symbolToIndex.count(node.symbol) > 0)
    {
        node.cost = minHeap[symbolToIndex[node.symbol]].cost;
        return true;
    }
    return false;
}

//insert element into queue
bool PriorityQueue::insert(pqNode& node)
{
    if(symbolToIndex.count(node.symbol) > 0)
    {
        return false;
    }
    minHeap.push_back(node);
    int index = size()-1;
    symbolToIndex[node.symbol] = index;
    shiftUp(index);
    return true;
}

//return top element of queue
pqNode &PriorityQueue::top()
{
    assert(size() > 0);
    return minHeap[0];
}