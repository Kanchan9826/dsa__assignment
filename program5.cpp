#include <iostream>
#include <cstring>
using namespace std;

// Function to calculate the address in row-major order
long long int calculateRowMajorAddress(long long baseAddress, int i, int j, int numRows, int numCols, int sizeOfElement) {
    return baseAddress + ((i * numCols) + j) * sizeOfElement;
}

// Function to calculate the address in column-major order
long long int calculateColumnMajorAddress(long long baseAddress, int i, int j, int numRows, int numCols, int sizeOfElement) {
    return baseAddress + ((j * numRows) + i) * sizeOfElement;
}

int main() {
    // Declare variables for input
    string dataType;
    int numRows, numCols;
    string memoryArrangement;
    long long baseAddress;
    int i, j;

    // Input type of array (int, char, float, etc.)
    cout << "Enter the type of array (int, char, float, etc.): ";
    cin >> dataType;

    // Input size of the array
    cout << "Enter the number of rows and columns of the array: ";
    cin >> numRows >> numCols;

    // Input memory arrangement (ROW major or COLUMN major)
    cout << "Enter memory arrangement (ROW major or COLUMN major): ";
    cin >> memoryArrangement;

    // Input base address of the array
    cout << "Enter the base address of the array (as an integer): ";
    cin >> baseAddress;

    // Input indices of the element whose address needs to be computed
    cout << "Enter the row index (i) and column index (j) of the element: ";
    cin >> i >> j;

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
        elementAddress = calculateRowMajorAddress(baseAddress, i, j, numRows, numCols, sizeOfElement);
    } else if (memoryArrangement == "COLUMN") {
        elementAddress = calculateColumnMajorAddress(baseAddress, i, j, numRows, numCols, sizeOfElement);
    } else {
        cout << "Unsupported memory arrangement!" << endl;
        return 1;
    }

    // Output the calculated address of the element
    cout << "The address of element at index (" << i << ", " << j << ") is: " << elementAddress << endl;

    return 0;
}

