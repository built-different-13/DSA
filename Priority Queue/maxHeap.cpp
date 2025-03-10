// Include Header Files
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Make PriorityQueue Class
class PriorityQueue {
vector<int> pq;

public:

// Constructor
PriorityQueue() {

}

// Make isEmpty Function
bool isEmpty() {
    return pq.size()==0;
}

// Make getSize Function
int getSize() {
    return pq.size();
}

// Make getMax Function
int getMax() {
    if(isEmpty()) {
        cout << "Priority Queue is Empty" << endl;
        return INT_MIN;
    }
    return pq[0];
}

// Make insert Function
void insert(int element) {
    pq.push_back(element);

    int childIndex = pq.size()-1;

    while(childIndex>0) {
        int parentIndex = (childIndex-1)/2;
        if(pq[parentIndex]<pq[childIndex]) {
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[childIndex];
            pq[childIndex] = temp;
        } else {
            break;
        }
        childIndex = parentIndex;
    }
}

// Make removeMax Function
int removeMax() {

    // Condition
    if(isEmpty()) {
        cout << "Priority Queue is Empty" << endl;
        return INT_MIN;
    }

    int ans = pq[0];
    pq[0] = pq[pq.size()-1];
    pq.pop_back();

    int parentIndex = 0;
    int leftChildIndex = (2*parentIndex)+1;
    int rightChildIndex = (2*parentIndex)+2;

    while(leftChildIndex<pq.size()) {
        int maxIndex = parentIndex;
        if(pq[leftChildIndex]>pq[maxIndex]) {
            maxIndex = leftChildIndex;
        }
        if(rightChildIndex<pq.size() && pq[rightChildIndex]>pq[maxIndex]) {
            maxIndex = rightChildIndex;
        }
        if(parentIndex==maxIndex) break;

        int temp = pq[parentIndex];
        pq[parentIndex] = pq[maxIndex];
        pq[maxIndex] = temp;

        parentIndex = maxIndex;
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
    cout << p.getMax() << endl;

    while(!p.isEmpty()) {
        cout << p.removeMax() << " ";
    }
    return 0;
}