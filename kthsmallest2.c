#include <stdio.h>

int main() {
    int n, k, min, i, j;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k value: ");
    scanf("%d", &k);

    for(int count = 1; count <= k; count++) {

        min = arr[0];

        for(i = 1; i < n; i++) {
            if(arr[i] < min)
                min = arr[i];
        }

        if(count == k) {
            printf("Kth smallest = %d\n", min);
            break;
        }

        // Remove the minimum element
        for(i = 0; i < n; i++) {
            if(arr[i] == min) {
                for(j = i; j < n - 1; j++)
                    arr[j] = arr[j + 1];

                n--;
                break;
            }
        }
    }

    return 0;
}