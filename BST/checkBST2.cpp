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

// Class Structure of isBST Return
class isBSTReturn{
public:
int minimum;
int maximum;
bool isBST;
};

// Return object of isBST Type
isBSTReturn isBST2(BinaryTreeNode<int>* root) {
     
    // Base Case
    if(root==nullptr) {
        isBSTReturn output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBST = true;
        return output;
    }

    isBSTReturn leftAns = isBST2(root->left);
    isBSTReturn rightAns = isBST2(root->right);

    // Calculate the Values
    int leftMin = leftAns.minimum;
    int leftMax = leftAns.maximum;
    bool leftBST = leftAns.isBST;
    int rightMin = rightAns.minimum;
    int rightMax = rightAns.maximum;
    bool rightBST = rightAns.isBST;

    // Calculate the Overall Minimum and Overall Maximum
    int overallMin = min(root->data, min(leftMin, rightMin));
    int overallMax = max(root->data, max(leftMax, rightMax));
    bool overallisBST = (root->data>leftMax) && (root->data<=rightMin) && (leftBST) && (rightBST);

    // Return the Output
    isBSTReturn output;
    output.minimum = overallMin;
    output.maximum = overallMax;
    output.isBST = overallisBST;

    // Return the Output
    return output;
}

// Main Function of the Program
int main() {
    BinaryTreeNode<int>* root = takeInput();
    isBSTReturn ans = isBST2(root);
    if(ans.isBST==true) {
        cout << "It is valid BST" << endl;
    } else {
        cout << "It is not a valid BST" << endl;
    }
    delete root;
    return 0;
}