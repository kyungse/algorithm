//
//  main.cpp
//  task94
//
//  Created by 박경세 on 2017. 8. 20..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#define min(a,b) ((a) > (b) ? (b) : (a))

using namespace std;

int n, door1, door2, temp_n, temp;
vector<int> order;
int dp[21][21][21];

int check(int one, int two, int index){
    if(index == temp_n){
        return 0;
    }
    if(dp[one][two][index] != -1) return dp[one][two][index];
    dp[one][two][index] = min(check(order[index], two, index+1) + abs(order[index] - one), check(one, order[index], index+1) + abs(order[index] - two));
    return dp[one][two][index];
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    scanf("%d %d", &door1, &door2);
    scanf("%d", &temp_n);
    for(int i=0; i<temp_n; i++){
        scanf("%d", &temp);
        order.push_back(temp);
    }
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            for(int k=0; k<21; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    printf("%d\n", check(door1, door2, 0));
    return 0;
}
