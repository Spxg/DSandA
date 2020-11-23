#include <stdio.h>
#define MAX 10

int main(int argc, char const *argv[])
{
    int matrix[MAX][MAX] = { 0 };
    int n;
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
