#include<stdio.h>
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<j){
        while(i<=high&&arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int a=arr[j];
    arr[j]=arr[low];
    arr[low]=a;
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("elements after sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}