#include <stdio.h>
#define LEN 100000

int partition(int A[], int p, int r) {
    int x = A[r];
    int band = p;
    for (int i = p; i <= r; i++) {
        if (A[i] <= x) {
            if (band != i) {
                int temp = A[band];
                A[band] = A[i];
                A[i] = temp;
            }
            band += 1;
        }
    }
    return band - 1;
}

int main(int argc, char const *argv[])
{
    int n;
    int A[LEN];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int band = partition(A, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i != 0 ) {
            printf(" ");
        }
        if (i == band) {
            printf("[%d]", A[i]);
            continue;
        }
        printf("%d", A[i]);
    }

    printf("\n");
    return 0;
}
