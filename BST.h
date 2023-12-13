#include <iostream>
#include "CLQueue.h"
#include "AUList.h"
struct TNode {
  public:
  int placement;
  AUList PlayersByPlacement;
  TNode *left;
  TNode *right;
};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};


class BST {
  public:
  BST();
  BST(const BST& originalBST); //(Deep-)Copy constructor
  ~BST(); //Destructor
  
  
  //main BST functions that call helper functions using the root Node
  AUList GetItem(int gitem);
  void PutItem(int newitem, AUList PlayersByPlacement);
  void DeleteItem(int ditem);
  int GetLength();
  void MakeEmpty();
  bool IsEmpty();
  bool IsFull();
  void PrintTree();
  void ResetTree(OrderType order);
  int GetNextItem();
  bool TravEmpty();

  
  private:
  //helper functions called to recursively view/manipulate sub-tree elements
  void Insert (TNode* &curnode, int newitem, AUList PlayersByPlacement);
  AUList FindItem(TNode* curnode, int gitem);
  void Delete(TNode* &curnode, int ditem);
  void DeleteNode(TNode* &curnode);
  int CountNodes(TNode* curnode);
  void PrintNodes(TNode* curnode);
  void CopyNodes(TNode*& copyNode, const TNode* origNode);
  void DestroyNodes(TNode*& curNode);
  void PreNodes(TNode* curNode);
  void InNodes(TNode* curNode);
  void PostNodes(TNode* curNode);
  TNode *root;
  CLQueue *TravQueue;
};
