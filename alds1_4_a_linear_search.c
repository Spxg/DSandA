#include <stdio.h>

int search(int array[], int n, int key) {
    int i = 0;
    array[n] = key;
    while (array[i] != key) { 
        i += 1;
    }
    return i != n;
}

int main(int argc, char const *argv[])
{
    int n, m;
    int sum = 0;
    int array[10000 + 1];
    scanf("%d", &n);    
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    };

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int key;
        scanf("%d", &key);
        if (search(array, n, key)) {
            sum += 1;
        }
    }

    printf("%d", sum);
    return 0;
}
