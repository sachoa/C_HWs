//
// Created by Stephanie Achoa on 11/1/21.
//

#ifndef C_HWS_PRESIDENTS_H
#define C_HWS_PRESIDENTS_H

int president_main();
struct president * getPresidentName();
struct president * yearSort(struct president *, int);
struct president * lastNameSort(struct president *, int);
struct president * firstNameSort(struct president *, int);
void printListFirstNameSort(struct president *, int);
void printListLastNameSort(struct president *, int);
void printListYearSort(struct president *, int);

#endif //C_HWS_PRESIDENTS_H
