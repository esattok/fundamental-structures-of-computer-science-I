// Author: Esad Ismail Tok
// Student ID: 21801679

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;


// First Algorithm: Appends all items in arr1, then places the items in arr2 accordingly
// Time Complexity: O(N^2) -> The algorithm needs to iteratare through a nested loop including 2 for loops both having 0(N)
// time complexity so this algorithm has time complexity of O(N^2)
int* algorithm1(const int* arr1, const int* arr2, const int size) {
    
    int mergedSize = (size * 2);
    int* arr3 = new int[mergedSize];
    int currentSize = 0;
    int foundIndex;
    int value;
    bool haveFound;

    // Copy all the elements from arr1 to arr3 and keep the current size of arr3
    for (int i = 0; i < size; i++) {
        arr3[i] = arr1[i];
        currentSize++;
    }
    
    // Iterate through all the elements in arr2
    for (int i = 0; i < size; i++) {
        haveFound = false;

        // Iterate through all the current elements in arr3 and when a new element is added consider this as well
        for (int j = 0; j < currentSize; j++) {

            // If the i'th element of arr2 is less then or equal to an element of arr3 hold the index and value then exit the loop
            if (arr2[i] <= arr3[j]) {
                haveFound = true;
                foundIndex = j;
                value = arr2[i];
                break;
            }
        }

        // If the loop is done without any match it means that the element in arr2 is greater than all the elements
        // in arr3. So place this element at the end of the arr3 and increase the current size
        if (!haveFound) {   
            arr3[currentSize] = arr2[i];
            currentSize++;
        }

        // If the index is found then place the value according to found index
        else {
            // Create a size for the new element by shifting the others to the right
            for (int k = currentSize; k > foundIndex; k--) {
                arr3[k] = arr3[k - 1];
            }

            // Place the element and increase the current size and exit the loop
            arr3[foundIndex] = value;
            currentSize++;
        }
    }

    return arr3;
}


// Second Algorithm: Checks both input arrays' current items and places the smaller one into the output array
// and iterate to the next item in the choosen array and the output array
// Time Complexity: O(N) -> There is no nested loops and all the while loops include only statements 
// including O(1) complexity so the time complexity of this algorithm is O(N)
int* algorithm2(const int* arr1, const int* arr2, const int size) {
    // Keep the counters for arr1, arr2, and, arr3
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    int mergedSize = (2 * size);
    int* arr3 = new int[mergedSize];

    // Loop through untill one of the input arrays reach the end
    while ((count1 < size) && (count2 < size)) {

        // Compare both items and add the smaller one
        if (arr1[count1] < arr2[count2]) {
            arr3[count3] = arr1[count1];
            count1++;
            count3++;
        }

        // If the item was equal or greater then add it
        else {
            arr3[count3] = arr2[count2];
            count2++;
            count3++;
        }
    }

    // If there are remaining elements in the first array, add them at the and of the arr3
    while (count1 < size) {
        arr3[count3] = arr1[count1];
        count1++;
        count3++;
    }

    // If there are remaining elements in the second array, add them at the and of the arr3
    while (count2 < size) {
        arr3[count3] = arr2[count2];
        count2++;
        count3++;
    }

    return arr3;
}


// Additinonal Function
// Fills the given array with random numbers between the lower and upper bounds
void generateRandomArray(int* arr, const int size, const int lower, const int upper) {
    for (int i = 0; i < size; i++) {
        arr[i] = random() % (upper - lower + 1) + lower;
    }
}


// Additinonal Function
// Prints the given array
void showArray(const int* arr, const int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i]; 

        if (i < (size-1)) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}


// Driver function that testes and demonstrates both algorithms
// The test are done by changing the input size to 10, 100, 1000, 10000, 100000 accordingly
int main() {

    // Declaration of the input arrays
    int size = 100000; // Change the input size according to each test
    int* arr1 = new int[size];
    int* arr2 = new int[size];

    // Decleration of the output array
    int lastSize = 2 * size;
    int* arr3;
    

    // Filling and sorting the first and the second array to pass them into the algorithms
    generateRandomArray(arr1, size, 10, 500);
    sort(arr1, &arr1[size]);
    //showArray(arr1, size);

    generateRandomArray(arr2, size, 10, 500);
    sort(arr2, &arr2[size]);
    //showArray(arr2, size);
    //cout << endl;

    // // Testing the Algorithms
    // arr3 = algorithm1(arr1, arr2, size);
    // showArray(arr3, lastSize);

    // delete [] arr3;
    // arr3 = NULL;

    // arr3 = algorithm2(arr1, arr2, size);
    // showArray(arr3, lastSize);

    // delete [] arr3; 
    // arr3 = NULL;



    // -------------------------------------------------------------------------------------

    // Storing the starting time of first algorithm
    double first_duration;
    clock_t first_timer = clock();
    

    // Code block to calculate the elapsed time from the start of it and the end of it
    arr3 = algorithm1(arr1, arr2, size);

    // Claculating the elapsed time for first algorithm
    first_duration = 1000 * double(clock() - first_timer) / CLOCKS_PER_SEC;
    cout << "Execution time of Algorithm 1 = " << first_duration << " miliseconds" << endl;

    delete [] arr3;

    // -------------------------------------------------------------------------------------

    // Storing the starting time of second algorithm
    double second_duration;
    clock_t second_timer = clock();

    // Code block to calculate the elapsed time from the start of it and the end of it
    arr3 = algorithm2(arr1, arr2, size);

    // Claculating the elapsed time for second algorithm
    second_duration = 1000 * double(clock() - second_timer) / CLOCKS_PER_SEC;
    cout << "Execution time of Algorithm 2 = " << second_duration << " miliseconds" << endl << endl;

    // -------------------------------------------------------------------------------------

    // Deallocating the memory taken for arrays
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    
    return 0;
}