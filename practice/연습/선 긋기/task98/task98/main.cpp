//
//  main.cpp
//  task98
//
//  Created by 박경세 on 2017. 8. 22..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

long long answer = 0;
stack<pair<long long, long long> > group;
vector<pair<long long, long long> > sorted_group;

int main(int argc, const char * argv[]) {
    long long N, start, end;
    scanf("%lld", &N);
    for(int i=0; i<N; i++){
        scanf("%lld %lld", &start, &end);
        sorted_group.push_back(make_pair(start, end));
    }
    sort(sorted_group.begin(), sorted_group.end());
    group.push(sorted_group[0]);
    for(int i=1; i<N; i++){
        if(group.top().second >= sorted_group[i].first){
            long long temp_start = group.top().first;
            long long temp_end = max(sorted_group[i].second, group.top().second);
            group.pop();
            group.push(make_pair(temp_start, temp_end));
        }
        else{
            group.push(sorted_group[i]);
        }
    }
    while(!group.empty()){
        long long temp = abs(group.top().second - group.top().first);
        group.pop();
        answer += temp;
    }
    printf("%lld\n", answer);
    return 0;
}
