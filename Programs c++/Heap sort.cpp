#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // recursively heapify
    }
}

// Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);     // move current root to end
        heapify(arr, i, 0);       // heapify reduced heap
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}