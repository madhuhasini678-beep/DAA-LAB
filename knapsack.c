#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

void sort(struct Item item[], int n) {
    int i, j;
    struct Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
}

int main() {
    struct Item item[100];
    int n, capacity, i;
    float maxProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter profit and weight:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    sort(item, n);

    for (i = 0; i < n; i++) {
        if (capacity >= item[i].weight) {
            capacity -= item[i].weight;
            maxProfit += item[i].profit;
        } else {
            maxProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}