// Include Header Files
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Make Priority Queue Class
class PriorityQueue{
vector<int> pq;

public:
// Constructor
PriorityQueue() {

}

// Create isEmpty Function
bool isEmpty() {
    return pq.size()==0;
}

// Create getSize Function
int getSize() {
    return pq.size();
}

// Create getMin Function
int getMin() {
    
    // Condition
    if(isEmpty()) {
        cout << "Priority Queue is Empty" << endl;
        return INT_MAX;
    }
    return pq[0];
}

// Create insert Function
void insert(int element) {
    pq.push_back(element);

    int childIndex = pq.size()-1;
   
    while(childIndex>0) {
    int parentIndex = (childIndex-1)/2;
    if(pq[parentIndex]>pq[childIndex]) {
        int temp = pq[parentIndex];
        pq[parentIndex] = pq[childIndex];
        pq[childIndex] = temp;
    } else {
        break;
    }
    childIndex = parentIndex;
}
}

// Create removeMin Function
int removeMin() {

    // Condition
    if(isEmpty()) {
        cout << "Priority Queue is Empty" << endl;
        return INT_MAX;
    }

    int ans = pq[0];
    pq[0] = pq[pq.size()-1];
    pq.pop_back();

    int parentIndex = 0;
    int leftChildIndex = (2*parentIndex)+1;
    int rightChildIndex = (2*parentIndex)+2;

    while(leftChildIndex<pq.size()) {
    int minIndex = parentIndex;
    if(pq[leftChildIndex]<pq[minIndex]) {
        minIndex = leftChildIndex;
    }
    if(rightChildIndex<pq.size() && pq[rightChildIndex]<pq[minIndex]) {
        minIndex = rightChildIndex;
    }

    if(parentIndex==minIndex) break;

    int temp = pq[parentIndex];
    pq[parentIndex] = pq[minIndex];
    pq[minIndex] = temp;

    parentIndex = minIndex;
    leftChildIndex = (2*parentIndex)+1;
    rightChildIndex = (2*parentIndex)+2;
}
return ans;
}
};

int main() {
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;
    while(!p.isEmpty()) {
        cout << p.removeMin() << " ";
    }
}