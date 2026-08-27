#include<stdio.h>
void insert(int table[], int key, int n)
{
    int index = key%n;
    int i = 0;
    int newIndex;
     while (i < n)
    {
        newIndex = (index + i * i) % n;

        if (table[newIndex] == -1)
        {
            table[newIndex] = key;
            return;
        }
        i++;
    }
     printf("Hash table is full. Cannot insert %d\n", key);
}
void display(int table[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Index %d: %d\n", i, table[i]);
    }
}
int main()
{
    int n;
    printf("Enter no of elements:");
    scanf("%d",&n);
    int table[n];
    int key, i;
    for (i = 0; i < n; i++)
        table[i] = -1;
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(table, key,n);
    }
    printf("\nHash Table:\n");
    display(table, n);
    return 0;
}