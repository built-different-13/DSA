// Include Header Files
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Make Binary Tree Node Class
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

// Take Input from the User LevelWise
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter the rootData" << endl;
    cin >> rootData;
    if(rootData==-1) return nullptr;

    // Make Root
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    // Initialize a Queue
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cout << "Enter the leftChild of " << front->data << endl;
        cin >> leftChild;
        if(leftChild!=-1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }

        int rightChild;
        cout << "Enter the rightChild of " << front->data << endl;
        cin >> rightChild;
        if(rightChild!=-1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }

    // Return the root
    return root;
}

// Make leftMax Function 
int maximum(BinaryTreeNode<int>* root) {

    // Base Case
    if(root==nullptr) return INT_MIN;

    // Return the Maximum Value
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

// Make rightMin Function
int minimum(BinaryTreeNode<int>* root) {

    // Base Case
    if(root==nullptr) return INT_MAX;

    // Return the Minimum Value
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

// Check Whether Binary Tree is BST or Not
bool isBST(BinaryTreeNode<int>* root) {

    // Base Case
    if(root==nullptr) return true;

    // Calculate the leftMax and rightMin
     int leftMax = maximum(root->left);
     int rightMin = minimum(root->right);

     // Check condition for BST
     bool output = (root->data>leftMax) && (root->data<=rightMin) && (isBST(root->left)) && (isBST(root->right));

     // Return the Output
     return output;
}

// Main Function of the Program
int main() {
    BinaryTreeNode<int>* root = takeInput();
    bool ans = isBST(root);
    if(ans) {
        cout << "It is a valid BST" << endl;
    } else {
        cout << "It is not a valid BST" << endl;
    }
    delete root;
    return 0;
}