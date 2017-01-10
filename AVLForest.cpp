/*
 * File:            AVLForest.cpp
 * Project:         3
 * Author:          Joshua Meyer
 * Date created:    10/26/16
 * Section:         01
 * Username:        jmey1@umbc.edu
 * AVLForest.cpp implements the AVLForest class using AVLNodes
 */

#include "AVLForest.h"
#include <sstream>
#include <iostream>
#include <istream>
#include <string>
#include <stdlib.h>


AVLForest::AVLForest()
{

}

AVLForest::~AVLForest()
{
    //Iterate through forest deleting the appropriate AVLNode type
    for (int i = 0; i < m_treeForest.size(); i++){
        int letterType, numType;
        //check tree type from treeInfo
        letterType = m_treeInfo[i]->s_dataType;
        numType = m_treeInfo[i]->s_numType;
        
        if (letterType == 0 && numType == 0){
            AVLNode<char, int>* tempPtr = static_cast<AVLNode<char, int>* >(m_treeForest[i]);
            
            delete tempPtr;
            
        }
        
        else if (letterType == 0 && numType == 1){
            AVLNode<char, float>* tempPtr = static_cast<AVLNode<char, float>* >(m_treeForest[i]);
            
            delete tempPtr;
            
        }
        
        else if (letterType == 1 && numType == 0){
            AVLNode<std::string, int>* tempPtr = static_cast<AVLNode<std::string, int>* >(m_treeForest[i]);
            
            delete tempPtr;
            
        }
        
        else if (letterType == 1 && numType == 1){
            AVLNode<std::string, float>* tempPtr = static_cast<AVLNode<std::string, float>* >(m_treeForest[i]);
            
            delete tempPtr;
                       
        }
        
    }
    
    //delete the vector of structs of treeInfo
    for (int i = 0; i < m_treeInfo.size(); i++){
        delete m_treeInfo[i];
    }
    
}

