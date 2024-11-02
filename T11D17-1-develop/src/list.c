#include "list.h"
#include "door_struct.h"

#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* root = malloc(sizeof(struct node));
    root->newdoor = door;
    root->next = NULL;
    return root;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* newNode = malloc(sizeof(struct node));
    elem->next = newNode;
    newNode->newdoor = door;
    newNode->next = NULL;
    return newNode;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while(current != NULL) {
        if(current->newdoor->id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* prev = NULL;
    struct node* current = root;

    if(current != NULL && current->newdoor == elem->newdoor) {
        struct node* temp = current;
        root = current->next;
        free(temp);
        return root;
    }

    while(current != NULL && current->newdoor != elem->newdoor) {
        prev = current;
        current = current->next;
    }

    if(current == NULL) {
        return NULL;
    }

    prev->next = current->next;
    free(current);

    return root;
}

void destroy(struct node* root) {
    if(root == NULL) {
        return;
    }
    destroy(root->next);
    free(root);
}


