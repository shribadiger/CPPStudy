/*
 Testing the c++ code for binary Tree and there examples
 */
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
class TreeNode
{
public:
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
        // default constructor
    }
    TreeNode(char _val) : val(_val), left(nullptr), right(nullptr)
    {
        // parameterized constructor
    }

    TreeNode(char _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right)
    {
        // all param constructor
    }
};

class TreeNodeInt
{
public:
    int val;
    TreeNodeInt *left;
    TreeNodeInt *right;
    TreeNodeInt() : val(0), left(nullptr), right(nullptr)
    {
        // default constructor
    }
    TreeNodeInt(int _val) : val(_val), left(nullptr), right(nullptr)
    {
        // parameterized constructor
    }

    TreeNodeInt(int _val, TreeNodeInt *_left, TreeNodeInt *_right) : val(_val), left(_left), right(_right)
    {
        // all param constructor
    }
};
std::vector<char> depth_first_value(TreeNode *root)
{
    std::stack<TreeNode *> TreeNodeStack;
    std::vector<char> result;
    // checking the root node
    if (root == nullptr)
    {
        cout << "\n Empty Tree \n";
        return result;
    }

    TreeNodeStack.push(root);
    while (!TreeNodeStack.empty())
    {
        TreeNode *currNode = TreeNodeStack.top();
        TreeNodeStack.pop(); // removing that element and adding into vector
        result.push_back(currNode->val);
        if (currNode->right != nullptr)
            TreeNodeStack.push(currNode->right);
        if (currNode->left != nullptr)
            TreeNodeStack.push(currNode->left);
    }
    return result;
}
std::vector<char> result1;
void recursive_dfs(TreeNode *root)
{
    if (root != nullptr)
    {
        result1.push_back(root->val);
        recursive_dfs(root->left);
        recursive_dfs(root->right);
    }
}

// Let write the code to print each level nodes
void print_level_nodes(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "\n Empty Tree\n";
    }
    // declare the queue to hold the each nodes of the tree
    std::queue<TreeNode *> NodeQueue;
    // push root node to queue and iterate each time
    int level_node_count = 0; // to iterate each nodes of the level
    int levels = 0;
    NodeQueue.push(root);
    while (!NodeQueue.empty())
    {
        // get the size of each level - number of nodes
        level_node_count = NodeQueue.size();
        levels++;
        cout << "\n Nodes at level : " << levels;
        while (level_node_count > 0)
        {
            TreeNode *head = NodeQueue.front();
            NodeQueue.pop();    // remove from the queue
            level_node_count--; // decrease the number of nodes in each level
            cout << "\t" << head->val;
            // insert each nodes from the head node
            if (head->left != nullptr)
                NodeQueue.push(head->left);
            if (head->right != nullptr)
                NodeQueue.push(head->right);
        }
        cout << "\n";
    }
}

// Function to check the node exists in the given binary tree
bool isNodeExistInBinaryTree(TreeNode *root, char _val)
{
    if (root != nullptr)
    {
        if (root->val == _val)
        {
            return true;
        }
        return (isNodeExistInBinaryTree(root->left, _val) || isNodeExistInBinaryTree(root->right, _val));
    }
    return false;
}

int get_sum_tree_nodes(TreeNodeInt *root)
{
    // checking the root node is null or not
    if (root == nullptr)
        return 0;
    return (root->val + get_sum_tree_nodes(root->left) + get_sum_tree_nodes(root->right));
}

/* Finding the minimum value in the tree */
void get_min_value(TreeNodeInt *root, int &minVal)
{
    // checking the root node
    if (root == nullptr)
        return;
    if (root->val < minVal)
        minVal = root->val;
    get_min_value(root->left, minVal);
    get_min_value(root->right, minVal);
}

int get_max_sum_path(TreeNodeInt *root)
{
    if (root == nullptr)
        return INT_MIN;
    if (root->left == nullptr && root->right == nullptr)
        return root->val; // returning the child value

    // do some calculation
    int maxVal = std::max(get_max_sum_path(root->left), get_max_sum_path(root->right));
    return maxVal + root->val;
}
int main()
{
    // prepare some nodes
    /*TreeNode *a = new TreeNode('a');
    TreeNode *b = new TreeNode('b');
    TreeNode *c = new TreeNode('c');
    TreeNode *d = new TreeNode('d');
    TreeNode *e = new TreeNode('e');
    TreeNode *f = new TreeNode('f');

    // preparation of tree directly
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    std::vector<char> result = depth_first_value(a);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "\t" << result[i];
    }
    cout << "\n Calling the recursive function\n";
    recursive_dfs(a);
    for (int i = 0; i < result1.size(); i++)
    {
        cout << "\t" << result1[i];
    }

    print_level_nodes(a);
    char value = 'c';
    if (isNodeExistInBinaryTree(a, value))
    {
        cout << "\n Node Value " << value << " found ";
    }
    else
    {
        cout << "\n Node value " << value << " not present";
    }
    */
    // let prepare the integer tree and check the values
    // prepare some nodes
    TreeNodeInt *a = new TreeNodeInt(5);
    TreeNodeInt *b = new TreeNodeInt(11);
    TreeNodeInt *c = new TreeNodeInt(4);
    TreeNodeInt *d = new TreeNodeInt(3);
    TreeNodeInt *e = new TreeNodeInt(2);
    TreeNodeInt *f = new TreeNodeInt(1);

    // preparation of tree directly
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    int minVal = INT_MAX;
    cout << "\n Sum : " << get_sum_tree_nodes(a);
    get_min_value(a, minVal);
    cout << "\n Minimum Value : " << minVal << endl;
    cout << "\n Max: " << get_max_sum_path(a);
    return 0;
}