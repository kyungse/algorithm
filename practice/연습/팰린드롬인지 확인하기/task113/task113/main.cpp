//
//  main.cpp
//  task113
//
//  Created by 박경세 on 2017. 9. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int dp[102][102] = {0,};

int main(int argc, const char * argv[]) {
    char str1[101], str2[101];
    scanf("%s", str1);
    int size = (int)strlen(str1);
    for(int i=0; i<size; i++){
        str2[i] = str1[size-1-i];
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(str1[i] == str2[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    if(dp[size][size]==size) printf("1\n");
    else printf("0\n");
    return 0;
}
