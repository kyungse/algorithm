//
//  main.cpp
//  task99
//
//  Created by 박경세 on 2017. 8. 22..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct P{
    int x;
    int y;
}Point;

vector<Point> island;
const int size = 1<<18;
long long answer = 0;

bool cmp1(Point &a, Point &b){
    return a.y < b.y;                                               // y오름차순 정렬;
};

bool cmp2(Point &a, Point &b){
    if(a.x == b.x) return a.y > b.y;                                // x오름차순인데, x같을시 y내림차순;
    return a.x < b.x;
};

struct SegTree{
    int arr[size];
    SegTree(){memset(arr, 0, sizeof(arr));}
    void inc(int n){                                                // 해당되는 리프노드 추가후, 올라가면서 루트까지 업데이트;
        n += size/2;
        while(n > 0){
            arr[n]++;
            n/=2;
        }
    }                                                               // 0 ~ size/2 구간이 전체 구간;
    int sum(int s, int e){ return sum(s, e, 1, 0, size/2); }        // s ~ e 구간이 내가 원하는 구간;
    int sum(int s, int e, int node, int ns, int ne){                // ns ~ ne 구간이 중간 구간;
        if(s >= ne || e <= ns) return 0;                            // 원하는 범위가 현재 중간범위와 겹치지 않을시 return;
        if(s <= ns && e >= ne) return arr[node];                    // 원하는 범위가 현재 중간범위를 아예 포함할시 해당 node값 return;
        int mid = (ns + ne) / 2;                                    // 범위를 반씩 나누어 해당 node에 맞게 들어간다;
        return (sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne));     // 걸치는 경우 오른쪽, 왼쪽으로 들어가서 재 탐색;
    }
};

int main(int argc, const char * argv[]) {
    int T, N;
    scanf("%d", &T);
    while(T--){
        SegTree SegmentTree;
        island.clear();
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            Point P;
            scanf("%d %d", &P.x, &P.y);
            island.push_back(P);
        }
        sort(island.begin(), island.end(), cmp1);
        int range = 0;
        int newY[75000];
        for(int i=0; i<N; i++){
            if(i>0 && island[i].y != island[i-1].y) range++;        // 0 ~ 1000000000범위를 0 ~ 75000으로 맞추기 위해;
            newY[i] = range;                                        // 오름차순정렬하여 0부터 배당, 같으면 같은번호 아니면 ++;
        }                                                           // segment tree의 leaf node가 y값이 된다;
        
        for(int i=0; i<N; i++) island[i].y = newY[i];
        sort(island.begin(), island.end(), cmp2);
        
        answer = 0;
        for(int i=0; i<N; i++){
            answer += SegmentTree.sum(island[i].y, size/2);
            SegmentTree.inc(island[i].y);
        }
        printf("%lld\n", answer);
    }
    return 0;
}
