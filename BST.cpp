#include "BST.h"
using namespace std;

  
BST::BST() {
  root=NULL;
  TravQueue=new CLQueue;
}


bool BST::IsFull() { // Returns true if there is no room for another item on the heap; false otherwise.
  TNode* location;
  try
  {
    location = new TNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

int BST::CountNodes(TNode* curnode) { //Return total number of nodes in (sub-)tree denoted by curnode
  if (curnode == NULL)
    return 0;
  else 
    return CountNodes(curnode->left) + CountNodes(curnode->right) + 1;
}

int BST::GetLength()
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
  return CountNodes(root);
}

bool BST::IsEmpty()
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}
  
void BST::Insert (TNode* &curnode, int newitem, AUList PlayersByPlacement) { //Helper function to insert an placement into (sub-)tree denoted by curnode
  if (curnode==NULL) {
    curnode = new TNode;
	curnode->placement = newitem;
	curnode->PlayersByPlacement = PlayersByPlacement;
	curnode->right = NULL;
	curnode->left = NULL;
  } else if (newitem<curnode->placement)
    Insert(curnode->left,newitem, PlayersByPlacement);
  else
    Insert(curnode->right,newitem, PlayersByPlacement);
}
  
AUList BST::FindItem(TNode* curnode, int gitem) { //Helper function to locate an item in (sub-)tree denoted by curnode
  if (curnode == NULL){
    return curnode->PlayersByPlacement;
  }else if (gitem == curnode->placement){
    cout << endl;
    cout << endl;
    cout << "Placement: ";
    cout << curnode->placement;
    cout << endl;
    cout << endl;
	return curnode->PlayersByPlacement;
  }else if (gitem < curnode->placement){
    return FindItem(curnode->left,gitem);
  }else{
    return FindItem(curnode->right,gitem);
	}
}


void BST::DeleteNode(TNode* &delnode) { //Helper function to delete an actual node
  TNode *tmpNode;
  if ((delnode->left) == NULL) { //If left child is null, we can replace with right child (whether NULL or not!)
    tmpNode = delnode;
    delnode = delnode -> right;
    delete(tmpNode);
  } else if ((delnode->right) == NULL) { //Check to see if other easy case applies (right child is NULL, but left is not)
    tmpNode = delnode;
    delnode = delnode -> left;
    delete(tmpNode);
  } else { //Difficult case -- we need to replace item with that of the logical predecessor
    TNode *predecessor = delnode->left;
    while (predecessor->right != NULL) {	
      predecessor = predecessor->right;
    }
    int replaceitem = predecessor->placement;
    delnode->placement = replaceitem;
    Delete(delnode->left, replaceitem);
  }     
  
}



void BST::Delete(TNode* &curnode, int ditem) { //Helper function to delete an item in (sub-)tree denoted by curnode
  if (curnode == NULL)
    throw;
  else if (ditem < curnode->placement)
    Delete(curnode->left, ditem);   // Look in left subtree.
  else if (ditem > curnode->placement)
    Delete(curnode->right, ditem);  // Look in right subtree.
  else
    DeleteNode(curnode);           // Node found; call DeleteNode.
}   


//Main functions always call recursive helper functions using root node as initial node
void BST::PutItem(int newitem, AUList PlayersByPlacement) {
  Insert(root,newitem, PlayersByPlacement);
}  

AUList BST::GetItem(int gitem) {
  return FindItem(root, gitem);
}
  
void BST::DeleteItem(int ditem) {
  Delete(root,ditem);
}

void BST::PrintNodes(TNode* curnode) { // Prints items in (sub-)tree in sorted order
  if (curnode != NULL) {
    PrintNodes(curnode->left);   // Print left subtree.
   	AUList Players = curnode->PlayersByPlacement;
   	cout << endl;
   	cout << endl;
   	cout << "Placemment: ";
   	cout << curnode->placement;
   	cout << endl;
   	cout << endl;
	Players.PrintList(curnode->placement, 0, 0, 0, "N");
    PrintNodes(curnode->right);  // Print right subtree.
  }
}

void BST::PrintTree() {// Calls recursive function PrintNodes to print items in the tree.
  if (IsEmpty())
    std::cout<<"(Empty Tree)"<<std::endl;
  else {
    PrintNodes(root);
    std::cout << "\b\b "<<std::endl;
  }
}

void BST::CopyNodes(TNode*& copyNode, const TNode* origNode) {
  if (origNode == NULL)
    copyNode = NULL;
  else {
    copyNode = new TNode;
    copyNode->placement = origNode->placement;
    CopyNodes(copyNode->left, origNode->left);
    CopyNodes(copyNode->right, origNode->right);
  }
}

BST::BST(const BST& originalBST) { //Constructor that calls recursive function CopyNodes to copy original tree into root
  CopyNodes(root, originalBST.root);
  TravQueue=new CLQueue;
}

void BST::DestroyNodes(TNode*& curNode) {
  if (curNode != NULL) {
    DestroyNodes(curNode->left);
    DestroyNodes(curNode->right);
    delete curNode;
  }
}


void BST::MakeEmpty() {
  DestroyNodes(root);
  root=NULL;
}

BST::~BST() { //Destructor -- calls recursive Function DestroyNodes to destroy tree starting from root
  DestroyNodes(root);
  //std::cout<<"Destruction Complete!"<<std::endl;
}

bool BST::TravEmpty() {
  return TravQueue->IsEmpty();	
}

void BST::PreNodes(TNode* curNode) {    
  if (curNode!=NULL) {
    TravQueue->Enqueue(curNode->placement);
	PreNodes(curNode->left);    
    PreNodes(curNode->right);
  }
}

void BST::InNodes(TNode* curNode) {    
  if (curNode!=NULL) {
    InNodes(curNode->left);
    TravQueue->Enqueue(curNode->placement);
    InNodes(curNode->right);
  }
}

void BST::PostNodes(TNode* curNode) {    
  if (curNode!=NULL) {
    PostNodes(curNode->left);    
    PostNodes(curNode->right);
    TravQueue->Enqueue(curNode->placement);
  }
}

int BST::GetNextItem() {
	if (TravQueue->IsEmpty())
	  return INT_MIN;
	else
	  return (TravQueue->Dequeue());
}

void BST::ResetTree(OrderType order) {
// Calls function to create a queue of the tree elements in 
// the desired order.
  TravQueue->MakeEmpty();  
  switch (order) {
    case PRE_ORDER : PreNodes(root);
                     break;
    case IN_ORDER  : InNodes(root);
                     break;
    case POST_ORDER: PostNodes(root);
                     break;
  }
  
}

