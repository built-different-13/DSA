// Include Header Files
#include <iostream>
#include <queue>
using namespace std;

// Make K Largest Elements Function
vector<int> kLargestElements(int input[], int n, int k) {

    // Edge Case
    if(k>n) return {};

    // Initialize a Priority Queue
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i=0; i<k; i++) {
        pq.push(input[i]);
    }

    for (int i=k; i<n; i++) {
        if(input[i]>pq.top()) {
            pq.push(input[i]);
            pq.pop();
        }
    }

    vector<int> output;
    while(!pq.empty()) {
        output.push_back(pq.top());
        pq.pop();
    }

    return output;
}

// Print the Priority Queue
void print(vector<int>& output) {
    for (int i=0; i<output.size(); i++) {
        cout << output[i] << " ";
    }
}

// Main Function of the Program
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
    vector<int> ans = kLargestElements(arr,n,k);
    print(ans);
    return 0;
}