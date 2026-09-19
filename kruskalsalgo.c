#include <stdio.h>

int parent[10];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];

    return x;
}

int main() {
    int n, e, i, j;
    int u[10], v[10], w[10];
    int total = 0, count = 0;

    printf("Vertices: ");
    scanf("%d", &n);

    printf("Edges: ");
    scanf("%d", &e);

    printf("Enter: start end cost\n");

    for (i = 0; i < e; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    // Sort edges by cost
    for (i = 0; i < e; i++) {
        for (j = i + 1; j < e; j++) {
            if (w[i] > w[j]) {
                int temp;

                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = u[i]; u[i] = u[j]; u[j] = temp;
                temp = v[i]; v[i] = v[j]; v[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        parent[i] = i;

    
    for (i = 0; i < e && count < n - 1; i++) {
        int a = find(u[i]);
        int b = find(v[i]);

        if (a != b) {
            printf("%d - %d = %d\n", u[i], v[i], w[i]);

            total = total + w[i];
            parent[b] = a;
            count++;
        }
    }

    printf("Minimum cost = %d", total);

    return 0;
}
