/*
* Title: BinaryNode cpp
* Author: Safa Eren Kuday
* ID: 21902416
* Section: 3
* Assignment: 2
* Description: implementation of Node
*/
//#include <string>
//#include <iostream>
#include "BinaryNode.h"
using namespace std;


BinaryNode::BinaryNode(int value){
    size = 1;
    val = value;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

