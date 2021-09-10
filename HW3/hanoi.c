//
// Created by Stephanie Achoa on 9/8/21.
//
#include <stdio.h>
#include "hanoi.h"

int p=0, n=0, moves=0, savings=0;
char from, dest, temp1, temp2, temp3;

int hanoi(p, n){
    //create a while != -1 so it keeps going

    printf("Enter 4 pegs, 5 pegs, or -1 to quit: ");
    scanf("%d", &p);
    printf("Enter the number of disks (zero or greater): ");
    scanf("%d", &n);

    printf("The number of moves: %d", moves);
    printf("The savings over Hanoi 3 is: %d", savings);


    // The savings over Hanoi 3 is (compare moves to total 3-peg moves of (To compute 2^n -1, you may use the fact
    // that (1<<n) in C is 2^n).

    if (p==4){
        hanoi4(n, "A", "B", "C", "D");

    }
    else if (p==5){
        //call hanoi 5
    }
    else if {p==-1}{
        printf("You have quit the program.");
    }
    else{
        printf("Please enter a valid pegs option.");
    }


    return 0;
}

int hanoi4(n, from, dest , temp1, temp2){
    // moving n disks can be viewed in terms of moving n-1 disk
    if (n==1){
        printf("Move disk from %c to %c",from, dest);
    }
    moves++;
    hanoi4(n-1, from, temp1, temp2, dest)// move n-1 disk from 1 (from) to 2 (temp1), using 3(temp2) and 4(dest) as temp area
    printf("Move disk from %c to %c",from, temp1;
    hanoi4(n-1, temp1, temp2, dest, from); // move n-1 disk from 2 to 3, using 1 and 4 as temp area
    printf("Move disk from %c to %c", temp1, temp2;
    hanoi4(n-1, temp2, dest, from, temp1); // move n-1 disk from 3 to 4, using 1 and 2 as temp area
    printf("Move disk from %c to %c", temp2, dest;


}


int hanoi5(d, from, dest , temp1, temp2, temp3);


}