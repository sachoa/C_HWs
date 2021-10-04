//
// Created by Stephanie Achoa on 9/20/21.
//
#include <stdio.h>
#include "sort.h"
#include "sorting-routines.h"
#include "int-array-stuff.h"

//Main program: reads in size input, prints out unsorted array, calls quicksort and prints the sorted output

int size =0;
int sort(){

    printf("Welcome, this program quick sorts your integers.\n");
    printf("How many integers would you like to sort? ");
    scanf("%d", &size);

    int * randArr = createArray(size);

    printArray(0, size-1, randArr, "Unsorted Array: ");
    quicksort(randArr, 0, size-1, 0);
    printArray(0, size-1, randArr, "Sorted Array: ");

    return 0;
}