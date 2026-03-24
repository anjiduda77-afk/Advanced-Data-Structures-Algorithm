#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int wt[10], val[10], dp[10][10], n, W;
    printf("Enter number of items: "); scanf("%d",&n);
    printf("Enter weights:\n"); for(int i=1;i<=n;i++) scanf("%d",&wt[i]);
    printf("Enter values:\n");  for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    printf("Enter capacity: "); scanf("%d",&W);
    for(int i=0;i<=n;i++) for(int j=0;j<=W;j++) {
        if(i==0||j==0) dp[i][j]=0;
        else if(wt[i]<=j) dp[i][j]=max(val[i]+dp[i-1][j-wt[i]], dp[i-1][j]);
        else dp[i][j]=dp[i-1][j];
    }
    printf("Maximum profit = %d", dp[n][W]);
    return 0;
}