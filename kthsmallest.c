#include<stdio.h>
int kthsmallest(int arr[],int n,int k){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr[k-1];
}
int main(){
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter the value of k\n");
    scanf("%d",&k);
    int element=kthsmallest(arr,n,k);
    printf("The %dth smallest element is %d\n",k,element);
}