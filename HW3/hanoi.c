//
// Created by Stephanie Achoa on 9/8/21.
//
#include <stdio.h>
#include "hanoi.h"
#include "math.h"

int pegs=0, disks=0, moves=0, hanoi3=0;
char from, dest, temp1, temp2, temp3;

int hanoi(pegs, disks){

    printf("Welcome, this program calculates the distance traveled for the Jeep in the Desert puzzle.\n");

    while (pegs != (-1) ){

        // have to do something for not allowing negative disks
        printf("Enter 4 pegs, 5 pegs, or -1 to quit: ");
        scanf("%d", &pegs);

        if (pegs != -1){

            if (pegs==4){
                printf("Enter the number of disks (zero or greater): ");
                scanf("%d", &disks);

                if (disks>0){

                hanoi4(disks, 'A', 'D', 'B', 'C');
                printf("The number of moves: %d \n", moves);
                hanoi3= pow(2, disks);
                printf("The savings over Hanoi 3 is: %d\n", hanoi3-moves);
                printf("\n");
                }else{
                    printf("Please enter a positive disk number.");
                    printf("\n");
                    printf("\n");
                }
            }
            else if (pegs==5){
                printf("Enter the number of disks (zero or greater): ");
                scanf("%d", &disks);

                if (disks>0){
                    hanoi5(disks, 'A', 'E', 'B', 'C','D');
                    printf("The number of moves: %d \n", moves);
                    hanoi3= pow(2, disks);
                    printf("The savings over Hanoi 3 is: %d\n", hanoi3-moves);
                    printf("\n");
                }else{
                    printf("Please enter a positive disk number.");
                    printf("\n");
                    printf("\n");
                }
            }
            else{
                printf("Please enter a valid pegs option.");
                printf("\n");
                printf("\n");
            }
        }else{
            printf("You have quit the program.");
            printf("\n");
        }
        moves =0;
    }
    return 0;
}

void hanoi4(int disks, char from,char dest, char temp1, char temp2){

    if (disks==0){
        return;
    }
    else if (disks==1){
        printf("Move disk from %c to %c \n",from, dest);
        moves++;
        return;
    }
    hanoi4(disks-2, from, temp1, temp2, dest);
    printf("Move disk from %c to %c \n",from, temp2);
    moves++;
    printf("Move disk from %c to %c \n", from, dest);
    moves++;
    printf("Move disk from %c to %c \n",temp2, dest);
    moves++;
    hanoi4(disks-2, temp1, dest, from, temp2);
}

void hanoi5(int disks, char from,char dest, char temp1, char temp2, char temp3){
    if (disks==0){
        return;
    }
    else if (disks==1){
        printf("Move disk from %c to %c \n",from, dest);
        moves++;
        return;
    }
   else if (disks==2){
       printf("Move disk from %c to %c \n",from, temp1);
       moves++;
       printf("Move disk from %c to %c \n",from, dest);
       moves++;
       printf("Move disk from %c to %c \n",temp1, dest);
       moves++;
       return;
   }
    hanoi5(disks-3, from, temp1, temp2, temp3, dest);
    printf("Move disk from %c to %c \n",from, temp2);
    moves++;
    printf("Move disk from %c to %c \n",from, temp3);
    moves++;
    printf("Move disk from %c to %c \n",from, dest);
    moves++;
    printf("Move disk from %c to %c \n",temp3, dest);
    moves++;
    printf("Move disk from %c to %c \n",temp2, dest);
    moves++;
    hanoi5(disks-3, temp1, dest, from, temp2, temp3);

}