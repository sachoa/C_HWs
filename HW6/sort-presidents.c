//
// Created by Stephanie Achoa on 11/1/21.
//

#include "sort-presidents.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

/*
 * Input of the list is either TAB or SPACE between fields
 * Input: First Last Year
 *
 * Sorting options: 1) Last name, 2) First name, 3) Year elected
 * Sorting output 1: Last, First, Year
 * Sorting output 2: First, Last, Year
 * Sorting output 1: Year, First, Last
 */

struct president {
    char firstName[30];
    char lastName[30];
    int yearElected;
};
typedef struct president President;
int numOfPresidents = 46;

int president_main(int argc, char **argv) {
    printf("This program contains a list of all the US presidents with their first name, last name, and year elected.\n"
           "There are 3 options to sort the presidents: either by first name, last name, or year elected.\n");
    printf("Enter -l to sort alphabetically by last name.\nEnter -f to sort alphabetically by first name.\n"
           "Enter -y to sort by year elected from earliest to latest.\n\n");

    int c, lFlag, fFlag, yFlag;
    while ((c = getopt(argc, argv, "lf y :")) != -1) {
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
                printf("Invalid input! Usage: sort-presidents - l or -f or -y \n");
                return -1;
        }
    }

    struct president *presidentDirectory = getPresidentName();
    if (lFlag == 1) {
        printListLastNameSort(lastNameSort(presidentDirectory, 46), 46);
    }
    else if (yFlag == 1) {
        printListYearSort(yearSort(presidentDirectory, 46), 46);
    }else if (fFlag == 1) {
        printListFirstNameSort(firstNameSort(presidentDirectory, 46), 46);
    }
    return 0;
}
struct president *getPresidentName() {
    FILE *fptr;
    fptr = fopen("/Users/stephanieachoa/Documents/git/C_HWs/HW6/list_of_presidents.txt", "r");
    President *presidentDir = malloc(sizeof(President) * numOfPresidents);

    if (fptr == NULL) {
        printf(stderr, "Failed to open file.");
        exit(1);
    } else {
        int index = 0;
        char buffer[200];

        while (fgets(buffer, 200, fptr) != NULL) {
            char *token = strtok(buffer, " ");

            //extract first name
            if (token != NULL) {
                strcpy(presidentDir[index].firstName, token);
            }

            //extract last name
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(presidentDir[index].lastName, token);
            }

            //extract year elected
            token = strtok(NULL, " ");
            if (token != NULL) {
                presidentDir[index].yearElected = atoi(token);
            }
            index++;
        }

    }
    fclose(fptr);

    printf("Unsorted list of presidents: \n");
    for (int i = 0; i < numOfPresidents; i++) {
        printf("%s ", presidentDir[i].firstName);
        printf("%s ", presidentDir[i].lastName);
        printf("%d\n", presidentDir[i].yearElected);
    }
    printf("\n\n");
    return presidentDir;
}

struct president *yearSort(struct president presidentDir[46], int numOfPresidents) {
    int i, j;
    President temp;

    for (i = 1; i < numOfPresidents - 1; i++) {
        for (j = 0; j < (numOfPresidents - i); j++) {
            if (presidentDir[j].yearElected > presidentDir[j + 1].yearElected) {
                temp = presidentDir[j];
                presidentDir[j] = presidentDir[j + 1];
                presidentDir[j + 1] = temp;
            }
        }
    }
    return presidentDir;
}

struct president *lastNameSort(struct president presidentDir[46], int numOfPresidents) {
    int i, j;
    President temp;

    for (i = 1; i < numOfPresidents - 1; i++) {
        for (j = 0; j < (numOfPresidents - i); j++) {
            if (strcmp(presidentDir[j].lastName, presidentDir[j + 1].lastName) > 0) {
                temp = presidentDir[j];
                presidentDir[j] = presidentDir[j + 1];
                presidentDir[j + 1] = temp;
            }
        }
    }
    return presidentDir;
}

struct president *firstNameSort(struct president presidentDir[46], int numOfPresidents) {
    int i, j;
    President temp;

    for (i = 1; i < numOfPresidents - 1; i++) {
        for (j = 0; j < (numOfPresidents - i); j++) {
            if (strcmp(presidentDir[j].firstName, presidentDir[j + 1].firstName) > 0) {
                temp = presidentDir[j];
                presidentDir[j] = presidentDir[j + 1];
                presidentDir[j + 1] = temp;
            }
        }
    }
    return presidentDir;
}

void printListYearSort(struct president presidentDir[46], int numOfPresidents){
    printf("Sorted list of presidents by year elected: \n");
    for (int k = 0; k < numOfPresidents; k++) {
        printf("%d ", presidentDir[k].yearElected);
        printf("%s ", presidentDir[k].firstName);
        printf("%s\n ", presidentDir[k].lastName);
    }
}
void printListFirstNameSort(struct president presidentDir[46], int numOfPresidents){
    printf("Sorted list of presidents by first name: \n");
    for (int k = 0; k < numOfPresidents; k++) {
        printf("%s ", presidentDir[k].firstName);
        printf("%s ", presidentDir[k].lastName);
        printf("%d\n ", presidentDir[k].yearElected);
    }
}
void printListLastNameSort(struct president presidentDir[46], int numOfPresidents){
    printf("Sorted list of presidents by last name: \n");
    for (int k = 0; k < numOfPresidents; k++) {
        printf("%s ", presidentDir[k].lastName);
        printf("%s ", presidentDir[k].firstName);
        printf("%d\n", presidentDir[k].yearElected);
    }
}