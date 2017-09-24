//
//  main.cpp
//  task90
//
//  Created by 박경세 on 2017. 7. 9..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int visit[1001] = {0,};
int length[1001] = {0,};

void check_friend(int user){
    
}

int main(int argc, const char * argv[]) {
    int T, N, bestfriend;
    int BFFs[1001];
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        scanf("%d", &N);
        for(int i=1; i<=N; i++) BFFs[i] = 0;
        for(int i=1; i<=N; i++){
            scanf("%d", &bestfriend);
            BFFs[i] = bestfriend;
        }
        
    }
    return 0;
}
