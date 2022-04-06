/*
* Title: Tree Analyze
* Author: Safa Eren Kuday
* ID: 21902416
* Section: 3
* Assignment: 2
* Description: Anlyze-bst function to observe change in 
* the height of a tree during insertion and deletion operations
*/
#include <string>
#include <iostream>
#include "BinarySearchTree.h"
#include "analyze.h"
using namespace std;



void analyzeBST(){
    BinarySearchTree tree;
    const int arrsize = 10000;
    int arr[arrsize];
    
    cout << "Random BST size vs. height (Insertion)-----------------------------------------" << endl;

    srand (time (0));
    for(int i = 1; i <= arrsize; i++){ 
        arr[i-1] = rand();
        tree.add(arr[i-1]);

        if(i % 100 == 0)
            cout << tree.getNumberOfNodes() << " " <<tree.getHeight() << endl;

    }
    
    
    for(int i = 0; i < arrsize; i++){
        int a = rand() % arrsize;

        int temp = arr[i];
        arr[i] = arr[a];
        arr[a] = temp;
    }        

    cout << "Random BST size vs. height (Deletion)-----------------------------------------" << endl;
    for(int i = 1; i <= arrsize; i++){      
        tree.remove(arr[i - 1]);

        if(i % 100 == 0)
            cout << tree.getNumberOfNodes() << " " <<tree.getHeight() << endl;

        /*if(i > arrsize - 20){
            cout << tree.getNumberOfNodes() << " " << i << " " <<arr[i] << endl;
            tree.inorderTraverse();
        }*/
            
    }

    cout << "...The End" << endl;
}

