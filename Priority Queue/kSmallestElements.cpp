// Include Header Files
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Make K Smallest Element Function
vector<int> kSmallestElements(int arr[], int n, int k) {

    // Edge Case
    if(k>n) {
        return {};
    }

    // Initialize a priority queue
    priority_queue<int> pq;
    for (int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    for (int i=k; i<n; i++) {
        if(arr[i]<pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Initialize a vector
    vector<int> output;
   while(!pq.empty()) {
    output.push_back(pq.top());
    pq.pop();
   }

    // Return the Vector
    return output;
}

void print(vector<int>& output) {
    for (int i=0; i<output.size(); i++) {
        cout << output[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;
    vector<int> ans = kSmallestElements(arr,n,k);
    print(ans);
    return 0;
}