//
//  main.cpp
//  task129
//
//  Created by 박경세 on 2017. 10. 11..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N, A, B, round=1;
    scanf("%d %d %d", &N, &A, &B);
    while(true){
        for(int i=1; i<N; i+=2){
            if((A==i && B==(i+1)) || (A==(i+1) && B==i)){
                printf("%d\n", round);
                return 0;
            }
        }
        if(A%2==0) A/=2;
        else A=(A+1)/2;
        if(B%2==0) B/=2;
        else B=(B+1)/2;
        round++;
    }
    return 0;
}
