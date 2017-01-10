/*
 * File:            AVLNode.cpp
 * Project:         3
 * Author:          Joshua Meyer
 * Date created:    10/26/16
 * Section:         01
 * Username:        jmey1@umbc.edu
 * AVLNode.cpp impliments the functions needed for the AVLNode class
 */

#ifndef _AVLNODE_CPP_
#define _AVLNODE_CPP_

#include "AVLNode.h"
#include <queue>

//setup an empty node
template <class D, class N>
AVLNode<D, N>::AVLNode(){
    m_left = NULL;
    m_right =  NULL;
    m_isEmpty = true;
    m_height = 1;
    m_printOrder = 0;
}

//setup a node with a given input
template <class D, class N>
AVLNode<D, N>::AVLNode(int treeID, int printOrder){
    m_left = NULL;
    m_right = NULL;
    m_treeID = treeID;
    m_printOrder = printOrder;
    m_height = 1;
    m_isEmpty = true;
}

//destroy a node and its children
template <class D, class N>
AVLNode<D, N>::~AVLNode(){
    delete m_left;
    delete m_right;
}

//initialize a tree that has an existing node
template<class D, class N>
AVLNode<D, N>* AVLNode<D, N>::createFirstNode(AVLNode<D, N>* ptr, D alpha, N num){
    ptr->m_letterData = alpha;
    ptr->m_numData = num;
    ptr->m_isEmpty = false;
    return ptr;
}

//add a new node to an existing tree
template <class D, class N>
AVLNode<D, N>* AVLNode<D, N>::createNode(AVLNode<D, N>* root, D alpha, N num, int ID, int printOrder){
    
    //if the current node is uninitialized, create a new node
    if (root == NULL){
        AVLNode<D, N>* newNode = new AVLNode<D, N>;
        newNode->m_letterData = alpha;
        newNode->m_numData = num;
        newNode->m_treeID = ID;
        newNode->m_isEmpty = false;
        newNode->m_printOrder = printOrder;
        return(newNode);
    }
    
    //if the number to insert is less than root, insert into left node
    if (num < root->m_numData){
        root->m_left = createNode(root->m_left, alpha, num, ID, printOrder);
    }
    
    //if the number to insert is greater than root, insert into right
    else{
        root->m_right = createNode(root->m_right, alpha, num, ID, printOrder);
    }
    
    //calculate the height of node by using its children
    if (getHeight(root->m_right) > getHeight(root->m_left)){
        root->m_height = getHeight(root->m_right) + 1;
    }
    
    else{
        root->m_height = getHeight(root->m_left) + 1;
    }
    
    
    //find balance of tree
    int bal = getBalance(root);
    
    
    //correct imbalances, if any
    // Left Left Case
    if (bal > 1 && num < root->m_left->m_numData){
        return rightRotate(root);
    }
    
    // Right Right Case
    if (bal < -1 && num > root->m_right->m_numData){
        return leftRotate(root);
    }
    
    // Left Right Case
    if (bal > 1 && num > root->m_left->m_numData){
        root->m_left =  leftRotate(root->m_left);
        return rightRotate(root);
    }
    
    // Right Left Case
    if (bal < -1 && num < root->m_right->m_numData){
        root->m_right = rightRotate(root->m_right);
        return leftRotate(root);
    }
    
    //return the node
    return root;
}

//returns the imbance of a tree by finding the difference in height
template <class D, class N>
int AVLNode<D, N>::getBalance(AVLNode<D, N>* root){
    if (root == NULL){
        return 0;
    }
    
    else{
        return getHeight(root->m_left) - getHeight(root->m_right);
    }
}

template <class D, class N>
AVLNode<D, N>* AVLNode<D, N>::leftRotate(AVLNode<D, N>* root){
    //perform rotataion
    AVLNode<D, N>* x = root->m_right;
    AVLNode<D, N>* t = x->m_left;
    
    x->m_left = root;
    root->m_right = t;
    
    //fix heights
    if (getHeight(root->m_left) > getHeight(root->m_right)){
        root->m_height = getHeight(root->m_left) + 1;
    }
    
    else{
        root->m_height = getHeight(root->m_right) + 1;
    }
    
    if (getHeight(x->m_left) > getHeight(x->m_right)){
        x->m_height = getHeight(x->m_left) + 1;
    }
    
    else{
        x->m_height = getHeight(x->m_right) + 1;
    }
    
    //return corrected node
    return x;
}

