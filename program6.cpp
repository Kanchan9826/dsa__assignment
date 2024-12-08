#include <iostream>
#include <cstring>
using namespace std;

// Function to calculate the address in row-major order for 3D array
long long int calculateRowMajorAddress(long long baseAddress, int i, int j, int k, int numRows, int numCols, int numDepth, int sizeOfElement) {
    return baseAddress + ((i * numCols * numDepth) + (j * numDepth) + k) * sizeOfElement;
}

// Function to calculate the address in column-major order for 3D array
long long int calculateColumnMajorAddress(long long baseAddress, int i, int j, int k, int numRows, int numCols, int numDepth, int sizeOfElement) {
    return baseAddress + ((k * numRows * numCols) + (j * numRows) + i) * sizeOfElement;
}

int main() {
    // Declare variables for input
    string dataType;
    int numRows, numCols, numDepth;
    string memoryArrangement;
    long long baseAddress;
    int i, j, k;

    // Input type of array (int, char, float, etc.)
    cout << "Enter the type of array (int, char, float, etc.): ";
    cin >> dataType;

    // Input size of the 3D array
    cout << "Enter the number of rows, columns, and depth of the array: ";
    cin >> numRows >> numCols >> numDepth;

    // Input memory arrangement (ROW major or COLUMN major)
    cout << "Enter memory arrangement (ROW major or COLUMN major): ";
    cin >> memoryArrangement;

    // Input base address of the 3D array
    cout << "Enter the base address of the array (as an integer): ";
    cin >> baseAddress;

    // Input indices of the element whose address needs to be computed
    cout << "Enter the row index (i), column index (j), and depth index (k) of the element: ";
    cin >> i >> j >> k;

    // Calculate size of each element based on data type
    int sizeOfElement;
    if (dataType == "int") {
        sizeOfElement = sizeof(int);
    } else if (dataType == "char") {
        sizeOfElement = sizeof(char);
    } else if (dataType == "float") {
        sizeOfElement = sizeof(float);
    } else {
        cout << "Unsupported data type!" << endl;
        return 1;
    }

    // Calculate the address based on memory arrangement
    long long int elementAddress;
    if (memoryArrangement == "ROW") {
        elementAddress = calculateRowMajorAddress(baseAddress, i, j, k, numRows, numCols, numDepth, sizeOfElement);
    } else if (memoryArrangement == "COLUMN") {
        elementAddress = calculateColumnMajorAddress(baseAddress, i, j, k, numRows, numCols, numDepth, sizeOfElement);
    } else {
        cout << "Unsupported memory arrangement!" << endl;
        return 1;
    }

    // Output the calculated address of the element
    cout << "The address of element at index (" << i << ", " << j << ", " << k << ") is: " << elementAddress << endl;

    return 0;
}

