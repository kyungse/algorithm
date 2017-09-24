//
//  main.cpp
//  task85
//
//  Created by 박경세 on 2017. 5. 21..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b)((a)>(b)?(a):(b))

using namespace std;

long long answer = 0;
int group[100000] = {0,};
int total_algo[31] = {0,};
int personal_algo[100000][31] = {0,};

int main(int argc, const char * argv[]) {
    int N, K, D, M, d;
    int algo, common=0, total=0, size=0;
    int start=0, end=0, past_end=0;
    vector<pair<int, int> > ability;
    scanf("%d %d %d", &N, &K, &D);
    for(int i=0; i<N; i++){
        scanf("%d %d", &M, &d);
        ability.push_back(make_pair(d, i));
        for(int j=0; j<M; j++){
            scanf("%d", &algo);
            personal_algo[i][algo] = 1;
        }
    }
    sort(ability.begin(), ability.end());
    for(start=0; start<N; start++){             // past_end ~ end-1까지가 새로 추가된것;
        if(start){
            size--;
            for(int i=0; i<31; i++) if(personal_algo[ability[start-1].second][i]) total_algo[i]--;
        }
        for(;end<N; end++){
            if(ability[end].first - ability[start].first <= D) size++;
            else break;
        }
        for(int i=past_end; i<end; i++){
            for(int j=0; j<31; j++) if(personal_algo[ability[i].second][j]) total_algo[j]++;
        }
        for(int i=0; i<31; i++){
            if(total_algo[i]) total++;
            if(total_algo[i]==size) common++;
        }
        answer = max(answer, (total-common)*size);
        total = common = 0;
        past_end = end;
    }
    printf("%lld\n", answer);
    return 0;
}
