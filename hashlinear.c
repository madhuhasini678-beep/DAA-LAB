#include<stdio.h>
void insert(int table[],int n,int key){
    int index=key%n;
    while(table[index]!=-1){
        index=(index+1)%n;
    }
    table[index]=key;
}
void display(int table[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("INDEX %d: %d\n",i,table[i]);
    }
}
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n],table[n],i,key;
    for(i=0;i<n;i++){
        table[i]=-1;
    }
    for(i=0;i<n;i++){
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
        key=arr[i];
        insert(table,n,key);
    }
    printf("Hash table:");
    display(table,n);
}