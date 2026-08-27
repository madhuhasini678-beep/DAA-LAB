#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int hash[100]={0};
    int arr[n];
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++){
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
        hash[arr[i]]++;
    }
    printf("Frequency of the elements:\n");
    for(i=0;i<100;i++){
        if(hash[i]>0)
        printf("%d-%d\n",i,hash[i]);
    }
}