#include <stdio.h>

int main() {
    int n, x, i;
    int sum = 0, term = 1;

    printf("Enter x and n: ");
    scanf("%d %d", &x, &n);

    for(i = 0; i <= n; i++) {
        sum += term;
        term *= x;
    }

    printf("Sum = %d", sum);

    return 0;
}