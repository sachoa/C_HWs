//
// Created by Stephanie Achoa on 10/5/21.
//

#ifndef C_HWS_JOSEPHUS_FUNCTIONS_H
#define C_HWS_JOSEPHUS_FUNCTIONS_H

struct Rebel_s {
    int id;
    struct Rebel_s *left;
    struct Rebel_s *right;
};
typedef struct Rebel_s Rebel_t;

int num_rebels, increment;
int josephus(int, int, int);

#endif //C_HWS_JOSEPHUS_FUNCTIONS_H
