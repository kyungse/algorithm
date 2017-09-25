//
//  main.cpp
//  task93
//
//  Created by 박경세 on 2017. 8. 20..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

long long int answer = 1;

int main(int argc, const char * argv[]) {
    int T, n;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        answer = 1;
        scanf("%d", &n);
        while(n != 1){
            answer = max(answer, n);
            if(n%2 == 0) n /= 2;
            else n = n * 3 + 1;
        }
        printf("%lld\n", answer);
    }
    return 0;
}
