/* Finding the max Depth of the given tree */
#include<iostream>
using namespace std;

struct TreeNode {
   int val;
   struct TreeNode* left;
   struct TreeNode* right;
   TreeNode():val(0),left(nullptr),right(nullptr) {}
   TreeNode(int v):val(v),left(nullptr),right(nullptr) {}
};

//code to find the max Depth
int maxDepth(TreeNode* root) {
   if(root==nullptr) return 0;
   int leftDepth = maxDepth(root->left);
   int rightDepth= maxDepth(root->right);
   return 1+max(leftDepth,rightDepth);
}
int main() {
  //preparing the tree
  TreeNode* root=new TreeNode(3);
  root->left=new TreeNode(9);
  root->right=new TreeNode(20);
  //root->right->left=new TreeNode(21);
  //root->right->right=new TreeNode(4);
  
  cout<<"\n Max Depth : "<<maxDepth(root);
}
