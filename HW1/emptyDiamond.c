//
// Created by Stephanie Achoa on 9/2/21.
//

#include <stdio.h>
#include "emptyDiamond.h"



// this does not work i just copied the code from diamond

int emptyDiamond () {

    int n, size, rows, spaces, print, line;

    printf("Enter diamond size (must be an odd integer) \n");
    scanf("%d", &size);

    rows = (size+1)/2; //top half of the rows counting the center


   if (size > 0 && size %2 != 0){
       for (line=1; line <= rows; line++){ //line is the current line I'm "standing" o
           for (spaces = 1; spaces <= rows - line; spaces++)
               printf(" ");
           for (print = 1; print <= 2*line-1; print++){
               if (print==1 || print==(2*line-1)){
                   printf("B");
               } else{
                   printf(" ");
               }
           }
           printf("\n");
       }

        for (line= rows-1; line >= 1; line--){
            for (spaces = 1; spaces <= rows - line; spaces++)
                printf(" ");

            for (print = 1; print <= 2*line-1; print++)
                if (print==1 || print==(2*line-1)){
                    printf("B");
                } else{
                    printf(" ");
                }
            printf("\n");
        }

    }
    else {
        printf("Enter a positive and odd integer \n");
    }

    return 0;
}
