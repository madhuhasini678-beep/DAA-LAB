
#include <stdio.h>

int main() {
    int n, i, j, size;
    int f[100], left[100], right[100];
    char ch[100];
    int min1, min2, parent[100];
    int code[100], top, k;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    size = n;

    printf("Enter characters:\n");
    for (i = 0; i < n; i++)
        scanf(" %c", &ch[i]);

    printf("Enter frequencies:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &f[i]);

    for (i = 0; i < 2 * n - 1; i++) {
        left[i] = right[i] = -1;
        parent[i] = -1;
    }

    while (size < 2 * n - 1) {
        min1 = -1;
        min2 = -1;

        for (i = 0; i < size; i++) {
            if (parent[i] == -1 && f[i] > 0) {
                if (min1 == -1 || f[i] < f[min1]) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 || f[i] < f[min2]) {
                    min2 = i;
                }
            }
        }

        left[size] = min1;
        right[size] = min2;
        f[size] = f[min1] + f[min2];

        parent[min1] = size;
        parent[min2] = size;
        parent[size] = -1;

        size++;
    }

    printf("\nHuffman Codes:\n");

    for (i = 0; i < n; i++) {
        top = 0;
        j = i;

        while (parent[j] != -1) {
            if (left[parent[j]] == j)
                code[top++] = 0;
            else
                code[top++] = 1;

            j = parent[j];
        }

        printf("%c: ", ch[i]);

        for (k = top - 1; k >= 0; k--)
            printf("%d", code[k]);

        printf("\n");
    }

    return 0;
}
