/*
* Title: BST.h
* Author: Safa Eren Kuday
* ID: 21902416
* Section: 3
* Assignment: 2
*/
using namespace std;
#include "BinaryNode.h"
#include "analyze.h"
class BinarySearchTree{
    
   private:     
        BinaryNode * root;

        void deletePostOrder(BinaryNode* node);
        int getHeightOfNode(BinaryNode* node);
        void inorderTraverseOfNode(BinaryNode* node);
        void getWidths( int*& arr, BinaryNode* node, int height);


   public:
        BinarySearchTree();
        ~BinarySearchTree();

        /**
         * @brief 
         * Returns true if BST is empty; otherwise false.
         * @return true 
         * @return false 
         */
        bool isEmpty(); 

        /**
         * @brief Get the Height object
         * 
         * @return int 
         */
        int getHeight(); 

        /**
         * @brief Get the Number Of Nodes 
         * 
         * @return int 
         */
        int getNumberOfNodes();
        
        /**
         * @brief Adds a new node containing a given data item to the BST.   
         * Returns false and does not add if newEntry is less than or equal to zero or newEntry
         * already exists in the current BST. Returns true if the addition is successful.
         * @param newEntry 
         * @return true 
         * @return false 
         */
        bool add(int newEntry);

        /**
         * @brief Removes the node containing the given data item from
         * BST. True if the removal is successful, or false if not.
         * @param anEntry 
         * @return true 
         * @return false 
         */
        bool remove(int anEntry); 

        /**
         * @brief Tests whether the given data item occurs in the BST.
         * True if the BST contains the given data item, or false if not.
         * @param anEntry 
         * @return true 
         * @return false 
         */
        bool contains(int anEntry);

        /**
         * @brief Traverses the BST in inorder and prints the data of each node in the traversal order.
         * 
         */
        void inorderTraverse();

        /**
         * @brief Get the Width of the Tree
         * 
         * @return int 
         */
        int getWidth();

        /**
         * @brief 
         * Returns the number of nodes in the BST with data values
            within a specific range. In other words, it is the number of nodes with the data value greater
            than or equal to a, and less than or equal to b.
         * @param a 
         * @param b 
         * @return int 
         */
        int count(int a, int b); 
        /**
         * @brief 
         * returns the 0-based index of anEntry in the sorted
            sequence of the items in the BST. If anEntry is not in the BST, then return -1.
         * @param anEntry 
         * @return int 
         */
        int select(int anEntry); 

        /**
         * @brief 
         * Returns the inorder successor of anEntry. If
            anEntry does not exist in the BST, returns -1. If anEntry is the last entry in the BST,
            returns -2.
         * @param anEntry 
         * @return int 
         */
        int successor(int anEntry); 


        private:
           void deleteNode(BinaryNode* node);
};