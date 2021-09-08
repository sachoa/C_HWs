cmake_minimum_required(VERSION 3.20)
project(C_HWs C)

set(CMAKE_C_STANDARD 99)

#add_executable(C_HWs main.c HW1/diamond.c HW1/diamond.h HW1/minmax.c HW1/minmax.h HW1/emptyDiamond.c HW1/emptyDiamond.h
#                HW2/primes.c HW2/primes.h HW2/calendar.c HW2/calendar.h )

add_executable(C_HWs
        main.c
        HW2/primes.c
        HW2/primes.h
        HW2/calendar.c
        HW2/calendar.h
        )