template <class D, class N>
AVLNode<D, N>* AVLNode<D, N>::rightRotate(AVLNode<D, N>* root){
    //perform rotation
    AVLNode<D, N>* x = root->m_left;
    AVLNode<D, N>* t = x->m_right;
    
    x->m_right = root;
    root->m_left = t;
    
    //fix heights
    if (getHeight(root->m_left) > getHeight(root->m_right)){
        root->m_height = getHeight(root->m_left) + 1;
    }
    
    else{
        root->m_height = getHeight(root->m_right) + 1;
    }
    
    if (getHeight(x->m_left) > getHeight(x->m_right)){
        x->m_height = getHeight(x->m_left) + 1;
    }
    
    else{
        x->m_height = getHeight(x->m_right) + 1;
    }
    
    //return corrected node
    return x;
}

//call other print functions based on print order
template <class D, class N>
void AVLNode<D, N>::printNode(AVLNode<D, N>* root, std::ostream& outStream){
    
    if (root->m_printOrder == 0){
        printInOrder(root, outStream);
    }
    
    else if (root->m_printOrder == 1){
        printPreOrder(root, outStream);
    }
    
    else if (root->m_printOrder == 2){
        printPostOrder(root, outStream);
    }
    
    else if (root->m_printOrder == 3){
        printLevelOrder(root, outStream);
    }
 
}

template <class D, class N>
void AVLNode<D, N>::printInOrder(AVLNode<D, N>* root, std::ostream& outStream){
    
    if (root != NULL){
        printInOrder(root->m_left, outStream);
        outStream<<root->m_letterData<<" ";
        printInOrder(root->m_right, outStream);
    }
}

template <class D, class N>
void AVLNode<D, N>::printPreOrder(AVLNode<D, N>* root, std::ostream& outStream){
    if (root){
        outStream<<root->m_letterData<<" ";
        printPreOrder(root->m_left, outStream);
        printPreOrder(root->m_right, outStream);
    }
}

template <class D, class N>
void AVLNode<D, N>::printPostOrder(AVLNode<D, N>* root, std::ostream& outStream){
    if (root != NULL){
        printPostOrder(root->m_left, outStream);
        printPostOrder(root->m_right, outStream);
        outStream<<root->m_letterData<<" ";
    }
}

template <class D, class N>
void AVLNode<D, N>::printLevelOrder(AVLNode<D, N>* root, std::ostream& outStream){
    std::queue<AVLNode<D, N>* > itemsToPrint;
    itemsToPrint.push(root);
    
    while ( ! itemsToPrint.empty()){
        AVLNode<D, N>* node = itemsToPrint.front();
        outStream<<node->m_letterData<<" ";
        
        if (node->m_left != NULL){
            itemsToPrint.push(node->m_left);
        }
        if (node->m_right != NULL){
            itemsToPrint.push(node->m_right);
        }
        
        itemsToPrint.pop();
        
    }
}

template <class D, class N>
void AVLNode<D, N>::print_range(std::ostream& outStream, N lower, N upper){
    //do nothing for null node
    if (this == NULL){
        return;
    }
    
    //recursively call print_range based on upper and lower bounds
    if (m_numData > lower){
        m_left->print_range(outStream, lower, upper);
    }
    
    if (m_numData >= lower && m_numData <= upper){
        outStream<<m_letterData<<" ";
    }
    
    if (m_numData < upper){
        m_right->print_range(outStream, lower, upper);
    }
    
}

template <class D, class N>
D AVLNode<D, N>::getData() const{
    return m_letterData;
}

template <class D, class N>
N AVLNode<D, N>::getNum() const{
    return m_numData;
}

template <class D, class N>
int AVLNode<D, N>::getHeight(AVLNode<D, N>* root){
    //null nodes have height of 0
    if (root == NULL){
        return 0;
    }
    
    return root->m_height;
}

template <class D, class N>
AVLNode<D, N>* AVLNode<D, N>::getRightPtr(){
    return m_right;
}

template <class D, class N>
AVLNode<D, N>* AVLNode<D, N>::getLeftPtr(){
    return m_left;
}

template <class D, class N>
bool AVLNode<D, N>::getIsEmpty(){
    return m_isEmpty;
}








#endif
