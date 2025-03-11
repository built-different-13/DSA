// Include Header Files
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Make Maximum Frequency Function
char maxFrequency(string s) {

    int arr[256];

    for (int i=0; i<256; i++) {
        arr[i] = 0;
    }

    for (int i=0; i<s.size(); i++) {
        arr[s[i]]++;
    }

    int max=0;
    char maxFreq = '\0';
    for (int i=0; i<256; i++) {
        if(arr[i]>max) {
            max = arr[i];
            maxFreq = char(i);
        }
    }

    return maxFreq;
}

// Main Function of the Program
int main() {
    string s;
    cout << "Enter the string" << endl;
    cin >> s;
    cout << "The Highest Frequency of the character in the given string is" << " ";
    char ans = maxFrequency(s);
    cout << ans << endl;
    return 0;
}