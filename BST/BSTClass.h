// We are going to Implement BST Class

// Include Header Files
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Make BinaryTreeNode Class
template <typename T>
class BinaryTreeNode{
public:
T data;
BinaryTreeNode* left;
BinaryTreeNode* right;

// Constructor
BinaryTreeNode(T data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

// Destructor
~BinaryTreeNode() {
    delete left;
    delete right;
}
};

// Make BST Class
class BST{
private:
BinaryTreeNode<int>* root;

// Helper Function for Search an Element in BST
bool search(BinaryTreeNode<int>* node, int data) {

    // Base Case
    if(node==nullptr) return false;

    if(node->data==data) return true;
 
   if(data<node->data) {
    return search(node->left, data);
   } else {
    return search(node->right, data);
   }
}

// Helper Function for Insert an Element in BST
BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data) {

    // Base Case
    if(node==nullptr) {
        return new BinaryTreeNode<int>(data);
    }

    if(data<node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }

    // Return the Node
    return node;
}

// Helper Function to find the Maximum Value from the LeftSubtree
void getMax(BinaryTreeNode<int>* node, int& maximum) {

    // Base Case
    if(node==nullptr) return;

    if(node->data>maximum) {
        maximum = node->data;
    }

    getMax(node->right, maximum);
}

// Helper Function for Delete an Element from BST
BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node, int data) {

    // Base Case
    if(root==nullptr) return nullptr;

    // Condition - 1
    if(node->data==data) {
        if(node->left==nullptr && node->right==nullptr) {
            delete node;
            return nullptr;
        }
    }

    // Condition - 2
    if(node->data==data) {
        if(node->left!=nullptr && node->right==nullptr) {
            BinaryTreeNode<int>* temp = node->left;
            delete node;
            return temp;
        }
        if(node->left==nullptr && node->right!=nullptr) {
            BinaryTreeNode<int>* temp = node->right;
            delete node;
            return temp;
        }
    }

    // Condition - 3
    if(node->data==data) {
        if(node->left!=nullptr && node->right!=nullptr) {
           int maximum = INT_MIN;
           getMax(node->left, maximum);
           node->data = maximum;
           node->left = remove(node->left, maximum);
        }
    }

    if(data<node->data) {
        node->left = remove(node->left, data);
    } else{
        node->right = remove(node->right, data);
    }

    return node;
}

// Helper Function to Print the BST
void print(BinaryTreeNode<int>* node) {
    // Base Case
    if(node==nullptr) return;

    cout << node->data << ":";
    if(node->left!=nullptr) {
        cout << "L:" << node->left->data << ",";
    }
    if(node->right!=nullptr) {
        cout << "R:" << node->right->data;
    }

    cout << endl;
    print(root->left);
    print(root->right);
}

public:
BST() {
    root=nullptr;
}

~BST() {
    delete root;
}

bool search(int data) {
    return search(root,data);
}

void insert(int data) {
    root = insert(root,data);
}

void remove(int data) {
    root = remove(root,data);
}

void print() {
    print(root);
}
};