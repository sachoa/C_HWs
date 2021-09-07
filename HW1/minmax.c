//
// Created by Stephanie Achoa on 9/2/21.
//

#include <stdio.h>
#include "minmax.h"

int minmax() {

    int n, min, max;

    printf("Next number please? \n");
    scanf("%d", &n);

    max = n;
    min = n;

    while (n > 0){ //breaks on the case a negative number is inputted

        if (n > max && n > 0){
            max = n;
            printf("The maximum is %d, ", max);
        }else{
            max;
            printf("The maximum is %d, ", max);
        }

        if (n < min && n > 0){
            min = n;
            printf("The minimum is %d\n", min);
        }else{
            min;
            printf("The minimum is %d\n", min);
        }

        printf("Next number please? \n");
        scanf("%d", &n);

    }
    printf("Huh? no numbers? Next time, give me something useful.");
    return 0;

}

