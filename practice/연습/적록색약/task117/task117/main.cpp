//
//  main.cpp
//  task117
//
//  Created by 박경세 on 2017. 9. 2..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int N;
int answer1 = 0;
int answer2 = 0;
char map[100][100];
int visit[100][100] = {0,};
int row_dir[4] = {1, -1, 0, 0};
int col_dir[4] = {0, 0, 1, -1};

void alpha(int row, int col, char alphabet){
    for(int i=0; i<4; i++){
        if(row+row_dir[i]>=0&&row+row_dir[i]<N&&col+col_dir[i]>=0&&col+col_dir[i]<N){
            if(!visit[row+row_dir[i]][col+col_dir[i]]){
                if(map[row+row_dir[i]][col+col_dir[i]] == alphabet){
                    visit[row+row_dir[i]][col+col_dir[i]] = 1;
                    alpha(row+row_dir[i], col+col_dir[i], alphabet);
                }
            }
        }
    }
}

void redgreen(int row, int col){
    for(int i=0; i<4; i++){
        if(row+row_dir[i]>=0&&row+row_dir[i]<N&&col+col_dir[i]>=0&&col+col_dir[i]<N){
            if(!visit[row+row_dir[i]][col+col_dir[i]]){
                if(map[row+row_dir[i]][col+col_dir[i]]=='R' || map[row+row_dir[i]][col+col_dir[i]] =='G'){
                    visit[row+row_dir[i]][col+col_dir[i]] = 1;
                    redgreen(row+row_dir[i], col+col_dir[i]);
                }
            }
        }
    }
}

void not_redgreen(int row, int col){
    for(int i=0; i<4; i++){
        if(row+row_dir[i]>=0&&row+row_dir[i]<N&&col+col_dir[i]>=0&&col+col_dir[i]<N){
            if(!visit[row+row_dir[i]][col+col_dir[i]]){
                if(map[row+row_dir[i]][col+col_dir[i]]=='B'){
                    visit[row+row_dir[i]][col+col_dir[i]] = 2;
                    not_redgreen(row+row_dir[i], col+col_dir[i]);
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%s", map[i]);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visit[i][j]){
                answer2++;
                visit[i][j] = 1;
                if(map[i][j] == 'R' || map[i][j] == 'G') redgreen(i, j);
                else not_redgreen(i, j);
                
            }
        }
    }
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) visit[i][j] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visit[i][j]){
                answer1++;
                visit[i][j] = 1;
                alpha(i, j, map[i][j]);
            }
        }
    }
    printf("%d %d\n", answer1, answer2);
    return 0;
}
