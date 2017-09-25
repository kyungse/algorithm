//
//  main.cpp
//  task97
//
//  Created by 박경세 on 2017. 8. 21..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#define min(a,b) ((a) > (b) ? (b) : (a))

using namespace std;

int N, K;
queue<pair<int, int> > Q;
int visited[100001] = {0,};

int main(int argc, const char * argv[]) {
    int cnt = 0;
    scanf("%d %d", &N, &K);
    if(N==K){
        printf("%d\n", cnt);
        return 0;
    }
    Q.push(make_pair(N, 0));
    visited[N] = 1;
    while(true){
        pair<int, int> current = Q.front();
        int current_pos = current.first;
        int current_cnt = current.second;
        Q.pop();
        if(current_pos <= 100000 && current_pos >= 0){
            if(current_pos-1 >= 0 && !visited[current_pos-1]){
                Q.push(make_pair(current_pos-1, current_cnt+1));
                visited[current_pos-1] = 1;
                if(current_pos-1 == K){
                    printf("%d\n", current.second+1);
                    break;
                }
            }
            if(current_pos+1 <= 100000 && !visited[current_pos+1]){
                Q.push(make_pair(current_pos+1, current_cnt+1));
                visited[current_pos+1] = 1;
                if(current_pos+1 == K){
                    printf("%d\n", current.second+1);
                    break;
                }
            }
            if(current_pos*2 <= 100000 && !visited[current_pos*2]){
                Q.push(make_pair(current_pos*2, current_cnt+1));
                visited[current_pos*2] = 1;
                if(current_pos*2 == K){
                    printf("%d\n", current_cnt+1);
                    break;
                }
            }
        }
    }
    return 0;
}
