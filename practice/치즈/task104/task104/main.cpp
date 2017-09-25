//
//  main.cpp
//  task104
//
//  Created by 박경세 on 2017. 8. 31..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int N, M;
int map[100][100] = {0,};
int visit[100][100] = {0,};
int row_dir[4] = {1, -1, 0, 0};
int col_dir[4] = {0, 0, 1, -1};

int melt(int time){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==2){
                cnt++;
                map[i][j] = 0;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]){
                return 0;
            }
        }
    }
    printf("%d\n", time);
    printf("%d\n", cnt);
    return 1;
}

void check(int row, int col){
    for(int i=0; i<4; i++){
        if(row+row_dir[i]>=0 && row+row_dir[i]<N && col+col_dir[i]>=0 && col+col_dir[i]<M){
            if(map[row+row_dir[i]][col+col_dir[i]]==1){
                map[row+row_dir[i]][col+col_dir[i]]=2;
            }
        }
    }
    for(int i=0; i<4; i++){
        if(row+row_dir[i]>=0 && row+row_dir[i]<N && col+col_dir[i]>=0 && col+col_dir[i]<M){
            if(!map[row+row_dir[i]][col+col_dir[i]] && !visit[row+row_dir[i]][col+col_dir[i]]){
                visit[row+row_dir[i]][col+col_dir[i]] = 1;
                check(row+row_dir[i], col+col_dir[i]);
            }
        }
    }
}

void clear(){
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) visit[i][j] = 0;
}

int main(int argc, const char * argv[]) {
    int time=1;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &map[i][j]);
    while(true){
        visit[0][0] = 1;
        check(0, 0);
        clear();
        if(melt(time)){
            break;
        }
        else time++;
    }
    return 0;
}
