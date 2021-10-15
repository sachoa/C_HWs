//
// Created by Stephanie Achoa on 10/5/21.

#include <stdio.h>
#include <stdlib.h>
#include "josephus_functions.h"

static Rebel_t *create_rebels(int num_rebels) {
    if (num_rebels <= 0) {
        return NULL;
    }
    Rebel_t *head = NULL;
    Rebel_t *rebel = head;
    Rebel_t *tail = head;

    for (int i = 0; i < num_rebels; i++) {
        if (i == 0) {
            head = (Rebel_t *) malloc(sizeof(Rebel_t));
            head->id = i + 1;
            head->right = head;
            head->left = head;
            tail = head;
        } else {
            rebel = (Rebel_t *) malloc(sizeof(Rebel_t));
            rebel->id = i + 1;
            rebel->left = tail;
            rebel->right = head;
            tail->right = rebel;
            tail = rebel;
        }
    }
    head->left = tail;
    return head;
}

void display(Rebel_t *head) {
    Rebel_t *rebel = head;
    do {
        printf("%d-> ", rebel->id);
        rebel = rebel->right;
    } while (rebel != head);
    printf("\b\b\b\n"); //deletes last arrow
}

static Rebel_t kill_rebel(Rebel_t *rebel, int increment, int vflag) {
    int counter = 1;
    while (rebel->right != rebel) {
        Rebel_t *nextRebel = rebel->right;
        if (counter % increment == 0) {
            rebel->left->right = rebel->right; //1.right = 2.right aka (2.left.right = 2.right)
            rebel->right->left = rebel->left; //3.left=2.left aka (2.right.left = 2.left)
            if (vflag == 1) { printf("Rebel %i commits suicide!\n", rebel->id); }
            free(rebel);
            counter++;
            rebel = nextRebel;
            if (vflag == 1) {
                printf("Surviving rebels: ");
                display(rebel);
            }
        } else {
            counter++;
            rebel = nextRebel;
        }
    }
    return *rebel;
}

int josephus(int num_rebels, int increment, int vflag) {
    if (num_rebels <= 0) {
        printf("Number of rebels must be greater than 0!\n");
    } else if (increment < 0) {
        printf("The increment must be greater than 0!\n");
    } else if (increment == 0) {
        printf("Everyone survives!\n");
    } else {
        Rebel_t *head = NULL;
        head = create_rebels(num_rebels);
        display(head);
        return printf("Rebel %d is the last survivor!", kill_rebel(head, increment, vflag).id);
    }
}


