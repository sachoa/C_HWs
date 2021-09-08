//
// Created by Stephanie Achoa on 9/7/21.
//

#include <stdio.h>
#include "primes.h"
#include <math.h>

int N, count, n;

int primes() {
    count = 0;

    printf("Please enter how many prime numbers you would like to see: \n");
    scanf("%d", &N);
    printf("\n");
    truncf(N);
     if (N > 0){
         //need to add in integer conversion (ignores number after the decimal)
         n = 3;
         count = 1; // because 2 is a free number
         printf("2, ");
         while(count<N){
             if(isPrime(n) == 1) {
                 count++;
                 printf("%d, ", n);
             }
             n++;
         }
         printf("The number of prime numbers is %d", count);
     }
     else {
         printf("Enter a positive integer \n");
     }
  return 0;
}

int isPrime(int n) {
    int d;
    for (d = 2; d < n; d++){
        if (n % d == 0){
            return 0; // need to fix since odd numbers a numbers arent necissarily prime if isnt divisable by
        }
    }
    return 1;
}



