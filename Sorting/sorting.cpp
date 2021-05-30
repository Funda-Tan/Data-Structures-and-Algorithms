/*
* Title: Sorting and Algorithm Efficiency
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 1
* Description: Selection sort, merge sort, quick sort and radix sort are
* implemented for random, ascending and descending ordered arrays.
*/

#include "sorting.h"
#include <iostream>
using namespace std;
#include <math.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
void displayArray(const int *arr, const int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    int item;
    for(int i = 0; i < size; i++){
        item = rand() ;
        arr1[i] = item;
        arr2[i] = item;
        arr3[i] = item;
        arr4[i] = item;
    }
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    int item = 0;
    for(int i = 0; i < size; i++){
        item = i + 1;
        arr1[i] = item;
        arr2[i] = item;
        arr3[i] = item;
        arr4[i] = item;
    }
}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    int item = 0;
    for(int i = 0; i < size; i++){
        item = size - i;
        arr1[i] = item;
        arr2[i] = item;
        arr3[i] = item;
        arr4[i] = item;
    }
}

int indexOfLargest(const int *arr, int size, int &compCount){
    int indexSoFar = 0;
    for(int currentIndex = 1; currentIndex < size; currentIndex++){
        compCount++;
        if(arr[currentIndex] > arr[indexSoFar])
            indexSoFar = currentIndex;
    }
    return indexSoFar;

}

void swap(int &x, int &y, int &moveCount){
    int temp = x;
    x = y;
    y = temp;
    moveCount = moveCount + 3;
}

void selectionSort(int *arr, const int size, int &compCount, int &moveCount){
    moveCount = 0;
    compCount = 0;
    for(int last = size - 1; last >= 1; last--){
        int largest = indexOfLargest(arr, last + 1, compCount);
        swap(arr[largest], arr[last], moveCount);
    }
}

void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount) {
   int tempArray[30000]; 	// temporary array
   int first1 = first; 	// beginning of first subarray
   int last1 = mid; 		// end of first subarray
   int first2 = mid + 1;	// beginning of second subarray
   int last2 = last;		// end of second subarray
   int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
      compCount++;
      if (theArray[first1] < theArray[first2]) {
         tempArray[index] = theArray[first1];
         moveCount++;
         ++first1;
      }
      else {
          tempArray[index] = theArray[first2];
          moveCount++;
          ++first2;
      }
   }
   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index){
      moveCount++;
      tempArray[index] = theArray[first1];
   }

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index){
      moveCount++;
      tempArray[index] = theArray[first2];
   }

   // copy the result back into the original array
   for (index = first; index <= last; ++index){
      moveCount++;
      theArray[index] = tempArray[index];
   }

}  // end merge


void mergeSort2(int *arr, int first, int last, int &compCount, int &moveCount) {

    if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergeSort2(arr, first, mid, compCount, moveCount);

      mergeSort2(arr, mid+1, last, compCount, moveCount);

      // merge the two halves
      merge(arr, first, mid, last, compCount, moveCount);
   }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    moveCount = 0;
    compCount = 0;
    mergeSort2(arr, 0, size - 1, compCount, moveCount);
}

void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

   // place pivot in theArray[first]
   int pivot = theArray[first]; // copy pivot
   moveCount++;
          // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      compCount++;
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1], moveCount);
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1], moveCount);
   pivotIndex = lastS1;
}


void quickSort2(int *arr, int first, int last, int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

   int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(arr, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quickSort2(arr, first, pivotIndex-1, compCount, moveCount);
      quickSort2(arr, pivotIndex+1, last, compCount, moveCount);
   }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    moveCount = 0;
    compCount = 0;
    quickSort2(arr, 0, size - 1, compCount, moveCount);
}

void radixSort2(int theArray[], int n, int d){
    int k;
    int a;
    int **groups = new int*[10];
    for(int i = 0; i < 10; ++i) {
            groups[i] = new int[n];
    }
    // sort n d-digit integers in the array theArray
	for (int j=d; j >= 1; j--) {
        //Initialize 10 groups to empty
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < n; j++){
                groups[i][n] = 0;
            }
        }

	     //Initialize a counter for each group to 0
        int ary[10] = {0,0,0,0,0,0,0,0,0,0};

        for (int i=0; i <= n-1; i++) {
            k = (theArray[i] / (int)pow(10, d-j)) % 10;
            groups[k][n-1 - ary[k]] = theArray[i];
            ary[k] = ary[k] + 1;
        }


        int a = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < ary[i]; j++){
                theArray[a] = groups[i][n-j-1];
                a++;
            }
        }
	}

	for(int i = 0; i < 10; i++)
        delete[] groups[i];
    delete[] groups;
}

void radixSort(int *arr, const int size){
    int maxItem = 0;
    int d;
    for(int i = 0; i < size; i++){
        if(maxItem < arr[i])
            maxItem = arr[i];
    }

    int i = 0;
    while(maxItem != 0){
        maxItem = maxItem/10;
        i++;
    }
    radixSort2(arr, size, i);
}

static double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks = (double)clock1 - (double)clock2;
    double diffms = (diffticks) / ((double)CLOCKS_PER_SEC/1000);
    return diffms;
}

