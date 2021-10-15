//
// Created by Stephanie Achoa on 10/5/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>
#include "josephus_main.h"
#include "josephus_functions.h"

int josephus_main(int argc, char **argv) {
    printf("Welcome, this program determines the last survivor in a game Josephus, where n people stand in a circle and \n"
           "every k-th person is eliminated until only one person survives. \n");
    printf("In the command line please enter the optional -v, number of rebels, and the increment in which rebels are killed.\n");
    printf("Enter -v if you would like to display when a person commits suicide and the rebels remaining, otherwise only\n"
           " the survivor will be displayed.\n\n");

    int c;
    while ((c = getopt(argc, argv, "v:")) != -1) {
        switch (c) {
            case 'v':
                vflag = 1;
                break;
            default:
                printf("Invalid input! Usage: josephus [-v] #rebels increment.\n");
                return -1;
        }
    }
    if (argc > 1) {
        if (isdigit(*argv[1])) {
            num_rebels = atoi(argv[1]);
            increment = atoi(argv[2]);
        } else {
            num_rebels = atoi(argv[2]);
            increment = atoi(argv[3]);
        }
    }
    josephus(num_rebels, increment, vflag);
    return 0;
}