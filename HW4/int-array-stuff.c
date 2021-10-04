//
// Created by Stephanie Achoa on 9/20/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "int-array-stuff.h"

//General procedures for manipulating integer arrays: dynamically creating an array, reading in the
// array elements, and printing the array

int * createArray(size){
   int *userArray;
   userArray = (int*)malloc(sizeof(int)*size);

   for(int i=0;i<size;i++){
       printf("Enter the values of the array as an integer: ");
       scanf("%d", &userArray[i]);
   }

   return userArray;
}

void printArray(int left, int right, int *array, char * label){

    printf("\n%s", label);
    for(int i=left;i<=right;i++){
        printf("%i ",array[i]);
    }
    printf("\n");
}