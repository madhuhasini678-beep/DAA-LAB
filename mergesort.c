#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[100];
    while(i<=mid&&j<=high){
        if(arr[i]>arr[j]){
            temp[k++]=arr[j++];
        }
        else{
            temp[k++]=arr[i++];
        }
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    k=0;
    for(i=low;i<=high;i++){
        arr[i]=temp[k++];
    }
}
void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int n;
    printf("Enter the no of array elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("array after sorting:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}