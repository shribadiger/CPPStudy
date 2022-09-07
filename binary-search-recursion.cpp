/* checking the TreeNode in binary search  */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

// Function to check the each level values
vector<double> averageOfLevel(struct TreeNode *root)
{
    vector<double> result;
    int numberOfNodesInQueue; // holds the value of each level -- indicate number of nodes in each level of the tree
    int sumOfNodesOfEachLevel = 0;
    // insert the first root to the queue
    queue<struct TreeNode *> nodeQueue;
    nodeQueue.push(root);
    // repeating the each nodes of the queue and checking it
    while (!nodeQueue.empty())
    {
        numberOfNodesInQueue = nodeQueue.size();
        double devider = numberOfNodesInQueue;
        for (int i = 0; i < numberOfNodesInQueue; i++)
        {
            TreeNode *frontNode = nodeQueue.front();
            sumOfNodesOfEachLevel += frontNode->val;
            // remove the node from the queue
            nodeQueue.pop();
            if (frontNode->left != nullptr)
                nodeQueue.push(frontNode->left);
            if (frontNode->right != nullptr)
                nodeQueue.push(frontNode->right);
        }
        cout << "\n Sum:" << sumOfNodesOfEachLevel;
        cout << "\n Level : " << numberOfNodesInQueue;
        double res = sumOfNodesOfEachLevel / devider;
        result.push_back(res);
        sumOfNodesOfEachLevel = 0;
        numberOfNodesInQueue = 0;
    }
    return result;
}

void print_tree(struct TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << "\t" << root->val;
    print_tree(root->left);
    print_tree(root->right);
}
int main()
{
    // prepare the binary tree to check the functionality input
    struct TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    print_tree(root);

    // getting the result from the function
    vector<double> result = averageOfLevel(root);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "\t" << result[i];
    }

    return 0;
}