//
//  main.cpp
//  task88
//
//  Created by 박경세 on 2017. 7. 5..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int N, M;
int current_row, current_col;
int dice[6] = {0,};
int map[20][20] = {0,};

void upper(int dir){
    int temp[6];
    for(int i=0; i<6; i++) temp[i] = dice[i];
    switch(dir){
        case 1:{
            if(current_col+1 >= M) return;
            else{
                current_col += 1;
                dice[3] = temp[0];
                dice[1] = temp[5];
                dice[0] = temp[1];
                dice[5] = temp[3];
                
                if(map[current_row][current_col]){
                    dice[5] = map[current_row][current_col];
                    map[current_row][current_col] = 0;
                }
                else{
                    map[current_row][current_col] = dice[5];
                }
            }
            break;
        }
        case 2:{
            if(current_col-1 < 0) return;
            else{
                current_col -= 1;
                dice[0] = temp[3];
                dice[5] = temp[1];
                dice[1] = temp[0];
                dice[3] = temp[5];
                if(map[current_row][current_col]){
                    dice[5] = map[current_row][current_col];
                    map[current_row][current_col] = 0;
                }
                else{
                    map[current_row][current_col] = dice[5];
                }
            }
            break;
        }
        case 4:{
            if(current_row+1 >= N) return;
            else{
                current_row += 1;
                dice[2] = temp[0];
                dice[5] = temp[2];
                dice[0] = temp[4];
                dice[4] = temp[5];
                if(map[current_row][current_col]){
                    dice[5] = map[current_row][current_col];
                    map[current_row][current_col] = 0;
                }
                else{
                    map[current_row][current_col] = dice[5];
                }
            }
            break;
        }
        case 3:{
            if(current_row-1 < 0) return;
            else{
                current_row -= 1;
                dice[0] = temp[2];
                dice[2] = temp[5];
                dice[4] = temp[0];
                dice[5] = temp[4];
                if(map[current_row][current_col]){
                    dice[5] = map[current_row][current_col];
                    map[current_row][current_col] = 0;
                }
                else{
                    map[current_row][current_col] = dice[5];
                }
            }
            break;
        }
    }
    printf("%d\n", dice[0]);
}

int main(int argc, const char * argv[]) {
    int x, y, K, spot, direction;
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &spot);
            map[i][j] = spot;
        }
    }
    current_row = x;
    current_col = y;
    for(int i=0; i<K; i++){
        scanf("%d", &direction);
        upper(direction);
    }
    return 0;
}
