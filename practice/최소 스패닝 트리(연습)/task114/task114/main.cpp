//
//  main.cpp
//  task114
//
//  Created by 박경세 on 2017. 9. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    int start;
    int end;
    int cost;
}NODE;

long long answer = 0;
vector<NODE> info;
int group[10001] = {0,};

bool cmp(NODE a, NODE b){ return a.cost < b.cost; }
int find(int number){
    if(group[number] == number) return number;
    else return find(group[number]);
}

int main(int argc, const char * argv[]) {
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i=0; i<V; i++) group[i] = i;
    for(int i=0; i<E; i++){
        NODE N;
        scanf("%d %d %d", &N.start, &N.end, &N.cost);
        info.push_back(N);
    }
    sort(info.begin(), info.end(), cmp);
    for(int i=0; i<E; i++){
        int group1 = find(info[i].start);
        int group2 = find(info[i].end);
        if(group1 == group2) continue;
        group[group1] = group[group2];
        answer += info[i].cost;
    }
    printf("%lld\n", answer);
    return 0;
}
