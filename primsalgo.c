#include <stdio.h>

#define INF 999

int main() {
    int n, a[10][10];
    int visited[10] = {0};
    int i, j, min, x, y, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);

            if (a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    visited[0] = 1; 

    for (int edge = 0; edge < n - 1; edge++) {
        min = INF;

        for (i = 0; i < n; i++) {
            if (visited[i] == 1) {
                for (j = 0; j < n; j++) {
                    if (visited[j] == 0 && a[i][j] < min) {
                        min = a[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", x, y, min);

        visited[y] = 1;
        total = total + min;
    }

    printf("Minimum cost = %d", total);

    return 0;
}
