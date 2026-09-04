#include<stdio.h>
int main(){
    int bucket[10][100],count[10]={0},i,j,n,k;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        int index=a[i]/10;
        bucket[index][count[index]]=a[i];
        count[index]++;
    }
    for(i=0;i<10;i++){
        for(j=0;j<count[i];j++){
           for(k=j+1;k<count[i];k++){
               if(bucket[i][j]>bucket[i][k]){
                   int temp=bucket[i][j];
                   bucket[i][j]=bucket[i][k];
                   bucket[i][k]=temp;
               }
           }
        }
    }
    int pos = 0;
    for (int i = 0; i<10; i++) {
        for (int j = 0; j < count[i]; j++) {
            a[pos++] = bucket[i][j];
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);


}