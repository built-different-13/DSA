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

    // Initialize Queue
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
            pendingNodes.push(child);
            front->left = child;
        }

        int rightChild;
        cout << "Enter the rightChild of " << front->data << endl;
        cin >> rightChild;
        if(rightChild!=-1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
            pendingNodes.push(child);
            front->right = child;
        }
    }

    return root;
}

// Print Nodes in Range
void range(BinaryTreeNode<int>* root, int k1, int k2) {

    // Base Case
    if(root==nullptr) return;

    // Case-1
    if(root->data>k1) {
        range(root->left,k1,k2);
    }

    if(root->data>=k1 && root->data<=k2) {
        cout << root->data << " ";
    }

    // Case-2
    if(root->data<k2) {
        range(root->right,k1,k2);
    }
}

// Main function of the Program
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k1,k2;
    cout << "Enter elements k1 and k2" << endl;
    cin >> k1 >> k2;
    range(root,k1,k2);
    delete root;
    return 0;
}