void performanceAnalysis(){
    int k = 0;
    double selectionTime[7] = {0};
    double mergeTime[7] = {0};
    double quickTime[7] = {0};
    double radixTime[7] = {0};

    int selectionMove[7] = {0};
    int mergeMove[7] = {0};
    int quickMove[7] = {0};
    int radixMove[7] = {0};

    int selectionComp[7] = {0};
    int mergeComp[7] = {0};
    int quickComp[7] = {1};
    int radixComp[7] = {0};

    int compCount = 0;
    int moveCount = 0;

    int* arr1;
    int* arr2;
    int* arr3;
    int* arr4;
    int* arr5;
    clock_t t1;
    clock_t t2;
    clock_t t3;
    clock_t t4;

    for(int j = 0; j < 3; j++){
        if(j == 0){
            cout << endl;
            cout << "EXPERIMENT IN RANDOM ORDERED ARRAY" << endl;
            cout << "Wait 10 seconds..." << endl;
        }

        else if(j == 1){
            cout << endl;
            cout << "EXPERIMENT IN ASCENDING ARRAY" << endl;
            cout << "Wait 10 seconds..." << endl;
        }

        else if(j == 2){
            cout << endl;
            cout << "EXPERIMENT IN DESCENDING ARRAY" << endl;
            cout << "Wait 10 seconds..." << endl;
        }

        k = 0;
        for(int i = 6000; i <= 30000; i = i + 4000){
            arr1 = new int[i];
            arr2 = new int[i];
            arr3 = new int[i];
            arr4 = new int[i];

            if(j == 0)
                createRandomArrays(arr1, arr2, arr3, arr4, i);

            else if(j == 1)
                createAscendingArrays(arr1, arr2, arr3, arr4, i);

            else if(j == 2)
                createDescendingArrays(arr1, arr2, arr3, arr4, i);

            arr5 = new int[i];
            for(int j = 0; j < i; j++){
                arr5[j] = arr1[j];
            }

        int counter = 0;
        do{    ////////SELECTION
            t1 = clock();
            selectionSort(arr1, i, compCount, moveCount);
            counter++;
            t3 = clock();
            for(int j = 0; j < i; j++)
                arr1[j] = arr5[j];
            t4 = clock();
            selectionMove[k] = moveCount;
            selectionComp[k] = compCount;
            t2 = clock();
            selectionTime[k] = selectionTime[k] + (diffclock(t2, t1) - diffclock(t4, t3));
        }while(selectionTime[k] < 50.0);
        selectionTime[k] = selectionTime[k] / counter;

        counter = 0;
        do{     ///////MERGE
            t1 = clock();
            mergeSort(arr2, i, compCount, moveCount);
            counter++;
            t3 = clock();
            for(int j = 0; j < i; j++)
                arr2[j] = arr5[j];
            t4 = clock();
            mergeMove[k] = moveCount;
            mergeComp[k] = compCount;
            t2 = clock();
            mergeTime[k] = mergeTime[k] + (diffclock(t2, t1) - diffclock(t4, t3));
        }while(mergeTime[k] < 50.0);
        mergeTime[k] = mergeTime[k] / counter;

        counter = 0;
        do{    ////////QUICK
            t1 = clock();
            quickSort(arr3, i, compCount, moveCount);
            counter++;
            t3 = clock();
            for(int j = 0; j < i; j++){
                arr3[j] = arr5[j];
            }
            t4 = clock();
            quickMove[k] = moveCount;
            quickComp[k] = compCount;
            t2 = clock();
            quickTime[k] = quickTime[k] + (diffclock(t2, t1) - diffclock(t4, t3));
        }while(quickTime[k] < 50.0);
        quickTime[k] = quickTime[k] / counter;

        counter = 0;
        do{    ////////RADIX
            t1 = clock();
            radixSort(arr4, i);
            counter++;
            t3 = clock();
            for(int j = 0; j < i; j++)
                arr4[i] = arr5[i];
            t4 = clock();
            t2 = clock();
            radixTime[k] = radixTime[k] + (diffclock(t2, t1) - diffclock(t4, t3));
        }while(radixTime[k] < 50.0);
        radixTime[k] = radixTime[k] / counter;

        k++;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;
        }

        cout << "-------------------------------------------------" << endl;
        cout << "Analysis of Selection Sort" << endl;

        cout << setw(16) << left << "Array Size";
        cout << setw(16) << left << "Elapsed time" <<  setw(16) <<  left << "compCount" << setw(16) <<  left << "moveCount"  << endl;

        for(int i = 0; i < 7; i++){

            cout << setw(16) << left << 6000 + 4000 * i;
            cout << setw(16) << left << selectionTime[i] <<  setw(16) <<  left << selectionComp[i] << setw(16) <<  left << selectionMove[i]  << endl;
        }

        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Analysis of Merge Sort" << endl;

        cout << setw(16) << left << "Array Size";
        cout << setw(16) << left << "Elapsed time" <<  setw(16) <<  left << "compCount" << setw(16) <<  left << "moveCount"  << endl;

        for(int i = 0; i < 7; i++){
            cout << setw(16) << left << 6000 + 4000 * i;
            cout << setw(16) << left << mergeTime[i] <<  setw(16) <<  left << mergeComp[i] << setw(16) <<  left << mergeMove[i]  << endl;
        }

        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Analysis of Quick Sort" << endl;

        cout << setw(16) << left << "Array Size";
        cout << setw(16) << left << "Elapsed time" <<  setw(16) <<  left << "compCount" << setw(16) <<  left << "moveCount"  << endl;
        for(int i = 0; i < 7; i++){
            cout << setw(16) << left << 6000 + 4000 * i;
            cout << setw(16) << left << quickTime[i] <<  setw(16) <<  left << quickComp[i] << setw(16) <<  left << quickMove[i]  << endl;
        }

        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Analysis of Radix Sort" << endl;

        cout << setw(16) << left << "Array Size";
        cout << setw(16) << left << "Elapsed time" << endl;

        for(int i = 0; i < 7; i++){
            cout << setw(16) << left << 6000 + 4000 * i;
            cout << setw(16) << left << radixTime[i] << endl;
        }
    }
}
