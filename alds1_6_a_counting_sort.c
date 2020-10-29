#include <stdio.h>
#define MAX 1000

int main(int argc, char const *argv[])
{
    int array[MAX] = { 0 };
    int count[MAX] = { 0 };
    int result[MAX] = { 0 };
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        count[array[i]] += 1;
    }

    for (int i = 1; i < n; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int index = array[i];
        result[count[index]] = array[i];
        count[index] -= 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i != 1) { printf(" "); }
        printf("%d", result[i]);
    }

    printf("\n");

    return 0;
}
