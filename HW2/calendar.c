//
// Created by Stephanie Achoa on 9/7/21.
//
#include <stdio.h>
#include "calendar.h"

int calendar(){
    float choice;
    int year, month, quarter, firstDayOfYear;

    while (choice!= 5){

        char *monthS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                          "October", "November", "December"};
        char *days[] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
        int daysInMonth[] = {31,28,31,30,31,31,30,31,30,31,30,31};
                if (year/400 == 0 || year/4 == 0 && year/100!=0){
                    daysInMonth[1] = 29;
                }

        printf ("*** Welcome to Steph's Calendar Program ***");
        printf("You have the following choices:\n 1. Leap year test \n 2. Get first day of the month\n "
               "3. Get a monthly calendar\n 4. Get a quarterly calendar\n 5. Quit\n");
        printf("Please enter your choice from the above menu: \n");
        scanf("%f", &choice);

        if (choice ==1) {
            printf("Please enter the year to test:\n");
            scanf("%d", &year);
            if (year%400 == 0 || year%4 == 0 && year%100!=0){
                printf("%d is a leap year\n", year);
            } else {
                printf("%.d is NOT a leap year\n", year);
            }
        }

        else if (choice ==2){ // first day of month
            printf("Please enter the year to test:\n");
            scanf("%d", &year);
            printf("Please enter the month (as a number):\n");
            scanf("%d", &month);

            if (month >= 1 && month <=12){
                firstDayOfYear = (1 + (year+1) + (year-1) /4 - (year-1) /100 + (year-1)/400)% 7;
                printf("the first day of the year is %d \n", firstDayOfYear);

                // need to figure out( maybe loop through the year) to see when the first day of the month will be
                        // jan day + 31 days would be then feb, but then feb is weird too
 //               printf("%s\n", days[firstDayOfYear-1]);
            } else{
                printf("Invalid month number option!\n");
            }
        }

        else if (choice ==3){ // print month
            printf("Please enter the year to test:\n");
            scanf("%d", &year);

            printf("Please enter the month you wish to print (as a number):\n");
            scanf("%d", &month);

            if (month > 1 && month <=12){
                printf("works\n");
 //               printf("%s\n", monthS [month-1])                        // gets you month name

                //  use first day calculation firstDay = (1 + (year+1) + (year-1) /4 - (year-1) /100 + (year-1)/400 %7
                // somehow iterate through the days to get to the right day for the month
                // then need to do some formatting
            } else{
                printf("Invalid month number option!\n");
            }
        }

        else if (choice ==4){
            printf("Please enter the year to test:\n");
            scanf("%d", &year);

            printf("Please enter the quarter (either 1, 2, 3, or 4):\n");
            scanf("%d", &quarter);

            if (quarter==1 || quarter==2 || quarter==3 || quarter==4){
                if (quarter ==1 ){ } // January, February, and March monthS[0,1,2]
                if (quarter ==2 ){ } // April, May, and June monthS[3,4,5]
                if (quarter ==3 ){ } // July, August, and September monthS[6,7,8]
                if (quarter ==4 ){ } // October, November, and December monthS[9,10,11]

                printf("works\n");                                      //  !! NEED TO ACTUALLY DO CALCULATIONS NOW !!
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