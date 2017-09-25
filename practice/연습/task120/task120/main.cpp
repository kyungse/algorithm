#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#define min(a,b) ((a) > (b) ? (b) : (a))

using namespace std;

int N, M;
int answer = 987654321;
int map[100][100] = {0,};
int visit[100][100] = {0,};
int row_dir[4] = {1, -1, 0, 0};
int col_dir[4] = {0, 0, 1, -1};

void DFS(int row, int col, int cnt){
    if(row==N-1 && col==M-1){
        answer = min(answer, cnt);
        return;
    }
    for(int i=0; i<4; i++){
        if(map[row+row_dir[i]][col+col_dir[i]] && !visit[row+row_dir[i]][col+col_dir[i]]){
            visit[row+row_dir[i]][col+col_dir[i]] = 1;
            DFS(row+row_dir[i], col+col_dir[i], cnt+1);
            visit[row+row_dir[i]][col+col_dir[i]] = 0;
        }
    }
}

void BFS(int row, int col){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(row, col)));
    while(!q.empty()){
        int cnt = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        visit[r][c] = 1;
        if(r==N-1 && c==M-1){
            printf("%d\n", cnt);
            break;
        }
        for(int i=0; i<4; i++){
            if(map[r+row_dir[i]][c+col_dir[i]] && !visit[r+row_dir[i]][c+col_dir[i]]){
                q.push(make_pair(cnt+1, make_pair(r+row_dir[i], c+col_dir[i])));
            }
        }
    }
}

int main(int argc, const char * argv[]){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &map[i][j]);
    DFS(0, 0, 0);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) visit[i][j] = 0;
    BFS(0, 0);
    return 0;
}

