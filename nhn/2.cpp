//
//  main.cpp
//  task
//
//  Created by 박경세 on 2017. 9. 23..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int rotate;
    char cmd[30], secret[30], sentence[30];
    char temp_answer[30], answer[30];
    scanf("%s %s %d %s", cmd, secret, &rotate, sentence);
    int size = (int)strlen(sentence);
    if(!strcmp(cmd, "encrypt")){
        for(int i=0; i<size; i++){
            temp_answer[i] = (secret[i]-'a'+sentence[i]-'a') % 26;
        }
        for(int i=0; i<size; i++){
            if(i-rotate>=0){
                answer[i-rotate] = temp_answer[i] + 'a';
            }
            else{
                answer[size+(i-rotate)] = temp_answer[i] + 'a';
            }
        }
        answer[size] = '\0';
        printf("%s\n", answer);
    }
    else if(!strcmp(cmd, "decrypt")){
        for(int i=0; i<size; i++){
            if(i+rotate<size){
                temp_answer[i+rotate] = sentence[i];
            }
            else{
                temp_answer[i+rotate-size] = sentence[i];
            }
        }
        for(int i=0; i<size; i++){
            answer[i] = temp_answer[i]-secret[i] < 0 ? temp_answer[i]-secret[i] + 26 +'a' : temp_answer[i]-secret[i] + 'a';
        }
        answer[size] = '\0';
        printf("%s\n", answer);
    }
    return 0;
}
