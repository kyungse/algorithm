//
//  main.cpp
//  task116
//
//  Created by 박경세 on 2017. 9. 2..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

int A[50], B[50];

int main(int argc, const char * argv[]) {
    int N, S=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    for(int i=0; i<N; i++) scanf("%d", &B[i]);
    sort(A, A+N);
    sort(B, B+N, greater<int>());
    for(int i=0; i<N; i++) S += A[i]*B[i];
    printf("%d\n", S);
    return 0;
}
