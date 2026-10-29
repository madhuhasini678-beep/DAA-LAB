#include<stdio.h>
void main(){
    int p[]={1,2,5,6};
    int w[]={2,3,4,5};
    int i,j,n=4;
    printf("Enter the maximum weight of knapsack: ");
    int m;
    scanf("%d",&m);
    int table[n+1][m+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0){
                table[i][j] = 0;
            }
            else if(w[i-1]<=j){
                if(p[i-1]+table[i-1][j-w[i-1]]>table[i-1][j]){
                    table[i][j] = p[i-1]+table[i-1][j-w[i-1]];
                }
                else{
                    table[i][j] = table[i-1][j];
                }
            }
            else{
                table[i][j] = table[i-1][j];
            }
        }
    }
    printf("The obtained table after applying 0/1 knapsack is:\n");
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("The maximum value that can be obtained is: %d", table[n][m]);
}