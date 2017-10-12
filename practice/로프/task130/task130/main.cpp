//
//  main.cpp
//  task130
//
//  Created by 박경세 on 2017. 10. 11..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int rope[100000];

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &rope[i]);
    sort(rope, rope+N);
    int answer = 0;
    for(int i=0; i<N; i++) answer = max(answer, rope[i]*(N-i));
    printf("%d\n", answer);
    return 0;
}