void AVLForest::insert(std::string line)
{
  //read in treeID and see if it exists
  bool treeExists = false;
  std::stringstream ss(line);
  int treeID;
  ss >> treeID;
  ss.ignore();

  for (int i = 0; i < m_treeInfo.size(); i++){
    if (treeID == m_treeInfo[i]->s_treeID){
      treeExists = true;
      break;
    }
  }
  
  if(treeExists == false)
  {
    // create a new tree and add it to the vector

    int printOrder, dataType, numType;
    ss >> printOrder;
    ss.ignore();
    ss >> dataType;
    ss.ignore();
    ss >> numType;

      

    //check tree type and create the appropriate AVLNode
    if(dataType == 0 && numType == 0)
    {
        AVLTreeBase* treePtr = static_cast<AVLNode<char, int>* >(new AVLNode<char, int>(treeID, printOrder));
      
      
        m_treeForest.push_back(treePtr);
       
        //add information about tree to treeInfo
        AVLForest::TREEINFO* treeToMake = new TREEINFO;
        treeToMake->s_dataType = 0;
        treeToMake->s_numType = 0;
        treeToMake->s_treeID = treeID;
        treeToMake->s_printOrder = printOrder;
        m_treeInfo.push_back(treeToMake);
       
       
    }
    else if(dataType == 0 && numType == 1)
    {
      AVLTreeBase* treePtr = static_cast<AVLNode<char, float>* >(new AVLNode<char, float>(treeID, printOrder));
        m_treeForest.push_back(treePtr);

        //add information about tree to treeInfo
        AVLForest::TREEINFO* treeToMake = new TREEINFO;
        treeToMake->s_dataType = 0;
        treeToMake->s_numType = 1;
        treeToMake->s_treeID = treeID;
        treeToMake->s_printOrder = printOrder;
        m_treeInfo.push_back(treeToMake);
    }
    else if(dataType == 1 && numType == 0)
    {
      AVLTreeBase* treePtr = static_cast<AVLNode<std::string, int>* >(new AVLNode<std::string, int>(treeID, printOrder));
        m_treeForest.push_back(treePtr);

        //add information about tree to treeInfo
        AVLForest::TREEINFO* treeToMake = new TREEINFO;
        treeToMake->s_dataType = 1;
        treeToMake->s_numType = 0;
        treeToMake->s_treeID = treeID;
        treeToMake->s_printOrder = printOrder;
        m_treeInfo.push_back(treeToMake);    }
    else if(dataType == 1 && numType == 1)
    {
      AVLTreeBase* treePtr = static_cast<AVLNode<std::string, float>* >(new AVLNode<std::string, float>(treeID, printOrder));
        m_treeForest.push_back(treePtr);

        //add information about tree to treeInfo
        AVLForest::TREEINFO* treeToMake = new TREEINFO;
        treeToMake->s_dataType = 1;
        treeToMake->s_numType = 1;
        treeToMake->s_treeID = treeID;
        treeToMake->s_printOrder = printOrder;
        m_treeInfo.push_back(treeToMake);    }
    else
    {
      // invalid case
      std::cout<<"Error: Invalid Tree creation\n";
    }
  }
  else
  {
    // tree is in vector
    // we can proceed with insert
      std::string data, num;
      int dataType, numType, i;
      
      //find the tree with matching treeID to insert into
      for (i = 0; i < m_treeInfo.size(); i++){
          if (treeID == m_treeInfo[i]->s_treeID){
              break;
          }
      }

    
      dataType = m_treeInfo[i]->s_dataType;
      numType = m_treeInfo[i]->s_numType;
      
      //read in the char/string and int/float data
      std::string strArray[2];
      std::string input;
      int count = 0;
      while (std::getline(ss, input, ',')){
          strArray[count] = input;
          count++;
      }
      
      

    // insert data, number pair

    
    if(dataType == 0 && numType == 0)
    {
      AVLNode<char, int>* ptr = static_cast<AVLNode<char, int>* >(m_treeForest[i]);
        //get the char from strArray
        input = strArray[0];
        char dataChar = input[0];
        
        //convert string to int
        std::stringstream stringToNum(strArray[1]);
        int dataNum;
        stringToNum >> dataNum;
        
        //if inserting into empty tree
        if (ptr->getIsEmpty() == true){
            ptr = ptr->createFirstNode(ptr, dataChar, dataNum);
        }
        
        else{
            ptr = ptr->createNode(ptr, dataChar, dataNum, m_treeInfo[i]->s_treeID, m_treeInfo[i]->s_printOrder);
            m_treeForest[i] = ptr;
        }
    }
      
    else if(dataType == 0 && numType == 1)
    {
      /* static_cast to <YourAVLTreeClassName<char, float>*> if needed */
        AVLNode<char, float>* ptr = static_cast<AVLNode<char, float>* >(m_treeForest[i]);
        
        //get the char from strArray
        input = strArray[0];
        char dataChar = input[0];
        
        //convert string to float
        std::stringstream stringToNum(strArray[1]);
        float dataNum;
        stringToNum >> dataNum;
        
        //if inserting into empty tree
        if (ptr->getIsEmpty() == true){
            ptr = ptr->createFirstNode(ptr, dataChar, dataNum);
        }
        else{
            ptr = ptr->createNode(ptr, dataChar, dataNum, m_treeInfo[i]->s_treeID, m_treeInfo[i]->s_printOrder);
            m_treeForest[i] = ptr;
        }

    }
    else if(dataType == 1 && numType == 0)
    {
      /* static_cast to <YourAVLTreeClassName<std::string, int>*> if needed */
        
        AVLNode<std::string, int>* ptr = static_cast<AVLNode<std::string, int>* >(m_treeForest[i]);
        //convert string to int
        std::stringstream stringToNum(strArray[1]);
        int dataNum;
        stringToNum >> dataNum;
        
        //if inserting into empty tree
        if (ptr->getIsEmpty() == true){
            ptr = ptr->createFirstNode(ptr, strArray[0], dataNum);
        }
        else{
            ptr = ptr->createNode(ptr, strArray[0], dataNum, m_treeInfo[i]->s_treeID, m_treeInfo[i]->s_printOrder);
            m_treeForest[i] = ptr;
        }

    }
    else if(dataType == 1 && numType == 1)
    {
      /* static_cast to <YourAVLTreeClassName<std::string, float>*> if needed */
        
        AVLNode<std::string, int>* ptr = static_cast<AVLNode<std::string, int>* >(m_treeForest[i]);
        
        //convert string to float
        std::stringstream stringToNum(strArray[1]);
        float dataNum;
        stringToNum >> dataNum;
        
        //if inserting into empty tree
        if (ptr->getIsEmpty() == true){
            ptr = ptr->createFirstNode(ptr, strArray[0], dataNum);
        }
        else{
            ptr = ptr->createNode(ptr, strArray[0], dataNum, m_treeInfo[i]->s_treeID, m_treeInfo[i]->s_printOrder);
            m_treeForest[i] = ptr;
        }
    }
    else
    {
      // invalid case
    }
     
}
}


