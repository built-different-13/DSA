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
    return root;
}

// Check whether Node is present in BST or Not
bool searchInBST(BinaryTreeNode<int>* root, int target) {

    // Base Case
    if(root==nullptr) return false;

    if(root->data==target) return true;

    if(target>root->data) {
        bool ans = searchInBST(root->right,target);
        if(ans) return true;
    } else if(target<root->data) {
        bool ans = searchInBST(root->left,target);
        if(ans) return true;
    }

    return false;
}

// Main function of the Program
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int target;
    cout << "Enter the node to be search" << endl;
    cin >> target;
    bool ans = searchInBST(root,target);
    if(ans) {
        cout << "The node is Present in BST" << endl;
    } else {
        cout << "The node is not Present in BST" << endl;
    }
    delete root;
    return 0;
}