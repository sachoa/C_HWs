//
// Created by Stephanie Achoa on 9/7/21.
//
#include <stdio.h>
#include "calendar.h"

int calendar(){
    float choice, year, month;

    // INPUT
    // Enter a choice from the menu (1, 2, 3, 4, or 5).
    //          else an error message is displayed and program ask again for valid choice
    //
    // Any year may be entered (even if it is a pre-calendar-adoption year) but valid month
    // numbers should be entered or else an illegal month message will be printed.

    while (choice!= 5){

        printf ("*** Welcome to Steph's Calendar Program ***");
        printf("You have the following choices:\n 1. Leap year test \n 2. Get first day of the month\n "
               "3. Get a monthly calendar\n 4. Get a quarterly calendar\n 5. Quit\n");

        printf("Please enter your choice from the above menu: \n");
        scanf("%f", &choice);

        if (choice ==1) {
            printf("Please enter the year to test:\n");
            scanf("%f", &year);
            if (year/400 == 0 || year/4 == 0 && year/100!=0){
                printf("%.0f is a leap year\n", year);
            } else {
                printf("%.0f is NOT a leap year\n", year);
            }
        }

        else if (choice ==2){
            printf("Please enter the year to test:\n");
            scanf("%f", &year);

            printf("Please enter the month (as a number):\n");
            scanf("%f", &month);

            if (month > 1 && month <=12){
                printf("works\n");                                        //  !! NEED TO ACTUALLY DO CALCULATIONS NOW !!
            } else{
                printf("Invalid month number option!\n");
            }
        }

        else if (choice ==3){
            printf("Please enter the year to test:\n");
            scanf("%f", &year);

            printf("Please enter the month you wish to print (as a number):\n");
            scanf("%f", &month);

            if (month > 1 && month <=12){
                printf("works\n");                                        //  !! NEED TO ACTUALLY DO CALCULATIONS NOW !!
            } else{
                printf("Invalid month number option!\n");
            }
        }

        else if (choice ==4){
            printf("Please enter the year to test:\n");
            scanf("%f", &year);

            printf("Please enter the quarter (either 1, 2, 3, or 4):\n");
            scanf("%f", &month);

            if (month==1 || month==2 || month==3 || month==4){
                printf("works");                                        //  !! NEED TO ACTUALLY DO CALCULATIONS NOW !!
            } else{
                printf("Invalid quarter number option!\n");
            }
        }

        else if (choice ==5){
            printf("You have quit the calendar program :( \n");
        }

        else{
            printf("This is not a valid choice. Please choose an option 1 through 5.\n");
        }

    }

    return 0;

}