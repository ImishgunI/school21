#ifndef DOOR_STRUCT
#define DOOR_STRUCT

struct door {
    int id;
    int status;
};

void sort(struct door* doors);
void output(struct door* doors);
#endif