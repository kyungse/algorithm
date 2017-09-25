//
//  main.cpp
//  task102
//
//  Created by 박경세 on 2017. 8. 28..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int max_number;
long long answer = 0;
int value[1000001] = {0,};

int main(int argc, const char * argv[]) {
    int N, T;
    scanf("%d", &T);
    while(T--){
        answer = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%d", &value[i]);
        max_number = value[N-1];
        for(int i=N-2; i>=0; i--){
            if(max_number <= value[i]) max_number = value[i];
            else{
                int j = i;
                for(; max_number > value[j] && j>=0; j--){
                    answer += max_number - value[j];
                }
                if(j < 0) break;
                else i=j+1;
            }
        }
        printf("%lld\n", answer);
    }
    return 0;
}
