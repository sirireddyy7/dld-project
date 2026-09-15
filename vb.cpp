#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30};

// Method 1: index-based
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

// Method 2: range-based (cleaner)
    for (int x : v) {
        x=x*2;
        cout << x << " ";
    }

// Method 3: range-based with reference (avoids copying, lets you modify)
    // for (int &x : v) {
    //     x = x * 2; // modifies original vector
    // }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}