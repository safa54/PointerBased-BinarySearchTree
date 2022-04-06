/*
* Title: BST.cpp
* Author: Safa Eren Kuday
* ID: 21902416
* Section: 3
* Assignment: 2
* Description: implementation of Bst
*/
#include <iostream>
using namespace std;
#include "BinarySearchTree.h"


    BinarySearchTree::BinarySearchTree(){
        root = nullptr;
    }



    void BinarySearchTree::deletePostOrder(BinaryNode* node){

        if(node == nullptr)
            return;
        
        deletePostOrder(node->left);
        deletePostOrder(node->right);
        delete node;
    }

    BinarySearchTree::~BinarySearchTree(){
        deletePostOrder(root);
    }


    bool BinarySearchTree::isEmpty(){
        return root == nullptr;
    }

    


    int BinarySearchTree::getHeightOfNode(BinaryNode* node){
        if(node == nullptr)
            return 0;

        return 1 + max(getHeightOfNode(node->left), getHeightOfNode(node->right));

    }
    int BinarySearchTree::getHeight(){
        return getHeightOfNode(root);
    }

    int BinarySearchTree::getNumberOfNodes(){

        if(isEmpty())
            return 0;

        return root->size;
    }
    
    
    bool BinarySearchTree::add(int newEntry){

        if(newEntry <= 0)
            return false;

        if(isEmpty()){
            root = new BinaryNode(newEntry);
            return true;
        }


        BinaryNode* parent = nullptr;
        BinaryNode* node = root;

        do{
           
            if(node == nullptr){

                if(parent->val < newEntry){
                    parent->right = new BinaryNode(newEntry);
                    parent->right->parent = parent;
                }
                else{
                    parent->left = new BinaryNode(newEntry);
                    parent->left->parent = parent;
                }
                

                //update sizes
                while(parent != nullptr){
                    parent->size++; 
                    parent = parent->parent;
                }
                return true;
            } 

            if(node->val > newEntry){
                parent = node;
                node = node->left;
            }
            else if(node->val < newEntry){
                parent = node;
                node = node->right;
            }
            else{
                return false;
            }


        }while(true);
        
    }

    
    bool BinarySearchTree::remove(int anEntry){

        if(anEntry <= 0)
            return false;

        BinaryNode* node = root;

        while (node != nullptr)
        {
            if(node->val > anEntry)
                node = node->left;       
            else if(node->val < anEntry)
                node = node->right;
            else{
                
          
                //update sizes
                BinaryNode* prnt = node->parent;
          
                while(prnt != nullptr){
                    prnt->size--; 
                    prnt = prnt->parent;
                }
          
          
                // delete the node

                if(node->left == nullptr || node->right == nullptr)
                {   
                  
                    //if it has less than 2 children
                    deleteNode(node);
                }
                else{// if two children
                   
                    BinaryNode* rightMin = node->right;

                    while(rightMin->left != nullptr){
                        rightMin->size--;
                        rightMin = rightMin->left;
                    }
                    
                    int temp = rightMin->val;
                    
                    deleteNode(rightMin);
                    
                    node->size--;
                    node->val = temp;
                }

                return true;
            }
                
       }
        return false;
    }
    

    void BinarySearchTree::deleteNode(BinaryNode* node){
        int entry = node->val;
        //if leaf
        if(node->size == 1){
            if(node->parent == nullptr){
                //cout << 177 << endl;
                root = nullptr;
                delete node;   
            }
            else{
                //cout << 182 << endl;
                node = node->parent;

                if(node->val > entry){
                    delete node->left;     
                    node->left = nullptr;
                }
                else if(node->val < entry){
                    delete node->right;     
                    node->right = nullptr;
                }
            }
        }
        else{
            if(node->left == nullptr){
                //if one (right) child
          
                // if root
                if(node == root){
                        root->right->parent = nullptr;                           
                        root = root->right;
                        delete node;
                        return;
                    }
                
            

                    //not root
                    if(node->parent->val > entry){ //if node is the left child of its parent
                        node->parent->left = node->right;
                        node->right->parent = node->parent;
                        delete node;      
                    }
                    else if(node->parent->val < entry){ //if node is the right child of its parent
                        node->parent->right = node->right;
                        node->right->parent = node->parent;
                        delete node; 
                    }
            
            }
            else{
                //if one (left) child
          
                // if root
                if(node == root){
                    root->left->parent = nullptr;                              
                    root = root->left;
                    delete node;
                    return;
                }

                //not root

                if(node->parent->val > entry){ //if node is the left child of its parent
                    node->parent->left = node->left;
                    node->left->parent = node->parent;
                    delete node;      
                }
                else if(node->parent->val < entry){ //if node is the right child of its parent
                    node->parent->right = node->left;
                    node->left->parent = node->parent;
                    delete node; 
                }
            }
        }
        
    }


    
    bool BinarySearchTree::contains(int anEntry){
        
        if(anEntry <= 0)
            return false;

        BinaryNode* node = root;

        while (node != nullptr)
        {
            if(node->val > anEntry)
                node = node->left;       
            else if(node->val < anEntry)
                node = node->right;
            else
                return true;
       }
        return false;
    }

    
   
    void BinarySearchTree::inorderTraverseOfNode(BinaryNode* node){

        if(node == nullptr)
            return;

        inorderTraverseOfNode(node->left);
        cout << node->val << " ";
        //cout << "(" << node->size << ")  ";
        inorderTraverseOfNode(node->right);
    }

    void BinarySearchTree::inorderTraverse(){
        cout << "Inorder Traversal: ";
        inorderTraverseOfNode(root);
        cout << endl;
    }

    void  BinarySearchTree::getWidths( int*& arr, BinaryNode* node, int height){

        if(node == nullptr)
            return;

        arr[height]++;
        
        height++;
        getWidths(arr, node->left, height);
        getWidths(arr, node->right, height);
    }
    
    int BinarySearchTree::getWidth(){
        int hgt  = getHeight();

        if(hgt == 0)
            return 0;

        int* widths = new int[hgt];

        for(int i = 0; i < hgt; i++)
            widths[i] = 0;

        getWidths(widths, root, 0);

        int maxi = 0;

        for(int i = 0; i < hgt; i++)
            maxi = max(maxi, widths[i]);
        

        delete [] widths;
        return maxi;
    }

    
    int BinarySearchTree::count(int a, int b){
 
        if(b < a)
            return 0;

        BinaryNode* node = root;

        int numOfSmallers = 0;
        int numOfLargers = 0;

        while (node != nullptr)
        {
            if(node->val > a)
                node = node->left;       
            else if(node->val < a){
                numOfSmallers += node->size;
                node = node->right;
                if(node != nullptr)
                    numOfSmallers -= node->size;
            }  
            else{
                if(node->left != nullptr)
                    numOfSmallers += node->left->size;
                break;
            }
       }

       node = root;

       while (node != nullptr)
        {
            if(node->val < b)
                node = node->right;       
            else if(node->val > b){
                numOfLargers += node->size;
                node = node->left;
                if(node != nullptr)
                    numOfLargers -= node->size;
            }  
            else{
                if(node->right != nullptr)
                    numOfLargers += node->right->size;

                break;
            }
       }

        return getNumberOfNodes() - numOfLargers - numOfSmallers;

    }


    int BinarySearchTree::select(int anEntry){
        if(anEntry <= 0)
            return -1;

        BinaryNode* node = root;

        int numOfSmallers = 0;

        while (node != nullptr)
        {
            if(node->val > anEntry)
                node = node->left;       
            else if(node->val < anEntry){
                numOfSmallers += node->size;
                node = node->right;
                if(node != nullptr)
                    numOfSmallers -= node->size;
            }  
            else{
                if(node->left != nullptr)
                    numOfSmallers += node->left->size;

                return numOfSmallers;
            }
                

       }
        return -1; 
    }


   

    int BinarySearchTree::successor(int anEntry){

        if(anEntry <= 0)
            return -1;

        BinaryNode* node = root;
        
        //value of the most recent parent of a left child 
        int theLatestLeft  = -2;

        while (node != nullptr)
        {
            if(node->val > anEntry){
                theLatestLeft = node->val;
                node = node->left;   
            }       
            else if(node->val < anEntry)
                node = node->right;
            else{
                
                //the node is found
                if(node->right != nullptr){
                    node = node->right;

                    while(node->left != nullptr)
                        node = node->left;

                    return node->val;
                }
                
                return theLatestLeft;
            }
       }
        return -1;

    }


    