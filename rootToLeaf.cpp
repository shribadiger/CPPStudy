/* Finding the path exist inside the tree and to vector*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// let have the complete tree printing
void printTree(TreeNode *root, int target)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> NodeStack;
    NodeStack.push(root);
    int sum = 0;
    vector<int> nodes;
    while (!NodeStack.empty())
    {
        TreeNode *currNode = NodeStack.top();
        NodeStack.pop(); // remove from the tree
        // cout << "\t" << currNode->val;
        sum = sum + currNode->val;
        nodes.push_back(currNode->val);
        // cout << "\n Sum : " << sum;
        if (currNode->right != nullptr)
            NodeStack.push(currNode->right);
        if (currNode->left != nullptr)
            NodeStack.push(currNode->left);
        if (sum == target)
        {
            // found the exact node
            cout << "\n Sum mataches:";
            for (auto val : nodes)
            {
                cout << "\t" << val;
            }
            sum = sum - currNode->val;

            nodes.pop_back(); // removing one element
            cout << "\n Removing Element\n";
            for (auto val : nodes)
            {
                cout << "\t" << val;
            }
            cout << "\n";
        }
        // checking that leaf node reached
        if (currNode->left == nullptr && currNode->right == nullptr)
        {
            if (sum != target)
            {
                sum = sum - currNode->val;
                nodes.pop_back();
            }
        }
    }
}
// Function to find the path inside the tree with target value
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> result;
    return result;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(1);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(2);
    root->right->right->right = new TreeNode(2);

    // calling the printTree
    printTree(root, 6);

    /* vector<vector<int>> res = pathSum(root, 22);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << "\t" << res[i][j];
        }
        cout << endl;
    }
    */
}
