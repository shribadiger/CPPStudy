/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        // checking the base condition
        if (root == nullptr)
            return root;

        // preparing the stack to push and add basic checks
        stack<Node *> nodes;
        root->next = nullptr;
        if (root->left == nullptr && root->right == nullptr)
            return root; // end of tree
        nodes.push(root->right);
        nodes.push(root->left);
        int level = 2;
        while (!nodes.empty())
        {
            int counter = level;
            vector<Node *> temp;
            while (counter > 0)
            {
                temp.push_back(nodes.top());
                nodes.pop();
                counter--;
            }
            for (int i = 0; i < temp.size() - 1; i++)
            {
                temp[i]->next = temp[i + 1];
            }
            // adding into stack
            for (int i = temp.size() - 1; i >= 0; i--)
            {
                if (temp[i]->right != nullptr && temp[i]->left != nullptr)
                {
                    nodes.push(temp[i]->right);
                    nodes.push(temp[i]->left);
                }
            }
            temp.clear();
            level = 2 * level;
        }

        return root;
    }
};