#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//structure to hold the node information
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right):val(_val), left(_left),right(_right){}
};


std::vector<int> inorder_stack(TreeNode* root){
    //checking the root node before processing 
    std::vector<int> result;
    std::stack<TreeNode*> nodes_stack;
    if(root == nullptr) return result;

    // loop unlimited to trace all nodes of the tree
    while(1) {
        // iterating each nodes of tree and push to stack
        while(root!=nullptr) {
            nodes_stack.push(root);
            root=root->left;
        }
        //checking the each of the stack if no more elements to trace out
        if(nodes_stack.empty()) break;

        TreeNode* temp = nodes_stack.top();
        nodes_stack.pop();
        result.push_back(temp->val);
        root=temp->right;
    }
    return result;
}
int main() {
    //preparation of the tree
    TreeNode* root=new TreeNode(1);
    //root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    std::vector<int> result = inorder_stack(root); // calling the inorder method with stack usage
    for(int i=0;i<result.size();i++)
    {
        cout<<"\t"<<result[i];
    }
    return 1;
}