#include <stdio.h>

int binary_search(int array[], int n, int key) {
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (array[mid] == key) {
            return 1;
        }
        if (array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    int m;
    int key;
    int sum = 0;
    int array[1000000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &key);
        if (binary_search(array, n, key)) {
            sum++;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}
