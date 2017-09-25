//
//  main.cpp
//  task106
//
//  Created by 박경세 on 2017. 8. 31..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#define max(a,b)((a) > (b) ? (a) : (b))

using namespace std;

int cost[100] = {0,};
queue<pair<int, int> > Q;

int main(int argc, const char * argv[]) {
    int T, N, M;
    scanf("%d", &T);
    while(T--){
        while(!Q.empty()) Q.pop();
        int cnt = 1;
        int index = 0;
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; i++){
            scanf("%d", &cost[i]);
            Q.push(make_pair(cost[i], i));
        }
        sort(cost, cost+N, greater<int>());
        while(true){
            if(Q.front().first == cost[index]){
                if(Q.front().second == M){
                    printf("%d\n", cnt);
                    break;
                }
                Q.pop();
                cnt++;
                index++;
            }
            else{
                pair<int, int> temp = Q.front();
                Q.pop();
                Q.push(temp);
            }
        }
    }
    return 0;
}
