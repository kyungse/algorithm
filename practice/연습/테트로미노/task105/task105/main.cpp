//
//  main.cpp
//  task105
//
//  Created by 박경세 on 2017. 8. 31..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max(a,b)((a) > (b) ? (a) : (b))

using namespace std;

int N, M;
int answer = 0;
int map[501][501] = {0,};
int visit[501][501] = {0,};
int row_dir[4] = {1, -1, 0, 0};
int col_dir[4] = {0, 0, 1, -1};

void dfs(int row, int col, int cnt, int sum){
    if(cnt==4){
        answer = max(answer, sum);
    }
    else{
        for(int i=0; i<4; i++){
            if(row+row_dir[i]>=0&&row+row_dir[i]<N&&col+col_dir[i]>=0&&col+col_dir[i]<M){
                if(!visit[row+row_dir[i]][col+col_dir[i]]){
                    visit[row+row_dir[i]][col+col_dir[i]] = 1;
                    dfs(row+row_dir[i], col+col_dir[i], cnt+1, sum+map[row+row_dir[i]][col+col_dir[i]]);
                    visit[row+row_dir[i]][col+col_dir[i]] = 0;
                }
            }
        }
    }
}

void cross(int row, int col){
    if(row-1>=0&&row+1<N&&col+1<M) answer = max(answer, map[row-1][col]+map[row+1][col]+map[row][col+1]+map[row][col]);
    if(row-1>=0&&row+1<N&&col-1>=0) answer = max(answer, map[row-1][col]+map[row+1][col]+map[row][col-1]+map[row][col]);
    if(col-1>=0&&col+1<M&&row+1<N) answer = max(answer, map[row+1][col]+map[row][col+1]+map[row][col-1]+map[row][col]);
    if(col-1>=0&&col+1<M&&row-1>=0) answer = max(answer, map[row-1][col]+map[row][col+1]+map[row][col-1]+map[row][col]);
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &map[i][j]);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visit[i][j] = 1;
            dfs(i, j, 1, map[i][j]);
            visit[i][j] = 0;
            cross(i, j);
            
        }
    }
    printf("%d\n", answer);
    return 0;
}
