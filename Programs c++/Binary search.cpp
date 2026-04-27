#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;           // found
        else if (arr[mid] < key)
            low = mid + 1;        // search right half
        else
            high = mid - 1;       // search left half
    }
    return -1; // not found
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50}; // sorted array
    int key = 30;

    int result = binarySearch(arr, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}