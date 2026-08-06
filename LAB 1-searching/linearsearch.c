#include<stdio.h>
int linearsearch(int a[],int n,int key){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==key){
			return i;
		}
	}
	return -1;
}
int main(){
	int n,key,i;
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the key value:\n");
	scanf("%d",&key);
	int position=linearsearch(a,n,key);
	if(position==-1){
		printf("Element not found");
	}
	else{
		printf(" element is found at index %d",position);
	}
	return 0;
	
}