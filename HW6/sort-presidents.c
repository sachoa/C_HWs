//
// Created by Stephanie Achoa on 11/1/21.
//

#include "sort-presidents.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/*
 * Input of the list is either TAB or SPACE between fields -- Tab 9 and Space 32
 * Input: First Last Year
 *
 * Sorting options: 1) Last name, 2) First name, 3) Year elected
 * Sorting output 1: Last, First, Year
 * Sorting output 2: First, Last, Year
 * Sorting output 1: Year, First, Last
 *
 * Deal with erroneous inputs
 *
 * Structure
 *    ask for user input
 *    struct
 *    get presidents name
 *    sort according to option
 *          first name sort func
 *          last name sort func
 *          year sort func
 *          probably some print/display function
 */


struct president{
    char *firstName;
    char *lastName;
    int yearElected; // need to convert string using atoi when pulling values
};
typedef struct president President;

void getPresidentName()
{
    char firstName[30], lastName[30];
    int yearElected [4];
    FILE *fptr;
    fptr = fopen( "list_of_presidents.txt",  "r" );

    if (fptr == NULL){
        printf(stderr, "Failed to open file.");
        exit(1);
    }

    while(!feof(fptr)) {
       President *pres = (President *) malloc(sizeof(President));
       fscanf(fptr,"%s %s %d ", pres->firstName, pres->lastName, pres->yearElected); // this only takes care of spaces not tabs


    char c;
    while((c = fgetc(fptr)) != EOF){
        President *pres = (President *) malloc(sizeof(President));
        if(c == ' ' || c == '\n' || c == '\t'){
            //send temp array to the struct
        }
        else{
           // keep adding to array
        }
    }

    char *firstName, *lastName;

    firstName = (char*) malloc(30);
    lastName = (char*) malloc(30);
    scanf("%s %s", firstName, lastName);

    fclose(fptr);
}

/*
 * Connecting file to program
 * Use a C library
 * either get C (use a temmp array of 30 characters and once a space, tab, or enter is hit then you add that temp array into the struct)
 */



int president_main(int argc, char **argv) {
    printf("This program contains a list of all the US presidents with their first name, last name, and year elected.\n"
           "You as the user has 3 options to sort the presidents: either by first name, last name, or year elected.\n");
    printf("Enter -l to sort alphabetically by last name.\n Enter -f to sort alphabetically by first name.\n"
           "Enter -y to sort by year elected from earliest to latest.\n");

    int c, lFlag, fFlag, yFlag;
    while ((c = getopt(argc, argv, "lfy:")) != -1) {
        switch (c) {
            case 'l': //last name sort
                lFlag = 1;
                break;

            case 'f': //first name sort
                fFlag = 1;
                break;

            case 'y': //year sort
                yFlag = 1;
                break;

            default:
                printf("Invalid input! Usage: josephus [-v] #rebels increment.\n");
                return -1;
        }
    }
    return 0;
}