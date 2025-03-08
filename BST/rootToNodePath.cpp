// Include Header Files
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Make Linked List Class
template <typename T>
class Node{
public:
T data;
Node* next;

// Constructor
Node(T data) {
    this->data = data;
    this->next = nullptr;
}
};

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
    this->left = nullptr;
    this->right = nullptr;
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

    // Return the Root
    return root;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
       
    // Base Case
    if(root==nullptr) return nullptr;

    if(root->data==data) {
        vector<int>* v = new vector<int>();
        v->push_back(root->data);
        return v;
    }

    vector<int>* left = getRootToNodePath(root->left, data);
    if(left!=nullptr) {
        left->push_back(root->data);
        return left;
    }

    vector<int>* right = getRootToNodePath(root->right, data);
    if(right!=nullptr) {
        right->push_back(root->data);
        return right;
    } 
    return nullptr;
}

// Main Function of the Program
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << "Enter the node to be search" << endl;
    int node;
    cin >> node;
    vector<int>* output = getRootToNodePath(root, node);
    cout << "The Root to Node Path is Printed below" << endl;
    for (int i=0; i<output->size(); i++) {
        cout << output->at(i) << " ";
    }
    delete root;
    delete output;
    return 0;
}