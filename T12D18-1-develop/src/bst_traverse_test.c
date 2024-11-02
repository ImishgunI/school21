#include <stdio.h>

#include "bst.h"

int main() {
    int item1 = 10;
    t_btree* node = bstree_create_node(item1);
    int item2 = 5;
    int item3 = 20;
    int item4 = 12;
    int item5 = 6;
    bstree_insert(node, item2, cmp);
    bstree_insert(node, item3, cmp);
    bstree_insert(node, item4, cmp);
    bstree_insert(node, item5, cmp);

    bstree_apply_prefix(node, apply);
    printf("\n");
    bstree_apply_infix(node, apply);
    printf("\n");
    bstree_apply_postfix(node, apply);
}