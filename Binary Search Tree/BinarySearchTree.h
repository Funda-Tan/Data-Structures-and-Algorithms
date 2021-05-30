/*
* Title: Binary Search Trees
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 2
* Description: .h file for Binary Search Tree class
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryNode.h"

class BinarySearchTree
{
    public:
        // functions in homework 2
        BinarySearchTree();
        ~BinarySearchTree();
        bool isEmpty();
        int getHeight();
        int getNumberOfNodes();
        bool add(const int newEntry);
        bool remove(const int anEntry);
        bool contains(const int anEntry);
        void preorderTraverse();
        void inorderTraverse();
        void postorderTraverse();
        void levelorderTraverse();
        int span(const int a, const int b);
        void mirror();
        // end homework 2 functions

        // helper functions
        int getHeightRoot(BinaryNode* root);
        int countNodes(BinaryNode *treePtr, int& count);
        void searchTreeInsert(const int& newItem);
        void insertItem(BinaryNode *& treePtr,const int& newItem);
        void searchTreeDelete(int searchKey);
        void deleteItem(BinaryNode * &treePtr, int searchKey);
        void deleteNodeItem(BinaryNode * &nodePtr);
        bool findContains(BinaryNode *treePtr, int entry);
        void processLeftmost(BinaryNode *&nodePtr,int& treeItem);
        void preorder(BinaryNode *treePtr);
        void inorder(BinaryNode *treePtr);
        void postorder(BinaryNode *treePtr);
        void printLevelOrder(BinaryNode* root);
        void printThisLevel(BinaryNode* root, int level);
        int spanTree(const int a, const int b, BinaryNode* root);
        void mirrorTree(BinaryNode* &root);

    private:
        BinaryNode* root;
};


#endif // BINARYSEARCHTREE_H
