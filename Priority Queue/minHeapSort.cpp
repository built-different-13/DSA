#include <iostream>
using namespace std;

void inplaceHeapSort(int input[], int n) {

    // Build the Heap in input array
     for (int i=1; i<n; i++) {
        int childIndex=i;

        while(childIndex>0) {
            int parentIndex = (childIndex-1)/2;
            if(input[parentIndex]>input[childIndex]) {
                int temp = input[parentIndex];
                input[parentIndex] = input[childIndex];
                input[childIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
     }
     
     // Remove Elements
     int size = n;

     while(size>1) {
     int temp = input[0];
     input[0] = input[size-1];
     input[size-1] = temp;

     size--;

     // Down Heapify
     int parentIndex = 0;
     int leftChildIndex = (2*parentIndex)+1;
     int rightChildIndex = (2*parentIndex)+2;

     while(leftChildIndex<size) {
        int minIndex = parentIndex;
        if(input[leftChildIndex]<input[minIndex]) {
            minIndex = leftChildIndex;
        }
        if(rightChildIndex<size && input[rightChildIndex]<input[minIndex]){
            minIndex = rightChildIndex;
        }
        if(minIndex==parentIndex) break;

        int temp = input[parentIndex];
        input[parentIndex] = input[minIndex];
        input[minIndex] = temp;

        parentIndex = minIndex;
        leftChildIndex = (2*parentIndex)+1;
        rightChildIndex = (2*parentIndex)+2;
     }
}
}

// Print the Sorted Array
void print(int input[], int size) {
    for (int i=0; i<size; i++) {
        cout << input[i] << " ";
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
cout << "The Sorted array is printed below" << endl;
inplaceHeapSort(arr,n);
print(arr,n);
return 0;
}