//
//  main.cpp
//  task132
//
//  Created by 박경세 on 2017. 10. 11..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int map[50][50] = {0,};

int main(int argc, const char * argv[]) {
    int N, M, answer=0;
    char sentence[50];
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%s", sentence);
        for(int j=0; j<M; j++) map[i][j] = sentence[j]-'0';
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int len = 0;
            int cnt = 1;
            while(i+cnt <N && j+cnt<M){
                if(map[i][j]==map[i+cnt][j+cnt] && map[i][j]==map[i+cnt][j] && map[i][j] == map[i][j+cnt]) len = cnt;
                cnt++;
            }
            answer = max(answer, (len+1)*(len+1));
        }
    }
    printf("%d\n", answer);
    return 0;
}
