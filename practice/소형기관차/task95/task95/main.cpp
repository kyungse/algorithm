//
//  main.cpp
//  task95
//
//  Created by 박경세 on 2017. 8. 20..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max(a,b)((a) > (b) ? (a) : (b))

using namespace std;

int answer = 0;
int train[500001] = {0,};
int dp[3][500001] = {0,};
int weight[500001] = {0,};

int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &train[i]);
    scanf("%d", &m);
    for(int i=0; i<n; i++){
        int size = i+m >= n ? n : i+m;
        for(int j=i; j<size; j++){
            weight[i] += train[j];          // weight는 현재위치에서 소형기관차 최대갯수만큼 더한것;
        }
    }
    dp[0][0] = weight[0];
    for(int i=1; i<n; i++) dp[0][i] = max(dp[0][i-1], weight[i]);
    for(int i=1; i<3; i++){
        for(int j=m; j<n; j++){
            dp[i][j] = dp[i-1][j-m] + weight[j];
            for(int k=1; k<m; k++){         // dp[i][j]는 i번째 기차일때, j번째까지 확인했을때 최댓값;
                dp[i][j] = max(dp[i][j], dp[i][j-k]);
            }
        }
    }
    printf("%d\n", dp[2][n-1]);
    return 0;
}
