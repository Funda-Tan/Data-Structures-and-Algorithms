/*
* Title: Binary Search Trees
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 2
* Description: Binary Search Tree class is implemented with various methods.
*/
#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include <algorithm>
#include <iostream>
using namespace std;
// constructor
BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

// destructor
BinarySearchTree::~BinarySearchTree(){
}

// check if it is empty
bool BinarySearchTree::isEmpty(){
    return root == NULL;
}

// calculate height
int BinarySearchTree::getHeight(){
    return getHeightRoot(root);
}

int BinarySearchTree::getHeightRoot(BinaryNode* root){
    if (root == NULL)
        return 0;

    else{
        int counterLeft = getHeightRoot(root->leftChildPtr);
        int counterRight = getHeightRoot(root->rightChildPtr);
        return 1 + max(counterLeft, counterRight);
    }
}

// get number of nodes in the tree
int BinarySearchTree::getNumberOfNodes(){
    int count = 0;
    countNodes(root, count);
    return count;
}

int BinarySearchTree::countNodes(BinaryNode *treePtr, int& count) {
    if (treePtr != NULL) {
        countNodes(treePtr->leftChildPtr, count);
        countNodes(treePtr->rightChildPtr, count);
        count++;
    }
    return count;
}

// add a new item to tree
bool BinarySearchTree::add(const int newEntry){
    if( contains(newEntry) == true)
        return false;
    else{
        searchTreeInsert(newEntry);
        return true;
    }
}

void BinarySearchTree::searchTreeInsert(const int& newItem) {
    insertItem(root, newItem);
}

void BinarySearchTree::insertItem(BinaryNode *& treePtr,
				const int& newItem){

		// position is found found
		if (treePtr == NULL) {
			treePtr = new BinaryNode(newItem, NULL, NULL);
		}
		// find insertion position
		else if (newItem < treePtr->item)
			insertItem(treePtr->leftChildPtr, newItem);
		else
			insertItem(treePtr->rightChildPtr, newItem);
}

// remove an item from tree
bool BinarySearchTree::remove(const int anEntry){
    int first = getNumberOfNodes();
    searchTreeDelete(anEntry);
    if(getNumberOfNodes() == first)
        return false;
    return true;
}

void BinarySearchTree::searchTreeDelete(int searchKey) {
    deleteItem(root, searchKey);
}

void BinarySearchTree::deleteItem(BinaryNode * &treePtr, int searchKey) {
    if (searchKey == treePtr->item)
        deleteNodeItem(treePtr);

    else if (searchKey < treePtr->item)
        deleteItem(treePtr->leftChildPtr, searchKey);

    else
        deleteItem(treePtr->rightChildPtr, searchKey);
}

void BinarySearchTree::deleteNodeItem(BinaryNode* &nodePtr) {
    BinaryNode *delPtr;
    int replacementItem;

    if ((nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL) ) {
        delete nodePtr;
        nodePtr = NULL;
    }

    else if (nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }

    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }

    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

void BinarySearchTree::processLeftmost(BinaryNode *&nodePtr, int& treeItem){
    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->item;
        BinaryNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, treeItem);
}

bool BinarySearchTree::contains(const int anEntry){
    return findContains(root, anEntry);
}

bool BinarySearchTree::findContains(BinaryNode *treePtr, int entry) {
    if (treePtr != NULL) {
        if(entry == treePtr->item){
            return true;
        }

        else if(entry < treePtr->item){
            return findContains(treePtr->leftChildPtr, entry);
        }

        else if(entry > treePtr->item){
            return findContains(treePtr->rightChildPtr, entry);
        }
    }
    return false;
}

// traverse preorder
void BinarySearchTree::preorderTraverse(){
    cout << "Prerder Traversal: ";
    preorder(root);
}

void BinarySearchTree::preorder(BinaryNode *treePtr) {
		if (treePtr != NULL) {
			cout << treePtr->item << " ";
			preorder(treePtr->leftChildPtr);
			preorder(treePtr->rightChildPtr);
		}
}

// traverse inorder
void BinarySearchTree::inorderTraverse(){
    cout << "Inorder Traversal: ";
    inorder(root);
}

void BinarySearchTree::inorder(BinaryNode *treePtr) {
		if (treePtr != NULL) {
			preorder(treePtr->leftChildPtr);
			cout << treePtr->item << " ";
			preorder(treePtr->rightChildPtr);
		}
}

// traverse post order
void BinarySearchTree::postorderTraverse(){
    cout << "Postorder Traversal: ";
    postorder(root);
}

void BinarySearchTree::postorder(BinaryNode *treePtr) {
		if (treePtr != NULL) {
			postorder(treePtr->leftChildPtr);
			postorder(treePtr->rightChildPtr);
			cout << treePtr->item << " ";
		}
}

// traverse level order
void BinarySearchTree::levelorderTraverse(){
    cout << "Levelorder Traversal: ";
    printLevelOrder(root);
}

void BinarySearchTree::printLevelOrder(BinaryNode *root){
    int lastLevel = getHeight();
    for (int i = 0; i <= lastLevel; i++)
        printThisLevel(root, i + 1);
}

void BinarySearchTree::printThisLevel(BinaryNode* root, int level){
    if (root != NULL) {
        if (level == 1)
            cout << root->item << " ";

        else if (level > 1){
            printThisLevel(root->leftChildPtr, level - 1);
            printThisLevel(root->rightChildPtr, level - 1);
        }
    }
}

int BinarySearchTree::span(const int a, const int b){
    return spanTree(a, b, root);
}

// span tree
int BinarySearchTree::spanTree(const int a, const int b, BinaryNode* root){
    if (root != NULL){
        if (root->item >= a && root->item <= b){
            return 1 + spanTree(a, b, root->leftChildPtr) + spanTree(a, b, root->rightChildPtr);
        }

        else if (root->item < a){
            return spanTree(a, b, root->rightChildPtr);
        }

        else if (root->item > b)
            return spanTree(a, b, root->leftChildPtr);

        else
            return 1;
    }
    return 0;
}

// mirror tree
void BinarySearchTree::mirror(){
    mirrorTree(root);
}

void BinarySearchTree::mirrorTree(BinaryNode* &root){
     if (root != NULL){
        BinaryNode* temp = NULL;
        mirrorTree(root->leftChildPtr);
        mirrorTree(root->rightChildPtr);
        temp = root->leftChildPtr;
        root->leftChildPtr = root->rightChildPtr;
        root->rightChildPtr = temp;
     }
}
