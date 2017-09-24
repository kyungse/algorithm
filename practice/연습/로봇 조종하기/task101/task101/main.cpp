//
//  main.cpp
//  task101
//
//  Created by 박경세 on 2017. 8. 26..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int N, M;
int dp[1000][1000] = {0,};
int value[1000][1000] = {0,};
int temp[1000][1000][2] = {0,};

int main(int argc, const char * argv[]) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &value[i][j]);
        }
    }
    dp[0][0] = value[0][0];
    for(int i=1; i<M; i++) dp[0][i] = dp[0][i-1] + value[0][i];
    for(int i=1; i<N; i++){
        temp[i][0][0] = dp[i-1][0] + value[i][0];
        for(int j=1; j<M; j++){
            temp[i][j][0] = max(dp[i-1][j], temp[i][j-1][0]) + value[i][j];
        }
        temp[i][M-1][1] = dp[i-1][M-1] + value[i][M-1];
        for(int j=M-2; j>=0; j--){
            temp[i][j][1] = max(dp[i-1][j], temp[i][j+1][1]) + value[i][j];
        }
        for(int j=0; j<M; j++){
            dp[i][j] = max(temp[i][j][0], temp[i][j][1]);
        }
    }
    printf("%d\n", dp[N-1][M-1]);
    return 0;
}
