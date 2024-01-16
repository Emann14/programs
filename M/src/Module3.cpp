//============================================================================
// Name        : mod3.cpp
// Author      : Evan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : mod3.cpp
// Author      : Evan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

int main() {
    int value1, value2, value3; // Variables to store user input

    // Prompt the user to enter three integer values
    cout << "Enter three integer values: ";
    cin >> value1 >> value2 >> value3;

    int* ptr1 = new int(value1); // Create a pointer and allocate memory for value1
    int* ptr2 = new int(value2); // Create a pointer and allocate memory for value2
    int* ptr3 = new int(value3); // Create a pointer and allocate memory for value3

    // Display the contents of the variables and pointers
    cout << "Variable 1: " << value1 << ", Pointer 1: " << *ptr1 << endl;
    cout << "Variable 2: " << value2 << ", Pointer 2: " << *ptr2 << endl;
    cout << "Variable 3: " << value3 << ", Pointer 3: " << *ptr3 << endl;

    // Deallocate the dynamically allocated memory using the delete operator
    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}
