/*
* Title: Sorting and Algorithm Efficiency
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 1
* Description: Header file for the implementation of selection sort, merge sort, quick sort and radix sort
* for random, ascending and descending ordered arrays.
*/

#ifndef SORTING_H
#define SORTING_H
using namespace std;

void  displayArray(const int *arr, const int size);

void  createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void  createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void  createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

int  indexOfLargest(const int *arr, int size, int &compCount);
void  swap(int &x, int &y, int &moveCount);

void  selectionSort(int *arr, const int size, int &compCount, int &moveCount);

void  merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount) ;

void  mergeSort2(int *arr, int first, int last, int &compCount, int &moveCount);
void  mergeSort(int *arr, const int size, int &compCount, int &moveCount);

void  partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount) ;
void quickSort2(int *arr, int first, int last, int &compCount, int &moveCount) ;
void quickSort(int *arr, const int size, int &compCount, int &moveCount);

void  radixSort2(int theArray[], int n, int d);
void  radixSort(int *arr, const int size);
void performanceAnalysis();
#endif // SORTING_H
