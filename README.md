# CS303-Assignment-1
Key feature 
  search for an integr in the arry and return its index
  modify an integer at a specifc index, with exception handeling to prevent out-of-bounds access.
  add new data to the array, with checks to ensure the maximum sixe isn't exceeded
  set an integr to 0 at specfic index, with exception handling
  display the arry from an input file A1input.txt

How to use the program
  Input file 
    Enure the input file contains a list of integrs seprated by spaces or newlines
    Modify the file path in the code to match your system's location if necessary.
  Operations preformed 
    The program reads integrs from the file and stores them in a dynamic array.
    Searches for a specific integer in the array and reports in index.
    Modifies a value at a given index, while handeling invalid index access. 
    Adds new data to the array, ensuring it does not exceed the maximum size. 
    Replaces an element with 0 at a specified index.
    Dispalys the contents of the array before and after each modfication.
    
Key functions
  searchNumber(const int* data, size_t size, int numberToFind):
  Searches for a number in the array and returns its index if found. Returns -1 if not found.
  
  modifyValue(int* data, size_t index, size_t size, int newValue, int& oldValue):
  Modifies the value at a given index and returns the old value. Throws an out_of_range     exception if the index is invalid.
  
  addData(int*& data, size_t& size, int newElement, size_t maxSize):
  Adds a new element to the array if it does not exceed the maximum allowed size. Throws an overflow_error if the array is full.
  
  modifyToZero(int* data, size_t index, size_t size):
  Modifies the value at a given index to 0. Throws an out_of_range exception if the index is invalid.
  
  displayDataAndPositions(const int* data, size_t size):
  Displays the current data elements along with their positions in the array.

Main Program Flow
File Input:
The program opens the input file, reads integers, stores them in a dynamic array, and closes the file.

Search Operation:
Searches for the integer 5 in the array and displays whether it was found and its index.

Modify Operation:
Modifies the value at index 2 to 10 and catches any exceptions if the index is out of bounds.

Add Operation:
Adds the integer 20 to the array, ensuring the array size doesn't exceed the maximum size.

Modify to Zero:
Sets the value at index 1 to 0 and catches any exceptions if the index is out of bounds.

Display Results:
Displays the contents of the array after each operation.

Exception handeling
The program utilizes C++ exception handling (try-catch) to handle errors related to invalid indices or exceeding the array size.

Constants
MAX_SIZE: The maximum size of the dynamic array, set to 100.

