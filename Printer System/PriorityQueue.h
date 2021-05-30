/*
* Title: Heaps
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 3
* Description: PriorityQueue.h
*/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "PriorityQueue.h"
#include "Request.h"

//PriorityQueue class definition
const int MAX_HEAP = 1000;
typedef Request HeapItemType;

class Heap {
public:
    Heap();				// default constructor
    // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem);
    void heapDelete(HeapItemType& rootItem);

protected:
    void heapRebuild(int root);		// Converts the semiheap rooted at
    // index root into a heap
private:
    HeapItemType items[MAX_HEAP];	// array of heap items
    int          size;            	// number of heap items
};

class PriorityQueue {
public:
    bool pqIsEmpty() const;
    void pqInsert(const Request& newItem);
    void pqDelete(Request& priorityItem);

private:
    Heap h;
};

#endif // PRIORITYQUEUE_H
