#include <iostream>
using namespace std;

// Function to perform Selection Sort and count comparisons and swaps
void selectionSort(int arr[], int n, int &compCount, int &swapCount) {
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            compCount++;  // Count comparison
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swapCount++;  // Count swap
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
    
    // Sorting the array using Selection Sort
    selectionSort(arr, n, compCount, swapCount);
    
    cout << "Sorted array: \n";
    printArray(arr, n);
    
    cout << "Total comparisons: " << compCount << endl;
    cout << "Total swaps: " << swapCount << endl;
    
    return 0;
}

