#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *node = malloc(sizeof(t_btree));

    node -> item = item;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

void bstree_insert(t_btree *root, int item, int (*cmpf) (int, int)) {
    if(root == NULL) {
        bstree_create_node(item);
    }
    
    t_btree *parent = NULL;
    t_btree *current = root;

    while(current != NULL) {
        parent = current;
        if(cmpf(item, current->item) == 1) {
            current = current -> left;
        } else {
            current = current -> right;
        }
    }

    t_btree *newNode = bstree_create_node(item);
    if(cmpf(item, parent->item) == 1) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

int cmp(int item, int item1) {
    if(item > item1) {
        return 0;
    }else {
        return 1;
    }
}

void apply(int item) {
    printf("%d ", item);
}

void bstree_apply_infix(t_btree* root, void (*applyf) (int)) {
    if(root == NULL) {
        return;
    }
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree* root, void (*applyf) (int)) {

    if(root == NULL) {
        return;
    }

    applyf(root->item);

    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);

}

void bstree_apply_postfix(t_btree* root, void (*applyf) (int)) {
    if(root == NULL) {
        return;
    }

    bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
    bstree_apply_postfix(root->left, applyf);
}