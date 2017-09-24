//
//  main.cpp
//  task91
//
//  Created by 박경세 on 2017. 7. 10..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int end_check = 0;
int input[26] = {0,};
int answer[10] = {0,};
int number[10][26] = {0,};

void check(int index, int length){
    int temp=0, len=0;
    if(index > 9){
        end_check = 1;
        return;
    }
    if(!length){
        for(int i=0; i<10; ){
            if(answer[i]){
                printf("%d", i);
                answer[i]--;
            }
            if(!answer[i]) i++;
        }
        end_check = 1;
        return;
    }
    for(int i=0; i<26; i++){
        if(input[i] < number[index][i]){
            temp=1;
            break;
        }
    }
    if(!temp){
        answer[index]++;
        for(int i=0; i<26; i++){
            input[i] -= number[index][i];
            len += number[index][i];
        }
        check(index, length-len);
        if(end_check==1) return;
        check(index, length-len);
        answer[index]--;
    }
    if(end_check==1) return;
    check(index+1, length);
    
}

int main(int argc, const char * argv[]) {
    int T;
    char sentence[2001];
    number[0][25] = number[0][4] = number[0][17] = number[0][14] = 1;
    number[1][14] = number[1][13] = number[1][4] = 1;
    number[2][19] = number[2][22] = number[2][14] = 1;
    number[3][19] = number[3][7] = number[3][17] = number[3][4] = 1;
    number[3][4]++;
    number[4][5] = number[4][14] = number[4][20] = number[4][17] = 1;
    number[5][5] = number[5][8] = number[5][21] = number[5][4] = 1;
    number[6][18] = number[6][8] = number[6][23] = 1;
    number[7][18] = number[7][4] = number[7][21] = number[7][13]  = 1;
    number[7][4]++;
    number[8][4] = number[8][8] = number[8][6] = number[8][7] = number[8][19] = 1;
    number[9][13] = number[9][8] = number[9][4] = 1;
    number[9][13]++;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        end_check = 0;
        for(int i=0; i<26; i++) input[i] = 0;
        for(int i=0; i<10; i++) answer[i] = 0;
        scanf("%s", sentence);
        for(int i=0; i<(int)strlen(sentence); i++) input[sentence[i]-65]++;
        printf("Case #%d: ", t);
        check(0, (int)strlen(sentence));
        printf("\n");
    }
    return 0;
}
