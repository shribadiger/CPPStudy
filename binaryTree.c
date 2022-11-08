/*
 * Program to illustrate about the binary tree and its implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>

#define MAX_SIZE 100 // it define the maximum size of the tree.

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} NODE;

NODE *getNewNode(int input)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = input;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(NODE *root)
{
    if (root != NULL)
    {
        printf("\t %d", root->value);
        inorder(root->left);
        inorder(root->right);
    }
}

void preorder(NODE *root)
{
    if (root != NULL)
    {
        preorder(root->left);
        printf("\t%d", root->value);
        preorder(root->right);
    }
}

void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("\t%d", root->value);
    }
}

int main()
{
    NODE *root = getNewNode(1);
    root->left = getNewNode(2);
    root->right = getNewNode(3);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return (0);
}
