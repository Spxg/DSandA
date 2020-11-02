#include <stdio.h>
#define MAX 100000
#define NONE -1

struct Node {
    int parent;
    int left;
    int right;
};

struct Node Tree[MAX];

void set_depth(int node, int next, int depth, int *d) {
    int left = Tree[next].left;
    int right = Tree[next].right;

    if (left == -1 && right == -1) {
        return;
    }

    if (left == node) {
        *d = depth + 1;
        return;
    } else if (right == node) {
        *d = depth;
        return;
    } else {
        if (left != -1) {
           set_depth(node, left, depth + 1, d);
        } 
        if (right != -1) {
           set_depth(node, right, depth, d);
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Tree[i].parent = Tree[i].left = Tree[i].right = NONE;
    }

    for (int i = 0; i < n; i++) {
        int node, nums;
        int last_node;
        scanf("%d %d", &node, &nums);

        for (int k = 0; k < nums; k++) {
            int t = 0;
            scanf("%d", &t);
            if (k == 0) {
                Tree[node].left = t;
            } else {
                Tree[last_node].right = t;
            }
            Tree[t].parent = node;
            last_node = t;
        }
    }

    for (int i = 0; i < n; i++) {
        int depth = 0;
        set_depth(i, 0, 0, &depth);
        printf("node %d: ", i);
        printf("parent = %d, ", Tree[i].parent);
        printf("depth = %d, ", depth);
        if (Tree[i].parent == NONE) {
            printf("root, ");
        } else if (Tree[i].left == NONE){
            printf("leaf, ");
        } else {
            printf("internal node, ");
        };
        printf("[");
        if (Tree[i].left != NONE) {
            printf("%d", Tree[i].left);
            for (int k = Tree[i].left; Tree[k].right != NONE; k = Tree[k].right) {
                printf(", %d", Tree[k].right);
            } 
        }
        printf("]");
        printf("\n");
    }

    return 0;
}
