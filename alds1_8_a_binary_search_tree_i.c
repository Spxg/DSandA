#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TNode {
    int key;
    struct TNode *parent;
    struct TNode *left;
    struct TNode *right;
};

typedef struct TNode TNode;

TNode *root;

void insert(int key) {
    TNode *y = NULL;
    TNode *x = root;
    
    TNode *z = (TNode *)malloc(sizeof(TNode));
    z->key = key;
    z->left = NULL;
    z->right = NULL;

    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left; 
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NULL) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

void inorder(TNode *node) {
    if (node == NULL) {
        return;
    }

    inorder(node->left);
    printf(" %d", node->key);
    inorder(node->right);
}

void preorder(TNode *node) {
    if (node == NULL) {
        return;
    }

    printf(" %d", node->key);
    preorder(node->left);
    preorder(node->right);
}
int main(int argc, char const *argv[]) {
    int n;
    int is_full;
    scanf("%d", &n);
    char command[10];

    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int key;
            scanf("%d", &key);
            insert(key);
        } else if (strcmp(command, "print") == 0) {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }

    return 0;
}
