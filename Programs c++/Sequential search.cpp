#include <iostream>
#include <vector>
using namespace std;

int sequentialSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i; // element found, return index
        }
    }
    return -1; // element not found
}

int main() {
    vector<int> arr = {10, 25, 30, 45, 50};
    int key = 30;

    int result = sequentialSearch(arr, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}