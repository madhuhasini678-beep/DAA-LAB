#include<stdio.h>
int binarysearch(int a[],int begi,int end,int key){
	int mid,i;
	mid=(begi+end)/2;
	while(begi<=end){
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]<key){
			end=mid-1;
		}
		else{
			begi=mid+1;
		}
	}
	return -1;
}
int main(){
	int n,key,begi,end,i;
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	begi=0;
	end=n;
	int a[n];
	printf("Enter array elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the key value:\n");
	scanf("%d",&key);
	int position=binarysearch(a,begi,end,key);
	if(position==-1){
		printf("Element not found");
	}
	else{
		printf(" element is found at index %d",position);
	}
	return 0;
}