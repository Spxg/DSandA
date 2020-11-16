#include <stdio.h>
#define MAX 10000
#define NONE -1

struct Node { 
    int parent;
    int left;
    int right;
};

struct Node Tree[MAX];

void pre_parse(int u) {
    if (u == NONE) {
        return;
    }
    printf(" %d", u);
    pre_parse(Tree[u].left);
    pre_parse(Tree[u].right);
}

void in_parse(int u) {
    if (u == NONE) {
        return;
    }
    in_parse(Tree[u].left);
    printf(" %d", u);
    in_parse(Tree[u].right);
}

void post_parse(int u) {
    if (u == NONE) {
        return;
    }
    post_parse(Tree[u].left);
    post_parse(Tree[u].right);
    printf(" %d", u);
}

int main(int argc, char const *argv[]) {
    int n = 0;
    int root;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Tree[i].parent = NONE;
    }

    for (int i = 0; i < n; i++) {
        int node = 0;
        int left, right;
        scanf("%d %d %d", &node, &left, &right);
        Tree[node].left = left;
        Tree[node].right = right;
        Tree[left].parent = node;
        Tree[right].parent = node;
    }

    for (int i = 0; i < n; i++) {
        if (Tree[i].parent == NONE) {
            root = i;
            break;
        }
    }
    printf("Preorder\n");
    pre_parse(root);
    printf("\n");
    printf("Inorder\n");
    in_parse(root);
    printf("\n");
    printf("Postorder\n");
    post_parse(root);
    printf("\n");
    return 0;
}
