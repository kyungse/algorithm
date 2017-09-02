//
//  main.cpp
//  task33
//
//  Created by 박경세 on 2017. 1. 18..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define min(a,b)((a>b)?b:a)
#define max(a,b)((a>b)?a:b)

using namespace std;

int N;
int W[16][16] = {0,};
int dp[16][1<<17] = {0,};

int TSP(int current, int visited){
    if(visited == (1<<N)-1) return W[current][0];               // 모두 다 방문했다면 1로 표시되어있으므로 마지막 출발값으로 돌아가는 값 더해주고 종료;
    if(dp[current][visited] != 0) return dp[current][visited];  // 이미 방문한 경로라면 탈출;
    dp[current][visited] = 1000000000;          // 방문하지 않았었더라면 MAX값으로 초기화하여 최솟값셋팅위한 준비;
    for(int next=0; next<N; next++){
        if(visited&(1<<next))   continue;       // next에 해당하는 bit가 1인지 확인하는 부분;
        if(W[current][next]==0) continue;       // current와 next가 연결이 되어있지 않은지 확인하는 부분;
        dp[current][visited] = min(dp[current][visited], TSP(next, visited|(1<<next)) + W[current][next]);
    }                                           // 현재 경로를 최솟값으로 업데이트 하는지 확인하는 부분;
    return dp[current][visited];
}

int main(int argc, const char * argv[]) {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &W[i][j]);
        }
    }
    printf("%d\n", TSP(0,1));                   // 0인 이유는 사실 가장작은 값을 구하면 어떤경로든 순환경로이므로;
    return 0;                                   // 어디를 출발점으로 넣던지 상관없다;
}
