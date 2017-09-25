//
//  main.cpp
//  task111
//
//  Created by 박경세 on 2017. 9. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max(a,b)((a) > (b) ? (a) : (b))

using namespace std;

int answer = 0;
int dp[100000][4] = {0,};
int cost[100000][4] = {0,};

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<4; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    for(int i=0; i<4; i++) dp[0][i] = cost[0][i];
    for(int i=1; i<N; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                if(j==k) continue;
                dp[i][j] = max(dp[i-1][k], dp[i][j]);
            }
            dp[i][j] += cost[i][j];
        }
    }
    for(int i=0; i<4; i++) answer = max(answer, dp[N-1][i]);
    printf("%d\n", answer);
    return 0;
}
