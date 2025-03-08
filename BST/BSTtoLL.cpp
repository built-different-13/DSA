// Include Header Files
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Make Linked List Node Class
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

    // Make a Root
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

// Helper Function
pair<Node<int>*, Node<int>*> helperFunction(BinaryTreeNode<int>* root) {

    // Base Case
    if(root==nullptr) {
        pair<Node<int>*, Node<int>*> output;
        output.first = nullptr;
        output.second = nullptr;
        return output;
    }

    pair<Node<int>*, Node<int>*> leftAns = helperFunction(root->left);
    pair<Node<int>*, Node<int>*> rightAns = helperFunction(root->right);

    // Make Node
    Node<int>* node1 = new Node<int>(root->data);

    if(leftAns.first!=nullptr) {
        leftAns.second->next = node1;
    }
    node1->next = rightAns.first;

    // Return the Final Head and Final Tail
    pair<Node<int>*, Node<int>*> ans;
    if(leftAns.first!=nullptr) {
        ans.first = leftAns.first;
    } else {
        ans.first = node1;
    }
    if(rightAns.second!=nullptr) {
        ans.second = rightAns.second;
    } else {
        ans.second = node1;
    }

    // Return the Pair
    return ans;
}

// Return the Head of the Linked List
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
      pair<Node<int>*, Node<int>*> output = helperFunction(root);
      return output.first;
}

// Print the Linked List
void print(Node<int>* head) {

    // Base Case
    if(head==nullptr) return;

    Node<int>* temp = head;
    while(temp!=nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
} 

// Main Function of the Program
int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);
    cout << "The Linked List id printed below" << endl;
    print(head);
    delete root;
    return 0;
}