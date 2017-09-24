//
//  main.cpp
//  task124
//
//  Created by 박경세 on 2017. 9. 13..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#define max(a,b)((a) > (b) ? (a) : (b))
#define min(a,b)((a) > (b) ? (b) : (a))

using namespace std;

int N, M;
long long max_capacity[10001] = {0,};
vector<pair<long long, int> > edge[10001];

void Dijkstra(int start, int destination){
    priority_queue<pair<long long, int> > q;
    q.push(make_pair(987654321, start));
    while(!q.empty()){
        pair<long long, int> cur = q.top();
        q.pop();
        if(cur.second==destination){
            printf("%lld\n", cur.first);
            return;
        }
        for(pair<long long, int> next : edge[cur.second]){
            if(max_capacity[next.second] < next.first){
                max_capacity[next.second] = next.first;
                q.push(make_pair(min(cur.first, next.first), next.second));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int start, end;
        long long cost;
        scanf("%d %d %lld", &start, &end, &cost);
        edge[start].push_back(make_pair(cost, end));
        edge[end].push_back(make_pair(cost, start));
    }
    int start, end;
    scanf("%d %d", &start, &end);
    Dijkstra(start, end);
    return 0;
}
