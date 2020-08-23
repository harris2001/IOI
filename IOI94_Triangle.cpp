#include <iostream>
#include <stdio.h>

using namespace std;

int dp[100][100];

int main(){
    
    int rows;
    scanf("%d",&rows);
    int pyramid[rows][rows];
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<rows; j++){
            pyramid[i][j]=-1;
        }
    }
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<i+1; j++){
            scanf("%d",&pyramid[i][j]);
        }
    }

    dp[0][0]=pyramid[0][0];
    int maxn = 0;
    for(int i=1; i<rows; i++){
        for(int j=0; j<i+1; j++){
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1])+pyramid[i][j]);
            if(i==rows-1&&dp[i][j]>maxn){
                maxn=dp[i][j];
            }
        }
    }
    printf("%d",maxn);
    return 0;
}
