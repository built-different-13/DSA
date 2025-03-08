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

// Helper Function
BinaryTreeNode<int>* helperFunction(int *arr, int start, int end) {

    // Base Case
    if(start>end) return nullptr;

    // Find the Mid
    int mid = (start+end)/2;

    // Find the rootData
    int rootData = arr[mid];

    // Make Root
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = helperFunction(arr, start, mid-1);
    root->right = helperFunction(arr, mid+1, end);

    // Return the Root
    return root;
}

// Make BST from Sorted Array
BinaryTreeNode<int>* constructTree(int *arr, int n) {

    BinaryTreeNode<int>* ans = helperFunction(arr,0,n-1);

    return ans;
}

// Print the BinaryTree Node
void print(BinaryTreeNode<int>* root) {

    // Base Case
    if(root==nullptr) return;

    // Initialize a Queue
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
      int size = pendingNodes.size();

      while(size--) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << " ";

        if(front->left!=nullptr) pendingNodes.push(front->left);
        if(front->right!=nullptr) pendingNodes.push(front->right);
      }

      cout << endl;
    }
}

// Main function of the Program
int main() {
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    cout << "Enter the elements of the array" << endl;
    int* arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    BinaryTreeNode<int>* root = constructTree(arr,n);
    cout << "The BST is Printed below" << endl;
    print(root);
    delete [] arr;
    delete root;
    return 0;
}