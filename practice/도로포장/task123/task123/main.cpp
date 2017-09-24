//
//  main.cpp
//  task123
//
//  Created by 박경세 on 2017. 9. 10..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#define min(a,b)((a) > (b) ? (b) : (a))

using namespace std;

int N, M, K;
vector<pair<int, int> > map[10001];

int dijkstra(int destination){
    long long answer = 1e15;
    long long distance[10001][21];
    for(int i=0; i<10001; i++) for(int j=0; j<21; j++) distance[i][j] = 1e15;
    priority_queue<pair<long long, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(1, K)));
    distance[1][K] = 0;
    while(!pq.empty()){
        int current = pq.top().second.first;
        int count = pq.top().second.second;
        long long cost = -(pq.top().first);
        pq.pop();
        int size = (int)map[current].size();
        for(int i=0; i<size; i++){
            int next = map[current][i].first;
            if(count > 0 && distance[next][count-1] > cost){
                distance[next][count-1] = cost;
                pq.push(make_pair(-cost, make_pair(next, count-1)));
            }
            if(distance[next][count] > cost + map[current][i].second){
                distance[next][count] = cost + map[current][i].second;
                pq.push(make_pair(-distance[next][count], make_pair(next, count)));
            }
        }
    }
    for(int i=0; i<=K; i++) answer = min(answer, distance[N][i]);
    printf("%lld\n", answer);
    return 0;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0; i<M; i++){
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        map[start].push_back(make_pair(end, cost));
        map[end].push_back(make_pair(start, cost));
    }
    dijkstra(N);
    return 0;
}
