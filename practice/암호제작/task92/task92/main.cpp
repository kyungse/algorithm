//
//  main.cpp
//  task92
//
//  Created by 박경세 on 2017. 7. 16..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int number[1000001] = {0,};

int main(int argc, const char * argv[]) {
    int len, K, check=0;
    char P[101];
    scanf("%s%d", P, &K);
    for(int i=2; i<=K; i++){
        if(number[i]) continue;
        for(int j=i+i; j<=K; j+=i) number[j] = 1;
    }
    len = (int)strlen(P);
    for(int i=2; i<=K; i++){
        if(number[i]) continue;
        int sum=0;
        for(int j=0; j<len; j++){
            sum = (sum * 10 + (P[j]-'0')) % i;
        }
        if((sum%i)==0){
            check=i;
            break;
        }
    }
    if(check){
        printf("BAD %d\n", check);
    }
    else{
        printf("GOOD\n");
    }
    return 0;
}
