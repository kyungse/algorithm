//
//  main.cpp
//  task118
//
//  Created by 박경세 on 2017. 9. 2..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

int forward_dir = 1;    // east 1, south = 2, west = 3, north = 4;
int map[101][101] = {0,};
int direction[10001] = {0,};
queue<pair<int, int> > snake;

int main(int argc, const char * argv[]) {
    int N, K, L;
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        int row, col;
        scanf("%d %d", &row, &col);
        map[row-1][col-1] = 1;
    }
    scanf("%d", &L);
    for(int i=0; i<L; i++){
        int second;
        char dir;
        scanf("%d %c", &second, &dir);
        if(dir=='L') direction[second] = 1;
        else if(dir=='D') direction[second] = 2;
    }
    int time = 0;
    snake.push(make_pair(0, 0));
    map[0][0] = 2;
    while(true){
        time++;
        if(forward_dir==1){
            snake.push(make_pair(snake.back().first, snake.back().second+1));
            if(direction[time]==1) forward_dir = 4;
            else if(direction[time]==2) forward_dir = 2;
        }
        else if(forward_dir==2){
            snake.push(make_pair(snake.back().first+1, snake.back().second));
            if(direction[time]==1) forward_dir = 1;
            else if(direction[time]==2) forward_dir = 3;
        }
        else if(forward_dir==3){
            snake.push(make_pair(snake.back().first, snake.back().second-1));
            if(direction[time]==1) forward_dir = 2;
            else if(direction[time]==2) forward_dir = 4;
        }
        else{
            snake.push(make_pair(snake.back().first-1, snake.back().second));
            if(direction[time]==1) forward_dir = 3;
            else if(direction[time]==2) forward_dir = 1;
        }
        if(snake.back().first<0||snake.back().second<0||snake.back().first>=N||snake.back().second>=N) break;
        if(map[snake.back().first][snake.back().second]==0){
            map[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
        else if(map[snake.back().first][snake.back().second] == 2) break;
        map[snake.back().first][snake.back().second] = 2;
    }
    printf("%d\n", time);
    return 0;
}
