//
//  main.cpp
//  task125
//
//  Created by 박경세 on 2017. 9. 25..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int message[1000][1000] = {0,};

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &message[i][j]);
    for(int i=0; i<N; i++){
        int answer = 0;
        for(int j=0; j<N; j++) answer |= message[i][j];     // 나올수있는 숫자는;
        printf("%d ", answer);                              // 다른 것들과 AND해서 나온것들을 모두;
    }                                                       // OR연산하면 원래의 숫자를 찾을 수 있다;
    return 0;
}
