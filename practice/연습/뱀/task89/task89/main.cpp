//
//  main.cpp
//  task89
//
//  Created by 박경세 on 2017. 7. 9..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
int forward_dir;                                    // north 0, east 1, south 2, west 3;
int map[101][101] = {0,};
int direction[10001] = {0,};
queue<pair<int, int> > snake;

int main(int argc, const char * argv[]) {
    int row, col, second, time=0;
    char dir;
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        scanf("%d %d", &row, &col);
        map[row][col] = 1;
    }
    scanf("%d", &L);
    for(int i=0; i<L; i++){
        scanf("%d %c", &second, &dir);
        if(dir=='D')      direction[second] = 1;
        else if(dir=='L') direction[second] = 2;
    }
    forward_dir = 1;
    map[1][1] = 2;
    snake.push(make_pair(1,1));
    while(true){
        time++;
        if(forward_dir==0){
            snake.push(make_pair(snake.back().first-1, snake.back().second));
            if(direction[time]==1) forward_dir = 1;
            else if(direction[time] == 2) forward_dir = 3;
            
        }
        else if(forward_dir==1){
            snake.push(make_pair(snake.back().first, snake.back().second+1));
            if(direction[time]==1) forward_dir = 2;
            else if(direction[time] == 2) forward_dir = 0;
            
        }
        else if(forward_dir==2){
            snake.push(make_pair(snake.back().first+1, snake.back().second));
            if(direction[time]==1) forward_dir = 3;
            else if(direction[time] == 2) forward_dir = 1;
            
        }
        else{
            snake.push(make_pair(snake.back().first, snake.back().second-1));
            if(direction[time]==1) forward_dir = 0;
            else if(direction[time] == 2) forward_dir = 2;
            
        }
        if(snake.back().first < 1 || snake.back().second < 1 || snake.back().first > N || snake.back().second > N) break;
        if(map[snake.back().first][snake.back().second] == 0){
            map[snake.front().first][snake.front().second] = 0;
            snake.pop();
            map[snake.back().first][snake.back().second] = 2;
        }
        else if(map[snake.back().first][snake.back().second] == 1) map[snake.back().first][snake.back().second] = 2;
        else if(map[snake.back().first][snake.back().second] == 2) break;
    }
    printf("%d\n", time);
    return 0;
}
