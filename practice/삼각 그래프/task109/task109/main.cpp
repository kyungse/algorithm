//
//  main.cpp
//  task109
//
//  Created by 박경세 on 2017. 9. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define min(a,b)((a) > (b) ? (b) : (a))

using namespace std;

int node[100000][3] = {0,};
long long dp[100000][3] = {0,};

int main(int argc, const char * argv[]) {
    int N, cnt=1;
    while(true){
        scanf("%d", &N);
        if(!N) break;
        for(int i=0; i<N; i++){
            for(int j=0; j<3; j++){
                scanf("%d", &node[i][j]);
            }
        }
        dp[0][1] = node[0][1];
        dp[0][2] = node[0][1] + node[0][2];
        for(int i=1; i<N; i++){
            for(int j=0; j<3; j++){
                if(j==0){
                    if(i==1) dp[i][j] = dp[i-1][j+1] + node[i][j];
                    else dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + node[i][j];
                }
                else if(j==1){
                    if(i==1) dp[i][j] = min(dp[i-1][j], min(dp[i-1][j+1], dp[i][j-1])) + node[i][j];
                    else dp[i][j] = min(dp[i-1][j], min(dp[i-1][j+1], min(dp[i-1][j-1], dp[i][j-1]))) + node[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + node[i][j];
                }
            }
        }
        printf("%d. %lld\n", cnt++, dp[N-1][1]);
    }
    return 0;
}
