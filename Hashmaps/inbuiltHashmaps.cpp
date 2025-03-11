#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> ourMap;
    
    // Insert Method - 1
    pair<string, int> p("abc", 1);
    ourMap.insert(p);

    // Insert Method - 2
    ourMap["def"] = 2;

    // Find or Access Method - 1
    cout << ourMap["abc"] << endl;
    cout << ourMap["def"] << endl;

    // Find or Access Method - 2
    cout << ourMap.at("abc") << endl;
    cout << ourMap.at("def") << endl;

    cout << "Size: " << ourMap.size() << endl;

    // cout << ourMap.at("ghi") << endl;

    cout << ourMap["ghi"] << endl;
    cout << "Size: " << ourMap.size() << endl;
    // Square Bracket will insert default value of "ghi" as 0 and it will give output as 0.

    // Check Present or Not
    if (ourMap.count("ghi")>0) {
        cout << "ghi is Present" << endl;
    } else {
        cout << "ghi is not Present" << endl;
    }

    // Erase
    ourMap.erase("ghi");
    cout << "Size: " << ourMap.size() << endl;
    if(ourMap.count("ghi")>0) {
        cout << "ghi is Present" << endl;
    } else {
        cout << "ghi is not Present" << endl;
    }
}