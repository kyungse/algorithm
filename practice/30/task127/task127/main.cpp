//
//  main.cpp
//  task127
//
//  Created by 박경세 on 2017. 10. 7..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    long long sum = 0;
    int check_zero = 0;
    char number[100001];
    scanf("%s", number);
    int size = (int)strlen(number);
    for(int i=0; i<size; i++){
        sum += number[i]-'0';
        if(!(number[i]-'0')) check_zero = 1;
    }
    if((sum%3!=0) || !check_zero) printf("-1\n");
    else{
        sort(number, number+size, greater<int>());
        printf("%s\n", number);
    }
    return 0;
}
