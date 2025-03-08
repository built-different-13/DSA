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

// Take Input from the user LevelWise
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter the rootData" << endl;
    cin >> rootData;
    if(rootData==-1) return nullptr;

    // Make Root
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    // Initialize Queue
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cout << "Enter the leftChild of" << front->data << endl;
        cin >> leftChild;
        if(leftChild!=-1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }

        int rightChild;
        cout << "Enter the rightChild of" << front->data << endl;
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

// Check whether Binary Tree is BST or Not
bool isBST3(BinaryTreeNode<int>* root, int min=INT_MIN, int max=INT_MAX) {

    // Base Case
    if(root==nullptr) return true;

    if(root->data<min || root->data>max) return false;

    bool isLeftOk = isBST3(root->left, min, root->data-1);
    bool isRightOk = isBST3(root->right, root->data, max);

    return (isLeftOk) && (isRightOk);
}

// Main Function of the Program
int main() {
    BinaryTreeNode<int>* root = takeInput();
    bool ans = isBST3(root);
    if(ans) {
        cout << "It is a Valid BST" << endl;
    } else {
        cout << "It is not a Valid BST" << endl;
    }
    delete root;
    return 0;
}