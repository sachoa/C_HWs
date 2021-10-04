//
// Created by Stephanie Achoa on 9/20/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "random-stuff.h"

//Random index generator

int random1(int lower, int upper ){
       int randNum = (rand() %(upper - lower + 1)) + lower;
        return randNum;
}

