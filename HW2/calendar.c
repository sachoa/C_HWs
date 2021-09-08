//
// Created by Stephanie Achoa on 9/7/21.
//
#include <stdio.h>
#include "calendar.h"

//global variables
char *monthS[] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September",
                  "October", "November", "December"};
char *days[] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
int daysInMonth[] = {0, 31,28,31,30,31,31,30,31,30,31,30,31};
float choice;
int year, month, quarter, firstDayOfYear=0, firstDayOfMonth=0, i=0, day, weekDay=0;

int calendar(){


    while (choice!= 5){

        printf ("\n*** Welcome to Steph's Calendar Program ***\n");
        printf("You have the following choices:\n 1. Leap year test \n 2. Get first day of the month\n "
               "3. Get a monthly calendar\n 4. Get a quarterly calendar\n 5. Quit\n");
        printf("Please enter your choice from the above menu: \n");
        scanf("%f", &choice);

        if (choice==1) {
            printf("Please enter the year to test:\n");
            scanf("%d", &year);
            if (year%400 == 0 || (year%4 == 0 && year%100!=0)){
                printf("%d is a leap year\n", year);
            } else {
                printf("%.d is NOT a leap year\n", year);
            }
        }

        else if (choice==2){ // first day of month
            printf("Please enter the year to test:\n");
            scanf("%d", &year);
            printf("Please enter the month (as a number):\n");
            scanf("%d", &month);

            if (month >= 1 && month <=12){
                firstDayOfYear = (1 + (year-1) + (year-1) /4 - (year-1) /100 + (year-1)/400)% 7;
                if (year%400 == 0 || (year%4 == 0 && year%100!=0)){
                    daysInMonth[2] = 29;
                    i=0;
                    firstDayOfMonth = firstDayOfYear;
                    do {
                        firstDayOfMonth = daysInMonth[i] + firstDayOfMonth;
                        i++;
                    } while (i<month);

                    firstDayOfMonth = firstDayOfMonth % 7;
                    printf("%s the first day of the month\n", days[firstDayOfMonth]);
                } else {
                    i=0;
                    firstDayOfMonth = firstDayOfYear;
                    do {
                        firstDayOfMonth = daysInMonth[i] + firstDayOfMonth;
                        i++;
                    } while (i<month);

                    firstDayOfMonth = firstDayOfMonth % 7;
                    printf("%s the first day of the month\n", days[firstDayOfMonth]);
                }
            } else{
                printf("Invalid month number option!\n");
            }
        }

        else if (choice ==3){ // print month
            printf("Please enter the year to test:\n");
            scanf("%d", &year);

            printf("Please enter the month you wish to print (as a number):\n");
            scanf("%d", &month);

            if (month >= 1 && month <=12){
                firstDayOfYear = (1 + (year-1) + (year-1) /4 - (year-1) /100 + (year-1)/400)% 7;
                if (year%400 == 0 || (year%4 == 0 && year%100!=0)){
                    daysInMonth[2] = 29;
                    printCalendar(month, year, firstDayOfMonth);
                } else {
                    printCalendar(month, year, firstDayOfMonth);
                }
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
                if (quarter==1){
                    firstDayOfYear = (1 + (year-1) + (year-1) /4 - (year-1) /100 + (year-1)/400)% 7;
                    if (year%400 == 0 || (year%4 == 0 && year%100!=0)){
                        daysInMonth[2] = 29;
                        for (month=1; month<=3; month++){
                            printCalendar(month, year, firstDayOfMonth);
                        }

                    } else {
                        for (month=1; month<=3; month++){
                            printCalendar(month, year, firstDayOfMonth);
                        }
                    }
                    printf("\n");
                }
                else if (quarter ==2 ){
                    firstDayOfYear = (1 + (year-1) + (year-1) /4 - (year-1) /100 + (year-1)/400)% 7;
                    if (year%400 == 0 || (year%4 == 0 && year%100!=0)){
                        daysInMonth[2] = 29;
                        for (month=4; month<=6; month++){
                            printCalendar(month, year, firstDayOfMonth);
                        }

                    } else {
                        for (month=4; month<=6; month++){
                            printCalendar(month, year, firstDayOfMonth);
                        }
                    }
                    printf("\n");
                }
                else if (quarter ==3 ){
                    firstDayOfYear = (1 + (year-1) + (year-1) /4 - (year-1) /100 + (year-1)/400)% 7;
                    if (year%400 == 0 || (year%4 == 0 && year%100!=0)){
                        daysInMonth[2] = 29;
                        for (month=7; month<=9; month++){
                            printCalendar(month, year, firstDayOfMonth);
                        }

                    } else {
                        for (month=7; month<=9; month++){
                            printCalendar(month, year, firstDayOfMonth);
                        }
                    }
                    printf("\n");
                }
                else if (quarter ==4 ){
                    firstDayOfYear = (1 + (year-1) + (year-1) /4 - (year-1) /100 + (year-1)/400)% 7;
                    if (year%400 == 0 || (year%4 == 0 && year%100!=0)){
                        daysInMonth[2] = 29;
                        for (month=10; month<=12; month++){
                            printCalendar(month, year, firstDayOfMonth);
                        }

                    } else {
                        for (month=10; month<=12; month++){
                            printCalendar(month, year, firstDayOfMonth);
                        }
                    }
                    printf("\n");
                }
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

int printCalendar(int month, int year, int firstDayOfYear){
    i=0;
    firstDayOfMonth = firstDayOfYear;
    do {
        firstDayOfMonth = daysInMonth[i] + firstDayOfMonth;
        i++;
    } while (i<month);
    firstDayOfMonth = firstDayOfMonth % 7;

    printf("\n\n    %s %d    ", monthS [month], year);
    printf("\nSu Mo Tu We Th Fr Sa\n");

    for(weekDay=0; weekDay<firstDayOfMonth; weekDay++){
        printf("   ");
    }
    for(day=1; day<=daysInMonth[month]; day++){
        printf("%2d ", day);
        weekDay++;
        if (weekDay>6){
            printf("\n");
            weekDay=0;
        }
    }
    return 0;
}

