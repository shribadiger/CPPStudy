/*
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root. */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
};

void insertNodeToTree(TreeNode **root, int val, int insert_val, int position)
{
    std::queue<TreeNode *> nodes;
    TreeNode *itr = *root;
    if (itr == nullptr)
        return;
    nodes.push(itr);
    while (!nodes.empty())
    {
        // checking the value matches to target value
        TreeNode *temp = nodes.front();
        nodes.pop();
        if (temp->val == val)
        {
            cout << "\n After getting the matching value\n";
            if (position == 1)
            {
                // inserting left side
                TreeNode *newNode = new TreeNode(insert_val);
                temp->left = newNode;
            }
            else
            {
                TreeNode *newNode = new TreeNode(insert_val);
                temp->right = newNode;
            }
            break;
        }
        if (temp->left != nullptr)
            nodes.push(temp->left);
        if (temp->right != nullptr)
            nodes.push(temp->right);
    }
}
TreeNode *generate_binary_tree(vector<vector<int>> &input)
{
    // prepare the first node and add value to it
    TreeNode *root = nullptr;
    if (input.size() != 0)
    {
        root = new TreeNode(input[0][0]);
        if (input[0][2] == 1)
        {
            // insert the node to left
            root->left = new TreeNode(input[0][1]);
        }
    }
    for (int i = 1; i < input.size(); i++) // iterating each element of the vector and check the nodes presence state
    {
        // iterate from root and insert at right place
        std::queue<TreeNode *> nodes;
        insertNodeToTree(&root, input[i][0], input[i][1], input[i][2]);
    }
    return root;
}

void print_tree(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << "\t" << root->val;
        print_tree(root->left);
        print_tree(root->right);
    }
}

int main()
{
    std::vector<std::vector<int>> input = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode *root = generate_binary_tree(input);
    print_tree(root);
    return 0;
}