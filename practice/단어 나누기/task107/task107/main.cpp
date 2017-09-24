//
//  main.cpp
//  task107
//
//  Created by 박경세 on 2017. 8. 31..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

char answer[51];

int main(int argc, const char * argv[]) {
    char sentence[51];
    scanf("%s", sentence);
    int size = (int)strlen(sentence);
    for(int i=0; i<size; i++) answer[i] = 'z';
    for(int i=0; i<size-2; i++){
        for(int j=i+1; j<size-1; j++){
            char temp[50];
            int index=0;
            for(int k=i; k>=0; k--) temp[index++] = sentence[k];
            for(int k=j; k>i; k--) temp[index++] = sentence[k];
            for(int k=size-1; k>j; k--) temp[index++] = sentence[k];
            temp[size] = '\0';
            if(strcmp(answer, temp) > 0){
                for(int i=0; i<size; i++) answer[i] = temp[i];
            }
        }
    }
    printf("%s\n", answer);
    return 0;
}