std::ostream& operator << (std::ostream& out, AVLForest& avlForest)
{
  // print all trees
  for(int i = 0; i < avlForest.m_treeForest.size(); i++)
  {
    //get tree type
    int dataType = avlForest.m_treeInfo[i]->s_dataType;
    int numType = avlForest.m_treeInfo[i]->s_numType;

    if(dataType == 0 && numType == 0)
    {
        AVLNode<char, int>* ptr = static_cast<AVLNode<char, int>* >(avlForest.m_treeForest[i]);
        ptr->printNode(ptr, out);
        out<<"\n";
    }
      
    else if(dataType == 0 && numType == 1)
    {
      /* static_cast to <YourAVLTreeClassName<char, float>*> and print */
        AVLNode<char, float>* ptr = static_cast<AVLNode<char, float>* >(avlForest.m_treeForest[i]);
        ptr->printNode(ptr, out);
        out<<"\n";
    }
      
    else if(dataType == 1 && numType == 0)
    {
      /* static_cast to <YourAVLTreeClassName<std::string, int>*> and print */
        AVLNode<std::string, int>* ptr = static_cast<AVLNode<std::string, int>* >(avlForest.m_treeForest[i]);
        ptr->printNode(ptr, out);
        out<<"\n";
    }
      
    else if(dataType == 1 && numType == 1)
    {
      /* static_cast to <YourAVLTreeClassName<std::string, float>*> and print */
        AVLNode<std::string, float>* ptr = static_cast<AVLNode<std::string, float>* >(avlForest.m_treeForest[i]);
        ptr->printNode(ptr, out);
        out<<"\n";
    }
    else
    {
      // invalid case
    }
  }

  return out;
}

void AVLForest::print_range(std::ostream& outStream, std::string line){
    //read in treeID
    std::stringstream ss(line);
    int treeID, i;
    
    ss >> treeID;
    ss.ignore();

    //find correct tree to print
    for (i = 0; i < m_treeInfo.size(); i++){
        if (treeID == m_treeInfo[i]->s_treeID){
            break;
        }
    }


    int dataType = m_treeInfo[i]->s_dataType;
    int numType = m_treeInfo[i]->s_numType;
    
    if(dataType == 0 && numType == 0)
    {
        //convert string to number
        int lower, upper;
        ss >> lower;
        ss.ignore();
        ss >> upper;
        
        AVLNode<char, int>* ptr = static_cast<AVLNode<char, int>* >(m_treeForest[i]);
            ptr->print_range(outStream, lower, upper);
            outStream<<"\n";
        }
        
        else if(dataType == 0 && numType == 1)
        {
            //convert string to number
            float lower, upper;
            ss >> lower;
            ss.ignore();
            ss >> upper;
            
            AVLNode<char, float>* ptr = static_cast<AVLNode<char, float>* >(m_treeForest[i]);
            ptr->print_range(outStream, lower, upper);
            outStream<<"\n";
        }
        
        else if(dataType == 1 && numType == 0)
        {
            //convert string to number
            int lower, upper;
            ss >> lower;
            ss.ignore();
            ss >> upper;
            
            AVLNode<std::string, int>* ptr = static_cast<AVLNode<std::string, int>* >(m_treeForest[i]);
            ptr->print_range(outStream, lower, upper);
            outStream<<"\n";
        }
        
        else if(dataType == 1 && numType == 1)
        {
            //convert string to number
            float lower, upper;
            ss >> lower;
            ss.ignore();
            ss >> upper;
            
            AVLNode<std::string, float>* ptr = static_cast<AVLNode<std::string, float>* >(m_treeForest[i]);
            ptr->print_range(outStream, lower, upper);
            outStream<<"\n";
        }
        else
        {
            // invalid case
        }
    

}

