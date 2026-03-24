#include <stdio.h>
#define N 4
#define INF 9999

int cost[N][N] = {{INF,10,15,20},{10,INF,35,25},{15,35,INF,30},{20,25,30,INF}};
int visited[N] = {0};
int minCost = INF;

void tsp(int city, int count, int costSoFar) {
    if(count==N && cost[city][0]!=INF) {
        int total = costSoFar+cost[city][0];
        if(total < minCost) minCost = total;
        return;
    }
    for(int i=0;i<N;i++) {
        if(!visited[i] && cost[city][i]!=INF) {
            visited[i]=1;
            tsp(i, count+1, costSoFar+cost[city][i]);
            visited[i]=0;
        }
    }
}

int main() {
    visited[0]=1; tsp(0,1,0);
    printf("Minimum travelling cost = %d", minCost);
    return 0;
}