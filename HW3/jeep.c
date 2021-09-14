//
// Created by Stephanie Achoa on 9/8/21.
//

#include <stdio.h>
#include "jeep.h"

float numOfCans=0, distancePerCan=0, r = 0, gallonsPerCan= 0, totalDistance=0;

// r is rate of gallons/100miles

int jeep(){

    printf("Welcome, this program calculates the distance traveled for the Jeep in the Desert puzzle.\n");

    while (numOfCans != (-1) ){
        printf("Enter the number of cans: ");
        scanf("%f", &numOfCans);

        if (numOfCans != -1){

            if (numOfCans<0){
                printf("The number of cans must be zero or greater. Please try again.\n");
                printf("\n");
            }
            else if (numOfCans==0){
                numOfCans = 0; // set the negative number to 0, so you can't go anywhere
                printf("The total distance traveled is: 0 \n");
                printf("\n");
            }else{
                printf("Enter the number of gallons per can:");
                scanf("%f", &gallonsPerCan);

                printf("Enter the jeep's fuel consumption rate (r gallons per 100 miles):");
                scanf("%f", &r);

                distancePerCan = gallonsPerCan/(r/100);

                printf("The total distance traveled is: %.2f miles \n", ((trip(numOfCans))*distancePerCan));
                printf("\n");
            }

        }else{
            printf("Thanks for playing!\n");
            break;
        }
    }
    return 0;
}

float trip (float numOfCans){
    if (numOfCans <= 0){
            return 0;
        }
    else if (numOfCans == 1){
        totalDistance = 1;
        return totalDistance;
    }
    else{
        totalDistance = trip(numOfCans-1)+(1/((2*numOfCans)-3));
        return totalDistance;
    }

}