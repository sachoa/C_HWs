//
// Created by Stephanie Achoa on 10/5/21.
//
// josephus function is the public interface >> function prototype in the header file
// rebel functions are private >> not put their function prototypes in the header file.


#include <stdio.h>
#include <stdlib.h>
#include "josephus_functions.h"

struct Rebel_s {
    int id;
    struct Rebel_s *left;
    struct Rebel_s *right;
};
typedef struct Rebel_s Rebel_t;

//creates the linked list representation of the circle of rebels
static Rebel_t *create_rebels(int num_rebels) {
    if (num_rebels <= 0) {
        return NULL;
    }
    Rebel_t *head = NULL;
    Rebel_t *rebel = head;
    Rebel_t *rebel_prev = head;

    for (int i = 0; i < num_rebels; i++) {
        if (i == 0) {
            head = (Rebel_t *) malloc(sizeof(Rebel_t *));
            head->id = i + 1;
            head->right = head;
            head->left = head;
            rebel_prev = head;
        }
        rebel = (Rebel_t *) malloc(sizeof(Rebel_t));
        rebel->id = i + 1;
        rebel_prev->right = rebel;
        rebel->left = rebel_prev;
        rebel_prev = rebel;
    }
    rebel->right = head;
    head->left = rebel;
    return head;
}

//removes a rebel's entry from the linked list
static Rebel_t kill_rebel(struct Rebel_s *rebel){
    free(rebel *);
//You MUST use the C routine free to free the memory for each rebel structure in the function kill_rebel.

}

int josephus(int num_rebels, int increment) {


    //a. create the rebels data structure

    // b. until there is only one rebel left
    /// something like ->>> while (rebel-> right != rebel && rebel->left != reble) keep doing the killing

    // i. count off rebels with the next rebel being the one to the right of the current rebel
    // ii. if the rebel is the increment-th one, that rebel is killed
    //  iii. restart the count
    /// something like
           ///for (int i =0; i<incriment; i++){
           ///    rebel = rebel-> right;

           ///    killRebel = rebel -> right;
           ///    rebel->right = rebel->right->right;

           ///    do the killing of killRebel
           ///
           ///    rebel = rebel -> right;

           ///}

    //return the position of the surviving rebel.

}
