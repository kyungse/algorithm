//
//  main.cpp
//  task128
//
//  Created by 박경세 on 2017. 10. 7..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int N;
int visit[13] = {0,};
int number[13] = {0,};

void back_tracking(int start, int cnt){
    if(cnt==6){
        for(int i=0; i<N; i++) if(visit[i]) printf("%d ", number[i]);
        printf("\n");
    }
    else{
        for(int i=start+1; i<N; i++){
            if(!visit[i]){
                visit[i] = 1;
                back_tracking(i, cnt+1);
                visit[i] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    while(true){
        scanf("%d", &N);
        if(!N) break;
        else{
            for(int i=0; i<N; i++) scanf("%d", &number[i]);
            for(int i=0; i<=N-6; i++){
                visit[i] = 1;
                back_tracking(i, 1);
                visit[i] = 0;
            }
            printf("\n");
        }
    }
    return 0;
}
