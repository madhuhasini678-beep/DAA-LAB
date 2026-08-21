//towers of hanoi non recursive approach
#include <stdio.h>
struct Move
{
    int n;
    char source;
    char auxiliary;
    char destination;
};
int main()
{
    int n;
    struct Move stack[100];
    int top = -1;

    printf("Enter number of disks: ");
    scanf("%d", &n);
    top++;
    stack[top].n = n;
    stack[top].source = 'A';
    stack[top].auxiliary = 'B';
    stack[top].destination = 'C';

    while (top >= 0)
    {
        struct Move current = stack[top];
        top--;

        int disks = current.n;
        char source = current.source;
        char auxiliary = current.auxiliary;
        char destination = current.destination;

        if (disks == 1)
        {
            printf("Move disk 1 from %c to %c\n",
                   source, destination);
        }
        else
        {
            top++;
            stack[top].n = disks - 1;
            stack[top].source = auxiliary;
            stack[top].auxiliary = source;
            stack[top].destination = destination;
            top++;
            stack[top].n = 1;
            stack[top].source = source;
            stack[top].auxiliary = auxiliary;
            stack[top].destination = destination;
            top++;
            stack[top].n = disks - 1;
            stack[top].source = source;
            stack[top].auxiliary = destination;
            stack[top].destination = auxiliary;
        }
    }

    return 0;
}