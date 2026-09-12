#include<stdio.h>
struct Result{
    int min;
    int max;
};
struct Result MinMax(int arr[],int low,int high){
    struct Result r,left,right;
    if(low==high){
        r.min=arr[low];
        r.max=arr[high];
        return r;
    }
    if(high==low+1){
        if(arr[low]>arr[high]){
            r.min=arr[high];
            r.max=arr[low];
        }
        else{
            r.min=arr[low];
            r.max=arr[high];
        }
        return r;
    
    }
    int mid=(low+high)/2;
    left=MinMax(arr,low,mid);
    right=MinMax(arr,mid+1,high);
    r.max=(left.max>right.max)?left.max:right.max;
    r.min=(left.min<right.min)?left.min:right.min;
    return r;
}
int main(){
    int n,i;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct Result r;
    r=MinMax(arr,0,n-1);
    printf("minimum element= %d\n",r.min);
    printf("Maximum element= %d\n", r.max);
}