cmake_minimum_required(VERSION 3.20)
project(C_HWs C)

set(CMAKE_C_STANDARD 99)

#add_executable(C_HWs main.c HW1/diamond.c HW1/diamond.h HW1/minmax.c HW1/minmax.h HW1/emptyDiamond.c HW1/emptyDiamond.h
#                HW2/primes.c HW2/primes.h HW2/calendar.c HW2/calendar.h HW3/hanoi.c HW3/hanoi.h HW3/jeep.c HW3/jeep.h
#                HW3/powers.c HW3/powers.h)

add_executable(C_HWs
        main.c
        HW4/int-array-stuff.c
        HW4/int-array-stuff.h
        HW4/random-stuff.c
        HW4/random-stuff.h
        HW4/sort.c
        HW4/sort.h
        HW4/sorting-routines.c
        HW4/sorting-routines.h
        )