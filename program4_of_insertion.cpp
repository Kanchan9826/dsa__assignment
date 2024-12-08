#include <iostream>
using namespace std;

// Function to perform Insertion Sort and count comparisons and swaps
void insertionSort(int arr[], int n, int &compCount, int &swapCount) {
    // Traverse through 1 to n-1
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0) {
            compCount++;  // Count comparison
            if (arr[j] > key) {
                swapCount++;  // Count swap
                arr[j + 1] = arr[j];
                j = j - 1;
            } else {
                break;  // No need to move further if key is in the right position
            }
        }
        arr[j + 1] = key;  // Insert the key at the correct position
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
    
    // Sorting the array using Insertion Sort
    insertionSort(arr, n, compCount, swapCount);
    
    cout << "Sorted array: \n";
    printArray(arr, n);
    
    cout << "Total comparisons: " << compCount << endl;
    cout << "Total swaps: " << swapCount << endl;
    
    return 0;
}

