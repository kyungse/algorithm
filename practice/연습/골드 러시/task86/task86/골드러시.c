//
//  main.cpp
//  task86
//
//  Created by 박경세 on 2017. 5. 24..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int t, n;
    long long min, a, b;
    int days=0;
    int two=1;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        days = 0;
        two = 1;
        scanf("%d %lld %lld", &n, &a, &b);
        min = a&b;
        while(min != 0){
            min = min >> 1;
            days++;
        }
        printf("%d\n", n-days+1);
    }
    return 0;
}
