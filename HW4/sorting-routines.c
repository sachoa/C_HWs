//
// Created by Stephanie Achoa on 9/20/21.
//
#include <stdio.h>
#include "sorting-routines.h"
#include "random-stuff.h"

//Sorting file: where function quicksort contains operations for quicksort and insertion sort.
//Auxiliary functions: partition and swap

int * quicksort(int *arr, int left, int right, int depth){
    int size = right - left +1;
    if (left < right){
       if(size < 8) {
           insertionSort(arr, left, right);
       } else{
            int part = partition(arr, left, right);
            quicksort(arr, left, part-1, ++depth);
            quicksort(arr, part+1, right, ++depth);
        }
    }
    return arr;
}

int partition(int *arr, int left, int right){

   int pivotIndex = random1(left, right);
   swap(&arr[pivotIndex], &arr[right]); //array-right is now the random pivot value
   int i = left;
   for (int j=left; j<right; j++){
       if (arr[j] < arr[right]){
           swap(&arr[j], &arr[i]);
           i++;
       }
   }
   swap(&arr[i], &arr[right]); //moves pivot back to the correct place swapping with a value that should be on the right
   return i; //returns index of the pivot
}

void swap (int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int * insertionSort(int *arr, int left, int right){
    int i=0, j=0, x=0;
    for (i=left; i<=right; i++){
        x=arr[i];
        j=i-1;
        while(j>=0 && arr[j] > x){
            arr[j+1]= arr[j];
            j=j- 1;
        }
        arr[j+1]=x;
    }
}