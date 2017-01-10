/*
 * File:            AVLForest.h
 * Project:         3
 * Author:          Joshua Meyer
 * Date created:    10/26/16
 * Section:         01
 * Username:        jmey1@umbc.edu
 * AVLForest.h contains the headers for the AVLForest functions and members
 */

#ifndef _AVLFOREST_H_
#define _AVLFOREST_H_

/* include your tree implementation  */
#include <vector>
#include <string>
#include "AVLNode.h"

class AVLForest
{
  // vector of trees
  // we use a non-templated base class so we can hold all template instantiations
  std::vector<AVLTreeBase*> m_treeForest;

  // other data memebers

  //used to hold information about created trees
  struct TREEINFO {
    int s_dataType;
    int s_numType;
    int s_treeID;
    int s_printOrder;
  };
    
  //holds TREEINFOs
  std::vector<TREEINFO*> m_treeInfo;
  
public:
  AVLForest();
  ~AVLForest();

  void insert(std::string);
  void print_range(std::ostream&, std::string);
  friend std::ostream& operator << (std::ostream&, AVLForest&);

  // other member functions



};

#endif /* _AVLFOREST_H_ */

