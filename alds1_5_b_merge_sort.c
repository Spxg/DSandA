#include <stdio.h>
#define MAX 5000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt = 0;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }

    for (int i = 0; i < n2; i ++) {
        R[i] = A[mid + i];
    }

    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] < R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
} 

void merge_sort(int A[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, n, left, mid);
        merge_sort(A, n, mid, right);
        merge(A, left, mid, right);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int A[MAX] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    merge_sort(A, n, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
    }

    printf("\n%d", cnt);
    return 0;
}
