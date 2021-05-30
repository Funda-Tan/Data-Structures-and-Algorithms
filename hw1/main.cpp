/*
* Title: Sorting and Algorithm Efficiency
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 1
* Description: Main for testing the algorithms and make performance analysis.
*/

#include <iostream>
#include "sorting.h"
using namespace std;

int main()
{
    int arr1[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int compCount = 0;
    int moveCount = 0;

    cout << "Selection Sort" << endl;
    selectionSort(arr1, 16, compCount, moveCount);
    cout << "After selection sorting: ";
    displayArray(arr1, 16);
    cout << endl;
    cout << "Number of key comparisons: " << compCount << endl;
    cout << "Number of data moves: " << moveCount << endl;
    cout << endl;

    cout << "Merge Sort" << endl;
    int arr2[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    compCount = 0;
    moveCount = 0;
    mergeSort(arr2, 16, compCount, moveCount);
    cout << "After merge sorting: ";
    displayArray(arr2, 16);
    cout << endl;
    cout << "Number of key comparisons: " << compCount << endl;
    cout << "Number of data moves: " << moveCount << endl;
    cout << endl;

    cout << "Quick Sort" << endl;
    int arr3[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    compCount = 0;
    moveCount = 0;
    quickSort(arr3, 16, compCount, moveCount);
    cout << "After quick sorting: ";
    displayArray(arr3, 16);
    cout << endl;
    cout << "Number of key comparisons: " << compCount << endl;
    cout << "Number of data moves: " << moveCount << endl;
    cout << endl;

    cout << "Radix Sort" << endl;
    int arr4[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    radixSort(arr4, 16);
    cout << "After radix sorting: ";
    displayArray(arr4, 16);
    cout << endl;

    performanceAnalysis();
    return 0;
}
