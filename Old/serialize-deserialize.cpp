/*
 * Exmaple to serialize and de-serialize the Tree Data structure
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

TreeNode *insert_node(TreeNode *root, int val)
{
    if (root == NULL)
    {
        TreeNode *temp = new TreeNode(val);
        return temp;
    }

    if (val <= root->val)
        root->left = insert_node(root->left, val);

    else
        root->right = insert_node(root->right, val);

    return root;
}

std::string encode(TreeNode *root)
{
    // preparing the result serialized string
    /*if (root == nullptr)
    {
        result.push_back('#');
        return;
    }
    cout << "Pushing nummber: " << root->val << " char : " << static_cast<char>('a' + root->val) << endl;
    // result.push_back(static_cast<char>(root->val));
    result.push_back(static_cast<char>('a' + root->val));
    prepare_serialize_string(root->left, result);
    prepare_serialize_string(root->right, result); */
    if (!root)
        return "";
    return to_string(root->val) + "-" + encode(root->left) + encode(root->right);
}
std::string
serialize_tree(TreeNode *root)
{
    // serializing the string
    std::string result;
    return encode(root);
}

TreeNode *
deserilize_tree(std::string data)
{
    stringstream ss(data);
    string item;
    TreeNode *root = NULL;

    while (getline(ss, item, '-'))
        root = insert_node(root, stoi(item));

    return root;
}

void print_tree(TreeNode *root)
{
    if (root != nullptr)
        return;
    cout << "\t" << root->val;
    print_tree(root->left);
    print_tree(root->right);
}
int main(int argc, char *argv[])
{
    // prepare the tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    std::string input = serialize_tree(root);
    cout << "\n Final Result: " << input;
    TreeNode *resultNode = deserilize_tree(input);
    print_tree(resultNode);
    return 0;
}