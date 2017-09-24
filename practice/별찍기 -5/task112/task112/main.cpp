//
//  main.cpp
//  task112
//
//  Created by 박경세 on 2017. 9. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    int max_star = 2*N-1;
    for(int i=0; i<N; i++){
        int star = max_star;
        int space = 0;
        for(int j=0; j<(N-1)-i; j++){
            space++;
            star -= 2;
        }
        for(int j=0; j<space; j++) printf(" ");
        for(int j=0; j<star; j++) printf("*");
        printf("\n");
    }
    for(int i=0; i<N; i++){
        int star = max_star;
        int space = 0;
        for(int j=0; j<=i; j++){
            space++;
            star -= 2;
        }
        for(int j=0; j<space; j++) printf(" ");
        for(int j=0; j<star; j++) printf("*");
        printf("\n");
    }
    return 0;
}
