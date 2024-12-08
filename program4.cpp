#include <iostream>
using namespace std;

// Function to perform Bubble Sort and count comparisons and swaps
void bubbleSort(int arr[], int n, int &compCount, int &swapCount) {
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            compCount++;  // Count comparison
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swapCount++;  // Count swap
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Sample array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int compCount = 0, swapCount = 0;
    
    cout << "Unsorted array: \n";
    printArray(arr, n);
    
    // Sorting the array using Bubble Sort
    bubbleSort(arr, n, compCount, swapCount);
    
    cout << "Sorted array: \n";
    printArray(arr, n);
    
    cout << "Total comparisons: " << compCount << endl;
    cout << "Total swaps: " << swapCount << endl;
    
    return 0;
}

