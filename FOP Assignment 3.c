#include <stdio.h>

int main() {
    int n, limit, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Multiplication table of %d up to %d:\n", n, limit);

    for (i = 1; i <= limit; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}