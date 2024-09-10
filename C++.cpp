#include <iostream>
#include <fstream>
#include <stdexcept>  // Required for exception handling

using namespace std;

// Function to check if an integer exists in the array and return its index
int searchNumber(const int* data, size_t size, int numberToFind) {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == numberToFind) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to modify the value of an integer at a specific index with exception handling
void modifyValue(int* data, size_t index, size_t size, int newValue, int& oldValue) {
    if (index >= size) {
        throw out_of_range("Index out of bounds!");  // Throw exception if index is invalid
    }
    oldValue = data[index];  // Store the old value
    data[index] = newValue;  // Update the array with the new value
}

// Function to add a new integer to the end of the array with exception handling
void addData(int*& data, size_t& size, int newElement, size_t maxSize) {
    if (size >= maxSize) {
        throw overflow_error("Array is full, cannot add new element!");  // Throw exception if array is full
    }
    data[size++] = newElement;  // Add the new element to the array
}

// Function to remove an integer or replace it with 0 at a specific index
void modifyToZero(int* data, size_t index, size_t size) {
    if (index >= size) {
        throw out_of_range("Index out of bounds!");  // Throw exception if index is invalid
    }
    data[index] = 0;  // Replace the value at the specified index with 0
}

// Function to display the number of data elements and their positions
void displayDataAndPositions(const int* data, size_t size) {
    cout << "Number of data elements: " << size << endl;
    for (size_t i = 0; i < size; ++i) {
        cout << "Position " << i << ": " << data[i] << endl;
    }
}

int main() {
    const size_t MAX_SIZE = 100;  // Define the maximum size of the array
    size_t size = 0;  // Initial size of the array
    int* data = new int[MAX_SIZE];  // Dynamically allocate an array
    int oldValue;

    // Fixed string assignment for file path
    string A1input = R "(C://Users//Nazrawit//Downloads//Programming//A1input.txt)";  // Name of the input file

    // Open and read the file
    ifstream file(A1input);  // Open the file
    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        delete[] data;
        return 1;  // Exit if the file cannot be opened
    }

    // Reading integers from the file and storing them in the array
    int value;
    while (file >> value && size < MAX_SIZE) {
        data[size++] = value;
    }

    file.close();  // Close the file after reading

    // Display the data stored in the array
    cout << "Initial data in the array:" << endl;
    displayDataAndPositions(data, size);

    // Example 1: Check if a value exists in the array
    int numberToFind = 5;  // Example number to search for
    int index = searchNumber(data, size, numberToFind);
    if (index != -1) {
        cout << "Number " << numberToFind << " found at position " << index << "." << endl;
    } else {
        cout << "Number " << numberToFind << " not found in the array." << endl;
    }

    // Example 2: Modify a value at a specific index with exception handling
    size_t modificationIndex = 2;  // Example index
    int newValue = 10;  // New value to assign
    try {
        modifyValue(data, modificationIndex, size, newValue, oldValue);
        cout << "Old value at position " << modificationIndex << ": " << oldValue << ", new value: " << newValue << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Display the data after modification
    cout << "Data after modification:" << endl;
    displayDataAndPositions(data, size);

    // Example 3: Add a new value to the array with exception handling
    int newElement = 20;  // New element to add
    try {
        addData(data, size, newElement, MAX_SIZE);
        cout << "Added new element " << newElement << " to the array." << endl;
    } catch (const overflow_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Display the data after adding the new element
    cout << "Data after adding a new element:" << endl;
    displayDataAndPositions(data, size);

    // Example 4: Modify an element to 0 at a specific index with exception handling
    size_t zeroIndex = 1;  // Example index
    try {
        modifyToZero(data, zeroIndex, size);
        cout << "Modified the element at position " << zeroIndex << " to 0." << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Display the data after modification
    cout << "Data after modifying an element to 0:" << endl;
    displayDataAndPositions(data, size);

    delete[] data;  // Free the dynamically allocated memory
    return 0;  // Indicate successful execution
}