//
//  main.cpp
//  task100
//
//  Created by 박경세 on 2017. 8. 24..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int A, B;
int numberA[10] = {0,};
int numberB[10] = {0,};

void yes_rotate(){
    int answer = 0;
    char numA[5][10], numB[5][10];
    int temp_max = 10, temp_min = 1, spotA = 0, spotB = 0;
    for(int i=0; i<5; i++) for(int j=0; j<10; j++) numA[i][j] = numB[i][j] = 0;
    while(temp_min <= A){
        numA[spotA++][(A%temp_max)/temp_min] = 1;
        temp_max *= 10;
        temp_min *= 10;
    }
    temp_max = 10, temp_min = 1;
    while(temp_min <= B){
        numB[spotB++][(B%temp_max)/temp_min] = 1;
        temp_max *= 10;
        temp_min *= 10;
    }
    
    int first = 0;
    for(int i=0; i<spot; i++){
        for(int j=1; j<10; j++){
            if(numA[i][j]){
                first = j;
                break;
            }
        }
    }
    printf("first = %d\n", first);
    for(int i=0; i<spot; i++){
        for(int j=0; j<10; j++){
            if(numB[i][j] && j==first) answer = i;
        }
    }
    if(answer > spot/2){
        for(int i=0; i<spot-answer; i++) printf("R");
    }
    else{
        for(int i=0; i<answer; i++) printf("L");
    }
}

void no_rotate(){
    int big = A > B ? A : B;
    int small = A > B ? B : A;
    while(big != small){
        if(big >= small*2){
            small *= 2;
            printf("D");
        }
        else{
            small += 1;
            printf("S");
        }
    }
}

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d", &T);
    while(T--){
        printf("[%d]\n",T);
        for(int i=0; i<10; i++) numberA[i] = numberB[i] = 0;
        int temp_max = 10, temp_min = 1;
        int check = 0;
        scanf("%d %d", &A, &B);
        while(temp_min < A){
            numberA[(A%temp_max)/temp_min]++;
            temp_max *= 10;
            temp_min *= 10;
        }
        temp_max = 10, temp_min = 1;
        while(temp_min < B){
            numberB[(B%temp_max)/temp_min]++;
            temp_max *= 10;
            temp_min *= 10;
        }
        numberA[0] = numberB[0] = 0;
        for(int i=0; i<10; i++){
            if(numberA[i] != numberB[i]){
                no_rotate();
                check = 1;
                break;
            }
        }
        if(!check) yes_rotate();
        printf("\n");
    }
    return 0;
}
