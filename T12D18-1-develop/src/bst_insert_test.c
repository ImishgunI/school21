#include "bst.h"

#include <stdio.h>

void insert_test();

int main() {
    insert_test();
}

void insert_test() {
    int item = 10;
    t_btree *node = bstree_create_node(item);
    int item2 = 20;
    bstree_insert(node, item2, cmp);
    int item3 = 5;
    bstree_insert(node, item3, cmp);

    if(node->left->item == item3) {
        printf("%d\n", item3);
        printf("SUCCESS\n");
    } else {
        printf("%d\n", item3);
        printf("FAIL\n");
    }

    if(node->right->item == item2) {
        printf("%d\n", item2);
        printf("SUCCESS\n");
    } else {
        printf("%d\n", item2);
        printf("FAIL\n");
    }

}