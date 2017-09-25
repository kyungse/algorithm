//
//  main.cpp
//  task110
//
//  Created by 박경세 on 2017. 9. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int N;
long long cur = 0;
long long number = 0;

void getNumber(long long total, int num, int cnt){
    if(cnt==0){
        cur++;
        if(cur==N){
            number = total;
            return;
        }
    }
    else{
        for(int i=0; i<num; i++){
            getNumber(total*10+i, i, cnt-1);
            if(cur==N) return;
        }
    }
}

void check(){
    int cnt = 0;
    while(true){
        for(int i=1; i<=9; i++){
            getNumber(i, i, cnt);
            if(cur==N){
                printf("%lld\n", number);
                return;
            }
        }
        cnt++;
    }
}



int main(int argc, const char * argv[]) {
    scanf("%d", &N);
    if(N > 1022){
        printf("-1\n");
    }
    else if(N==0){
        printf("0\n");
    }
    else{
        check();
    }
    
    return 0;
}
