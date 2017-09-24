//
//  main.cpp
//  task
//
//  Created by 박경세 on 2017. 9. 23..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> answer;
int map[10][10] = {0,};
int visit[10][10] = {0,};
int answer_map[10][10] = {0,};
int row_dir[4] = {1, -1, 0, 0};
int col_dir[4] = {0, 0, 1, -1};

void DFS(int row, int col, int cnt){
    for(int i=0; i<4; i++){
        if(row+row_dir[i]>=0&&row+row_dir[i]<N&&col+col_dir[i]>=0&&col+col_dir[i]<N){
            if(!visit[row+row_dir[i]][col+col_dir[i]] && map[row+row_dir[i]][col+col_dir[i]]){
                visit[row+row_dir[i]][col+col_dir[i]] = 1;
                answer_map[row+row_dir[i]][col+col_dir[i]] = cnt;
                DFS(row+row_dir[i], col+col_dir[i], cnt);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int cnt = 1;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] && !visit[i][j]){
                visit[i][j] = 1;
                answer_map[i][j] = cnt;
                DFS(i, j, cnt++);
            }
        }
    }
    
    for(int i=1; i<=cnt-1; i++){
        int count = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(answer_map[j][k]==i){
                    count++;
                }
            }
        }
        answer.push_back(count);
    }
    sort(answer.begin(), answer.end());
    printf("%d\n", cnt-1);
    if(cnt-1) for(int i=0; i<(int)answer.size(); i++) printf("%d ", answer[i]);
    return 0;
}
