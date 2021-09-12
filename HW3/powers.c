//
// Created by Stephanie Achoa on 9/8/21.
//
#include <stdio.h>
#include "powers.h"


float base, power=0, answer = 0, naive = 0, j = 0, count=0;

int powers(){

    printf("Welcome, this program raises an number to a integer exponent.\n");

    while (base != (-1) ){
        printf("Enter a base number or -1 to quit: ");
        scanf("%f", &base);

        if (base != -1){

            printf("Enter an integer exponent: ");
            scanf("%f", &power);

            if (power<0){
                power=power*(-1);
                naive = power-1;
                count = count -1;
                printf("%.3f raised to the power of %.3f is: %.3f \n", base, power, 1/compute(base,power));
                printf("Number of calculations: %.3f (Naive method uses %.3f)\n", count, naive);
                printf(" \n");
            }else{
                naive = power-1;
                count = count -1;
                printf("%.3f raised to the power of %.3f is: %.3f \n", base, power, compute(base,power));
                printf("Number of calculations: %.3f (Naive method uses %.3f)\n", count-1, naive);
                printf(" \n");
            }

        }else{
            printf("Thanks for playing!\n");
            break;
        }
        count = 0;
    }
    return 0;
}

float compute(float base, float power){
    count++;
    if (power == 0){
        return 1;
    }
    else if ((int) power % 2 == 0){
        answer = compute(base, power/2);
        j = answer*answer;
        return j;

    }
    else {
        j = compute(base, power-1)*base;
        return j;
    }
}