#include <stdio.h>
int main()
{
    int n, target;
    int found = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int hash[n];
    for (int i = 0; i < n; i++)
    {
        hash[i] = -1;
    }
    printf("Enter the target element: ");
    scanf("%d", &target);
    // Insert elements into hash table
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int index = ((key % n) + n) % n;
        while (hash[index] != -1)
        {
            index = (index + 1) % n;
        }
        hash[index] = key;
    }
    for (int i = 0; i < n; i++)
    {
        int search = target - arr[i];
        int index = ((search % n) + n) % n;
        while (hash[index] != -1)
        {
            if (hash[index] == search)
            {
                printf("%d + %d = %d\n",
                       search, arr[i], target);

                found = 1;
                break;
            }
            index = (index + 1) % n;
        }
    }
    if (found == 0)
    {
        printf("Not present\n");
    }
    printf("\nHash table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", hash[i]);
    }
    return 0;
}