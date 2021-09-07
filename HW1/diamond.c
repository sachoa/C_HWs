//
// Created by Stephanie Achoa on 9/2/21.
//

#include <stdio.h>
#include "diamond.h"

int diamond() {
    // diamond size (aka how many total rows) - odd number only
    // rows is the rows for the top and bottom half (includes the center)

    int size, rows, spaces, print, line;

    printf("Enter diamond size (must be an odd integer) \n");
    scanf("%d", &size);

    rows = (size+1)/2; //top half of the rows counting the center

    if (size > 0 && size %2 != 0){
        for (line=1; line <= rows; line++){ //line is the current line I'm "standing" on

            for (spaces = 1; spaces <= rows - line; spaces++)
                printf(" ");

            for (print = 1; print <= 2*line-1; print++)
                printf("B");
            printf("\n");
        }

        for (line= rows-1; line >= 1; line--){
            // lines sort of restart so in the case of size 7 the middle line is 4 "line spot" but the row after
            // isn't 5, its 3. I stuggled on that part but it makes sense now
            for (spaces = 1; spaces <= rows - line; spaces++)
                printf(" ");

            for (print = 1; print <= 2*line-1; print++)
                printf("B");
            printf("\n");
        }

    }
    else {
        printf("Enter a positive and odd integer \n");
    }

    return 0;
}
