/* Creating the BST based on the input array */
#include <iostream>
#include <vector>
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

TreeNode *generateBST(std::vector<int> input, int start, int end)
{
    if (start > end)
        return nullptr;
    // find the mid of the array to get the root node
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(input[mid]);
    root->left = generateBST(input, start, mid - 1);
    root->right = generateBST(input, mid + 1, end);
    return root;
}
void print_tree(TreeNode *root)
{
    if (root != nullptr)
    {

        print_tree(root->left);
        cout << "\t" << root->val;
        print_tree(root->right);
    }
}
int main()
{
    std::vector<int> input = {-10, -3, 1, 5, 9};
    TreeNode *root = generateBST(input, 0, input.size() - 1);
    print_tree(root);
    return 0;
}