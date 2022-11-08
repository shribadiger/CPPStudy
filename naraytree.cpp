/* Program to print the level based nodes from the tree */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
public:
    int val;
    vector<struct Node *> children;
    Node() {}
    Node(int _val)
    {
        val = _val;
    }
    Node(int _val, vector<struct Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> level_order(Node *root)
{
    // function to check the each nodes from the level order method
    vector<vector<int>> result;
    std::queue<Node *> nodeList;
    if (root == nullptr)
    {
        return result;
    }

    // if the root node is not null then push value to vector and push node to queue for next
    std::vector<int> level_root;
    level_root.push_back(root->val);
    nodeList.push(root);
    bool isLevelChanged = false;
    std::vector<int> nodes;
    while (!nodeList.empty())
    {
        struct Node *temp = nodeList.front();
        // insert each child node to vectors

        for (int i = 0; i < temp->children.size(); i++)
        {
            nodes.push_back((temp->children[i])->val);
        }
        nodeList.pop();
        if (nodeList.empty())
        {
            // pushing all nodes to queue for next iteration
            for (int i = 0; i < temp->children.size(); i++)
            {
                nodeList.push(temp->children[i]);
            }
            result.push_back(nodes);
            nodes.clear();
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    std::vector<struct Node *> children;
    struct Node *three = new Node(3);
    struct Node *two = new Node(2);
    struct Node *four = new Node(4);
    children.push_back(three);
    children.push_back(two);
    children.push_back(four);
    root->children = children;

    // children for node 3
    struct Node *five = new Node(5);
    struct Node *six = new Node(6);

    std::vector<struct Node *> children1;
    children1.push_back(five);
    children1.push_back(six);
    root->children[0]->children = children1;
}