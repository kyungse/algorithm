//
//  main.cpp
//  task96
//
//  Created by 박경세 on 2017. 8. 21..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

queue<int> Q;
int N, M, V;
int visited[1001] = {0,};
int map[1001][1001] = {0,};


void DFS(int index){
    visited[index] = 1;
    printf("%d ", index);
    for(int i=1; i<=N; i++){
        if(map[index][i] && !visited[i]){
            DFS(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int start, end;
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0; i<M; i++){
        scanf("%d %d", &start, &end);
        map[start][end] = 1;
        map[end][start] = 1;
    }
    DFS(V);
    for(int i=1; i<=N; i++) visited[i] = 0;
    printf("\n");
    Q.push(V);
    visited[V] = 1;
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        printf("%d ", temp);
        for(int i=1; i<=N; i++){
            if(map[temp][i] && !visited[i]){
                visited[i] = 1;
                Q.push(i);
            }
        }
    }
    return 0;
}
