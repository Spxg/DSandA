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

    if (left == NONE && right == NONE) {
        return;
    }

    if (left == node) {
        *d = depth + 1;
        return;
    } else if (right == node) {
        *d = depth + 1;
        return;
    } else {
        if (left != -1) {
            set_depth(node, left, depth + 1, d);
        }
        if (right != -1) {
            set_depth(node, right, depth + 1, d);
        }
    }
}

void set_height(int node, int height, int *h) {
    int left = Tree[node].left;
    int right = Tree[node].right;

    if (left == NONE && right == NONE) {
        if (*h < height) {
            *h = height;
        }
        return;
    }

    if (left != -1) {
        set_height(left, height + 1, h);
    }
    
    if (right != -1) {
        set_height(right, height + 1, h);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Tree[i].parent = Tree[i].left = Tree[i].right = NONE;
    }

    for (int i = 0; i < n; i++) {
        int node = 0;
        int l, r;
        scanf("%d", &node);
        scanf("%d %d", &l, &r);
        Tree[node].left = l;
        Tree[node].right = r;
        Tree[l].parent = node;
        Tree[r].parent = node;
    }

    for (int i = 0; i < n; i++) {
        printf("node %d: ", i);
        printf("parent = %d, ", Tree[i].parent);

        int sibling = NONE;
        if (Tree[i].parent != -1) {
            int p = Tree[i].parent;
            if (Tree[p].left != i) {
                sibling = Tree[p].left;
            }
            if (Tree[p].right != i) {
                sibling = Tree[p].right;
            }
        }
        printf("sibling = %d, ", sibling);

        int degree = 0;
        if (Tree[i].left != NONE) {
            degree += 1;
        }
        if (Tree[i].right != NONE) {
            degree += 1;
        }

        printf("degree = %d, ", degree);

        int depth = 0;
        set_depth(i, 0, 0, &depth);
        printf("depth = %d, ", depth);

        int hight = 0;
        set_height(i, 0, &hight);
        printf("height = %d, ", hight);

        if (Tree[i].parent == NONE) {
            printf("root\n");
        } else if (Tree[i].left == NONE){
            printf("leaf\n");
        } else {
            printf("internal node\n");
        };
    }

    return 0;
}
