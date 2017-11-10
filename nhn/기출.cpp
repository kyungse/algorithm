//
//  main.cpp
//  task
//
//  Created by 박경세 on 2017. 11. 10..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int visit[1000][1000] = {0,};
int row_dir[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int col_dir[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void check(int row, int col){
    int count = 0, d=0;
    visit[row][col] = 1;
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(row, col)));
    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        d = q.front().first;
        q.pop();
        count++;
        for(int i=0; i<8; i++){
            if(r+row_dir[i]>=0&&r+row_dir[i]<N&&c+col_dir[i]>=0&&c+col_dir[i]<M){
                if(!visit[r+row_dir[i]][c+col_dir[i]]){
                    visit[r+row_dir[i]][c+col_dir[i]] = 1;
                    q.push(make_pair(d+1, make_pair(r+row_dir[i], c+col_dir[i])));
                }
            }
        }
    }
    if(count != N*M) printf("F%d", d);
    else printf("T%d", d);
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &N, &M);
	if(N<=0 || M<=0) printf("-1");
    else check(0, 0);
    return 0;
}
