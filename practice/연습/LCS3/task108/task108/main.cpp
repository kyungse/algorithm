//
//  main.cpp
//  task108
//
//  Created by 박경세 on 2017. 9. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define max(a,b)((a) > (b) ? (a) : (b))

using namespace std;

int dp[102][102][102] = {0,};

int main(int argc, const char * argv[]) {
    int size1, size2, size3;
    char str1[100], str2[100], str3[100];
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    size1 = (int)strlen(str1);
    size2 = (int)strlen(str2);
    size3 = (int)strlen(str3);
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            for(int k=0; k<size3; k++){
                if(str1[i]==str2[j]&&str2[j]==str3[k]) dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
                else dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k], max(dp[i+1][j][k+1], dp[i][j+1][k+1]));
            }
        }
    }
    printf("%d\n", dp[size1][size2][size3]);
    return 0;
}
