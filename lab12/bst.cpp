#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

int isBSTUtil(Node* node, int min, int max)  
{  
  if (node==NULL)  
     return 1; 
        
  if (node->key < min || node->key > max)  
     return 0;  
  
  return 
    isBSTUtil(node->left, min, node->key-1) &&  // Allow only distinct values 
    isBSTUtil(node->right, node->key+1, max);  // Allow only distinct values 
} 
//Helper functions?
bool isBST(Node *root) {

	 return(isBSTUtil(root, INT_MIN, INT_MAX));  
}  

int height(Node* node) 
{ 
   if(node == NULL) 
       return 0; 
   return 1 + max(height(node->left), height(node->right)); 
}  
   
    
//Helper functions?
bool isBalanced(Node *root) {
   int lh; 
   int rh;

   if(root == NULL) 
    return 1;  
  
   lh = height(root->left); 
   rh = height(root->right); 
  
   if( abs(lh-rh) <= 1 && 
       isBalanced(root->left) && 
       isBalanced(root->right)) 
     return 1; 
 
   return 0;    
}