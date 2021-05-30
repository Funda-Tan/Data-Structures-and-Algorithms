/*
* Title: Binary Search Trees
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 2
* Description: Binary Node class is implemented. Also, get and set functions implemented.
*/
#include "BinaryNode.h"
BinaryNode::BinaryNode(const int& nodeItem, BinaryNode *left, BinaryNode *right){
    item = nodeItem; // set data
    leftChildPtr = left;
    rightChildPtr = right;
}

void BinaryNode::setItem(int nodeItem){
    item = nodeItem;
}

int BinaryNode::getItem(int nodeItem){
    return item;
}

void BinaryNode::setLeftPointer(BinaryNode* leftPointer){
    leftChildPtr = leftPointer;
}

void BinaryNode::setRightPointer(BinaryNode* rightPointer){
    rightChildPtr = rightPointer;
}


