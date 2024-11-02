#include "bst.h"

#include <stdio.h>

void create_test();

int main() {
    create_test();
}

void create_test() {
    t_btree* node1 = bstree_create_node(10);
    t_btree* node2 = bstree_create_node(20);

    if(node1 != NULL) {
        printf("%d\n", 10);
        printf("SUCCESS\n");
    } else {
        printf("%d\n", 10);
        printf("FAIL\n");
    }

    if(node2 != NULL) {
        printf("%d\n", 20);
        printf("SUCCESS\n");
    } else {
        printf("%d\n", 20);
        printf("FAIL\n");
    }
}