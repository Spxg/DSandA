#include <stdio.h>

int A[50], n;

int solve(int i, int m) {
    if (m == 0) {
        return 1;
    }
    if (i >= n) {
        return 0;
    }

    int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    return res;
}

int main(int argc, char const *argv[])
{
    int m;
    int q;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &m);
        if (solve(0, m)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
