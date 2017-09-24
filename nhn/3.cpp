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

using namespace std;

int N;
int map[10][10] = {0,};
int answer_map[10][10] = {0,};
int row_dir[4] = {-1, 0, 0, 1};
int col_dir[4] = {0, -1, 1, 0};

void check(int row, int col, int alphabet){
    if(alphabet=='0'){
        answer_map[row][col] = -1;
        return;
    }
    int load[4];
    int const_value = ((alphabet-'A')*16);
    for(int i=0; i<4; i++) load[i] = 0;
    for(int i=0; i<4; i++){
        if(row+row_dir[i]>=0&&row+row_dir[i]<N&&col+col_dir[i]>=0&&col+col_dir[i]<N){
            if(map[row+row_dir[i]][col+col_dir[i]]==alphabet){
                load[i] = 1;
            }
        }
    }
    int mul = 1;
    int value = 0;
    for(int i=0; i<4; i++){
        if(load[i]) value += mul;
        mul *= 2;
    }
    answer_map[row][col] = value + const_value;
}

int main(int argc, const char * argv[]) {
    char temp;
    scanf("%d", &N);
    scanf("%c", &temp);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%c", &temp);
            map[i][j] = (int)temp;
            scanf("%c", &temp);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            check(i, j, map[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", answer_map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
