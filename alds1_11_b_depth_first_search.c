#include <stdio.h>
#define LEN 100
#define WRITE 0
#define GRAY 1
#define BLACK 2

int matrix[LEN][LEN] = { 0 };
int color[LEN] = { 0 };
int find[LEN] = { 0 };
int end[LEN] = { 0 };
int count = 0;
int n = 0;

void dfs_visit(int node) {
    count += 1;
    find[node] = count;
    color[node] = GRAY;
    for (int i = 0; i < n; i++) {
        if (matrix[node][i] == 0) {
            continue;
        }
        if (color[i] == WRITE) {
            dfs_visit(i);
        }
    }
    color[node] = BLACK;
    count += 1;
    end[node] = count; 
}

void dfs() {
    for (int i = 0; i < n; i++) {
        dfs_visit(i);
    } 

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", i + 1, find[i], end[i]);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int node, degree;
        scanf("%d %d", &node, &degree);
        for (int i = 0; i < degree; i++) {
            int v;
            scanf("%d", &v);
            matrix[node - 1][v - 1] = 1; 
        }
    }
    dfs();
    return 0;
}
