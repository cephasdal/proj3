/*
 * File:            AVLNode.h
 * Project:         3
 * Author:          Joshua Meyer
 * Date created:    10/26/16
 * Section:         01
 * Username:        jmey1@umbc.edu
 * AVLNode.h contains the headers for the AVLNode functions and members
 */

#ifndef _AVLNODE_h_
#define _AVLNODE_h_

#include <iostream>
#include "AVLTreeBase.h"

template <class D, class N>
class AVLNode : public AVLTreeBase{
    

public:
    //constructors *********************************************
    //default constructor
    AVLNode();
    
    //alternate constructor, sets data member variables with given data
    AVLNode(int treeID, int printOrder);
    
    //deallocates memory
    ~AVLNode();

    //insert functions *********************************************
    //recieves pointer to a node and data to insert. Creates and fills
    //a new node
    AVLNode<D, N>* createNode(AVLNode<D, N>* root, D alpha, N num, int ID, int printOrder);
    
    //recieves pointer to a node and data to insert. Fills an existing
    //first node
    AVLNode<D, N>* createFirstNode(AVLNode<D, N>* ptr, D alpha, N num);
    
    //balance functions *********************************************
    //recieves a pointer to a node, returns int indicating an imbalance
    int getBalance(AVLNode<D, N>* root);
    
    //recieves pointer to node, performs left rotation
    AVLNode<D, N>* leftRotate(AVLNode<D, N>* root);
    
    //recieves pointer to node, performs right rotation
    AVLNode<D, N>* rightRotate(AVLNode<D, N>* root);
    
    //print functions -- recieve node pointer and output stream *****
    //calls the correct print function based on m_printOrder
    void printNode(AVLNode<D, N>* root, std::ostream& outStream);
    
    //performs an inorder walk
    void printInOrder(AVLNode<D, N>* root, std::ostream& outStream);
    
    //performs preorder walk
    void printPreOrder(AVLNode<D, N>* root, std::ostream& outStream);
    
    //performs postorder walk
    void printPostOrder(AVLNode<D, N>* root, std::ostream& outStream);
    
    //performs level walk using std::queue
    void printLevelOrder(AVLNode<D, N>* root, std::ostream& outStream);
    
    //recieves output stream and numerical bounds, prints nodes between
    //given bounds
    void print_range(std::ostream& outStream, N lower, N upper);
    
    //accessors ******************************************************
    //returns m_letterData
    D getData() const;
    
    //returns m_numData
    N getNum() const;
    
    //returns m_height for a given node
    int getHeight(AVLNode<D, N>* root);
    
    //returns right or left node pointers, respectively
    AVLNode<D, N>* getRightPtr();
    AVLNode<D, N>* getLeftPtr();
    
    //returns status of m_isEmpty
    bool getIsEmpty();
    
    
private:
    //stored node data
    D m_letterData;
    N m_numData;
    
    //left and right pointers
    AVLNode<D, N>* m_left;
    AVLNode<D, N>* m_right;
    
    //other information
    int m_treeID;
    int m_printOrder;
    int m_height;
    bool m_isEmpty; //indicates if node has no data
 
};

#include "AVLNode.cpp"

#endif 
