//
// Created by Stephanie Achoa on 9/7/21.
//

#include <stdio.h>
#include "primes.h"

int primes() {

    int N, count, n, div;

    //Also, as soon as the test finds that a number is divisible by another number, the test terminates
    //since it is then known that the number cannot be prime.

    printf("Please enter how many prime numbers you would like to see: \n");
    scanf("%d", &N);

     if (N > 0){
         // first need to add in integer conversion (ignores number after the decimal)

         while(count<=N){
             for (n=2; n < 20; n++){
                 for (div = 2; div <= n/2; div++){
                     if (n % div == 0){
                        break;    // need to fix since a number isnt prime just bc it isnt divisable by 2
                     }else{
                         count++; // count needs to be placed else where and need to print number
                         break;
                     }
                 }
             }
         }

         printf("2\n");
         printf("the count is %d", count);
         // print array of prime numbers
     }

     else {
         printf("Enter a positive integer \n");
     }

  return 0;
}