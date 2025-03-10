#include <iostream>
#include <queue>
using namespace std;

// K Sorted Array
void kSortedArray(int input[], int n, int k) {
    priority_queue<int> pq;
    for (int i=0; i<k; i++) {
        pq.push(input[i]);
    }

    int j=0;
    for (int i=k; i<n; i++) {
     input[j] = pq.top();
     pq.pop();
     pq.push(input[i]);
     j++;
    }

    while(!pq.empty()) {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

// Print the Array
void print(int input[], int n) {
    for (int i=0; i<n; i++) {
        cout << input[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int input[n];
    cout << "Enter the elements of the array" << endl;
    for (int i=0; i<n; i++) {
        cin >> input[i];
    }
    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;
    cout << "The K Sorted Array is printed below" << endl;
    kSortedArray(input, n, k);
    print(input,n);
    return 0;
}