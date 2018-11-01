#include "traversal.h"

//include what you need :D
#include <vector>
#include <iostream>

using namespace std;

void PreOrder(vector<int>& result, Node *start) {
	result.push_back(start->val);
 	if(start->left != nullptr) {
        PreOrder(result, start->left);
    }
    if(start->right != nullptr) {
        PreOrder(result, start->right);
    }
}

void InOrder(vector<int>& result, Node *start) {
 	if(start->left != nullptr) {
        InOrder(result, start->left);
    }
    result.push_back(start->val);
    if(start->right != nullptr) {
        InOrder(result, start->right);
    }
}

void PostOrder(vector<int>& result, Node *start) {
 	if(start->left != nullptr) {
        PostOrder(result, start->left);
    }
    if(start->right != nullptr) {
        PostOrder(result, start->right);
    }
    result.push_back(start->val);
}

//helper functions are encouraged :D
void LevelOrder(vector<int>& result, Node *start) {
	if (start == nullptr) return;  
    vector<Node*> q;  
    q.push_back(start);  
  
    while (!q.empty()) 
    {  
        Node *node = q.front();  
        result.push_back(node->val);
        q.erase(q.begin(),q.begin()+1); 
        if (node->left != nullptr) {
            q.push_back(node->left);  
        }
        if (node->right != nullptr) { 
            q.push_back(node->right);  
        }  
    }   
}


bool sym(Node *left,Node *right) 
{ 
    if (left == nullptr && right == nullptr) { return true; }
    if (left && right && left->val == right->val) { return sym(left->left, right->right) && sym(left->right, right->left); }
    return false; 
} 

bool checkSymmetrical(Node *root) { return sym(root, root); } 