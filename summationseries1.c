#include<stdio.h>
#include<math.h>
int summation(int a,int r,int n){
    
    return (a*(pow(r,n)-1)/(r-1)); 
}
int main(){
    int a,r,n;
    a=1;
    printf("Enter the value of r and no of terms\n");
    scanf("%d%d",&r,&n);
    int sum=summation(a,r,n);
    printf("sum=%d",sum);
}