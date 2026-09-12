#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int crosssumarr(int arr[],int low,int mid,int high){
    int leftsum=-999999;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>leftsum){
            leftsum=sum;
        }
    }
    int rightsum=-999999;
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(sum>rightsum){
            rightsum=sum;
        }
    }
    return leftsum+rightsum;
}
int maxsubarr(int arr[],int low,int high){
    if(low==high){
        return arr[low];
    }
    int mid=(low+high)/2;
    int leftsum=maxsubarr(arr,low,mid);
    int rightsum=maxsubarr(arr,mid+1,high);
    int crosssum=crosssumarr(arr,low,mid,high);
    return max(max(leftsum,rightsum),crosssum);
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
int sum=maxsubarr(arr,0,n-1);
printf("The maximum subarray sum: %d",sum);

}