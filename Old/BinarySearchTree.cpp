#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BST_Node {
	public:
		int key;
		BST_Node* left;
		BST_Node* right;
		BST_Node();
		BST_Node(int);

};

BST_Node::BST_Node() {
	key=0;
	left=NULL;
	right=NULL;
}

BST_Node::BST_Node(int val) {
	key=val;
	left=NULL;
	right=NULL;
}


class BST {
	public:
		BST_Node* insertNode(BST_Node* root, int value);

		bool searchNode(BST_Node* root, int value);

		BST_Node* deleteNode(BST_Node*, int);

		BST_Node* minValueNode(BST_Node*);

};

BST_Node* BST::insertNode(BST_Node* root, int value) {
	if(root == NULL) {
		//Empty Tree with empty ro
		root= new BST_Node(value);
		cout<<"\nNode: "<<root->key;
	}
	else if ( value < root->key) {
		//Left Tree need to be considered to insert value
		std::cout<<"\n Left Tree -->";
		root->left = insertNode(root->left, value);
	}
	else {
		std::cout<<"\n Right Tree -->";
		root->right = insertNode(root->right,value);
	}
	return root;
}

bool BST::searchNode(BST_Node* root, int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->key == data) {
		return true;
	}
	else if(data <= root->key) {
		std::cout<<"\n Left side search\n";
		return searchNode(root->left,data);
	}
	else{
		std::cout<<"\n Right side search\n";
		return searchNode(root->right,data);
	}
}

BST_Node* BST::minValueNode(BST_Node* node) {
	BST_Node* current = node;
	while(current && current->left != NULL) {
		current=current->left;
	}
	return current;
}

BST_Node* BST::deleteNode(BST_Node* root, int data) {
	if(root == NULL) return root;

	if(data < root->key) {
		root->left = deleteNode(root->left, data);
	}

	else if ( data > root->key) {
		root->right = deleteNode(root->right,data);
	}
	else if(data == root->key) {
		if(root->left == NULL) {
			BST_Node* tmp = root->right;
			free(root);
			return tmp;
		}
		else if(root->right == NULL) {
			BST_Node* tmp = root->left;
			free(root);
			return tmp;
		}
		
		BST_Node* tmp = minValueNode(root->right);
		root->key = tmp->key;
		root->right=deleteNode(root->right,tmp->key);
	}
	return root;
}
int main() {
	BST_Node* root = NULL;
	BST *tree = new BST();
	root = tree->insertNode(root,15);
	root = tree->insertNode(root,10);
	root = tree->insertNode(root,18);
	root = tree->insertNode(root,6);
	root = tree->insertNode(root,8);
	root = tree->insertNode(root,19);
	root = tree->deleteNode(root,18);
	bool found = tree->searchNode(root,18);
	if(found) {
		std::cout<<"\n Value Present\n";
	}
	else {
		std::cout<<"\n Value Not Present\n";
	}
}




