//
// Created by Stephanie Achoa on 9/8/21.
//
#include <stdio.h>
#include "powers.h"

int base=0, power=0, answer = 0, naive = 0, j = 0, calc=0;

int powers(){

    printf("Welcome, this program raises an number to a integer exponent.\n");

    while (base != 1 ){
        printf("Enter a base number or -1 to quit: ");
        scanf("%d", &base);

        if (base!=-1){
            printf("Enter an integer exponent: ");
            scanf("%d", &power);

            naive = power-1;
          //  printf("I used %d multiplications (naive method uses %d)", multi, naive);
            printf("%d raised to the power %d is: %d \n", base, power, compute(base,power));
        }else{
            printf("Thanks for playing!\n");
        }
    }

    return 0;
}
int compute(base, power){
    if (power == 0){
        return 1;
    }
    else if (power % 2 == 0){
        answer = compute(base, power/2);
        j = answer*answer;

        return j;
    }
    else {
        j = compute(base, power-1)*base;
        return j ;
    }


}


//So by repeatedly applying these rules we can compute x^n for a given n.
//For example, we can compute x^22 with 6 multiplications (instead of 21) as
//follows: 22 is even, so if we compute x^11 we can then compute x^22 with
//a single extra multiplication. How about computing x^11? By applying the
//second and then the first rule we see that if  we had x^5 then we
//just need multiply the result by itself and then multiply this by x. This
//is two multiplications. And so on.
//
//Your task is to write a recursive function  power(x, n) that takes a double x
//and a  positive  integer n and returns x^n. The function should be
//recursive based on the above rules together with the appropriate terminating
//case (n=1). Your program should also calculate the number of multiplications
//performed. Your output should look something like this (feel free to make it
//look "nicer").

//1. If you want, you can write a program to compute x^n for any integer n.
//     In this case notice that x^0 is 1 if x is not equal to 0, while 0^0
//     is undefined.
//  2. How much better is this method over the naive one? Here's a "back of
//     the envelope" calculation: Essentially, we reduce the computation
//     of x to some power to computing x to half that power; then we obtain
//     the result with one or two multiplications (that's the even/odd case).
//     We compute x to half of that power using the same method, each time
//     needing one or two multiplications. Starting from n, how many "halvings"
//     does it take to reach one? Well, that's log_2 n (this is the logarithm
//     to the base 2). So, roughly, it takes anywhere between log_2 n and
//     2*log_2 n multiplications. As n grows, this is  a lot faster
//     than the naive method  which requires n-1 multiplications.
//  3. Consider computing x to a 100-digit number. Using our method this would
//     need a few hundred multiplications. Using the naive method, this would
//     need about 10^100 multiplications (do you see why?) Well, even if you
//     consider the fastest possible computer, to do 10^100 multiplications
//     you need a lot more time than the age of the universe since the bing
//     bang! This is not an extreme example. A lot of  cryptographic and
//     computer security protocols involve operations among numbers that are
//     hundreds of digits long.