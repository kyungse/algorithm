//
//  main.cpp
//  exam
//
//  Created by 박경세 on 2017. 9. 30..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int T, N;
int map[501][501] = {0,};
int dp[501][501][3] = {0,};

int solve(int row, int col, int state){
    int ret = 0;
    if(dp[row][col][state]) return dp[row][col][state];
    else{
        if(state==1){
            if(row<N-1){
                ret = max(ret, solve(row+1, col, 1));
            }
            if(col<N-1){
                ret = max(ret, solve(row, col+1, 2));
            }
        }
        else if(state==2){
            if(row<N-1){
                ret = max(ret, solve(row+1, col, 1));
            }
            if(col<N-1){
                ret = max(ret, solve(row, col+1, 2));
            }
            if(row>=1){
                ret = max(ret, solve(row-1, col, 3));
            }
        }
        else{
            if(row>=1){
                ret = max(ret, solve(row-1, col, 3));
            }
            if(col<N-1){
                ret = max(ret, solve(row, col+1, 3));
            }
        }
        if(map[row][col]) ret++;
        dp[row][col][state] = ret;
        return dp[row][col][state];
    }
}

int main(int argc, const char * argv[]) {
    char sentence;
    FILE* fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    while(T--){
        fscanf(fp, "%d", &N);
        for(int i=0; i<501; i++) for(int j=0; j<501; j++) map[i][j] = 0;
        for(int i=0; i<501; i++) for(int j=0; j<501; j++) for(int k=0; k<3; k++) dp[i][j][k] = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                fscanf(fp, " %c", &sentence);
                if(sentence == 'B') map[N-1-i][j] = 1;
            }
        }
        solve(0, 0, 1);
        int answer = 0;
        for(int i=0; i<3; i++) answer = max(answer, dp[0][0][i]);
        printf("%d\n", answer);
    }
    return 0;
}
