//
//  main.cpp
//  task119
//
//  Created by 박경세 on 2017. 9. 2..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define min(a,b)((a) > (b) ? (b) : (a))

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    int answer = 987654321;
    int number[10] = {0,};
    int map[10][10] = {0,};
    scanf("%d", &N);
    for(int i=0; i<N; i++) number[i] = i;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &map[i][j]);
    sort(number, number+N);
    do{
        int check = 0;
        int temp = 0;
        for(int i=0; i<N-1; i++){
            if(map[number[i]][number[i+1]]) temp += map[number[i]][number[i+1]];
            else{
                check = 1;
                break;
            }
        }
        if(!check && map[number[N-1]][number[0]]){
            answer = min(answer, temp+map[number[N-1]][number[0]]);
        }
    } while(next_permutation(number, number+N));
    printf("%d\n", answer);
    return 0;
}
