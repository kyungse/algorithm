//
//  main.cpp
//  task115
//
//  Created by 박경세 on 2017. 9. 2..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int answer = 0;
int check[26] = {0,};
char sentence[100][101];

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int correct = 0;
        for(int j=0; j<26; j++) check[j] = 0;
        scanf("%s", sentence[i]);
        check[sentence[i][0]-'a'] = 1;
        for(int j=1; j<(int)strlen(sentence[i]); j++){
            if(check[sentence[i][j]-'a']==3){
                correct = 1;
                break;
            }
            else{
                if(sentence[i][j] == sentence[i][j-1]){
                    check[sentence[i][j]-'a'] = 1;
                }
                else{
                    check[sentence[i][j-1]-'a'] = 3;
                    if(!check[sentence[i][j]-'a']) check[sentence[i][j]-'a'] = 1;
                }
            }
        }
        if(!correct) answer++;
    }
    printf("%d\n", answer);
    return 0;
}
