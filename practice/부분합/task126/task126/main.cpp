//
//  main.cpp
//  task126
//
//  Created by 박경세 on 2017. 9. 25..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define min(a,b) ((a) > (b) ? (b) : (a))

using namespace std;

int answer = 987654321;
int sum[100000] = {0,};     // i번 index까지의 총합;
int cost[100000] = {0,};    // 각 수열의 가중치;

int main(int argc, const char * argv[]) {
    int N;
    long long S;
    scanf("%d %lld", &N, &S);
    for(int i=0; i<N; i++) scanf("%d", &cost[i]);
    sum[0] = cost[0];
    for(int i=1; i<N; i++) sum[i] = sum[i-1] + cost[i];
    int i=0, j=0;
    while(true){
        if(i>=N || j>=N) break;
        else{
            if(i==j){                                   // i==j 인경우 하나의 값이 S보다 큰지 비교;
                if(cost[i] >= S){
                    printf("1\n");
                    break;
                }
                else j++;                               // 아니라면 j++;
            }
            else{
                if(sum[j]-sum[i] < S) j++;              // i+1 ~ j까지의 합이 S보다 작으면 j++;
                else{                                   // i+1 ~ j까지의 합이 S보다 같거나 크다면;
                    while(sum[j]-sum[i] >= S && i!=j){  // i를 증가시키면서 더 짧은 범위에서도 클수있는지 확인;
                        answer = min(answer, j-i);
                        i++;
                    }
                }
            }
        }
    }
    if(answer==987654321) printf("0\n");
    else printf("%d\n", answer);
    return 0;
}
