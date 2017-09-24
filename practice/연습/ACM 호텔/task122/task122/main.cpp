//
//  main.cpp
//  task122
//
//  Created by 박경세 on 2017. 9. 10..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int T, H, W, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &H, &W, &N);
        int row=1, col=1;
        int temp = N;
        while(temp > H){
            temp-=H;
            col++;
        }
        row = (N % H);
        if(!row) row += H;
        printf("%d%02d\n", row, col);
    }
    return 0;
}
