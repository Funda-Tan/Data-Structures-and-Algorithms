/*
* Title: Binary Search Trees
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 2
* Description: .h file for Binary Node class
*/
#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <cstddef>

class BinaryNode {
public:
    //set and get methods
    void setItem(int nodeItem);
    int getItem(int nodeItem);
    void setLeftPointer(BinaryNode* leftPointer);
    void setRightPointer(BinaryNode* rightPointer);

private:
    BinaryNode();
    BinaryNode(const int& nodeItem,BinaryNode *left = NULL,BinaryNode *right = NULL);
    int item;                  // data
    BinaryNode *leftChildPtr;  // pointer to left child
    BinaryNode *rightChildPtr; // pointer to right child

    friend class BinarySearchTree;
};


#endif // BINARYNODE_H
