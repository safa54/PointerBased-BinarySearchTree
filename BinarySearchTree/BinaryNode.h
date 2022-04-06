/*
* Title: BST.h
* Author: Safa Eren Kuday
* ID: 21902416
* Section: 3
* Assignment: 2
* Description: implementation of Binary Node
*/
using namespace std;


class BinaryNode{
    private:
        int val;
        int size;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode* parent;

        BinaryNode(int value = 0);
    
   friend class BinarySearchTree;

};