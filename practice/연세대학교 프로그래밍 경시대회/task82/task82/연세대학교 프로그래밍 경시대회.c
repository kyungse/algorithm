//
//  main.cpp
//  task82
//
//  Created by 박경세 on 2017. 5. 15..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N, cnt=0;
    scanf("%d", &N);                    // x+y+z = N;
    for(int x=2; x<N-3; x+=2){          // x는 짝수로 증가;
        int temp = N-x;                 // 남은 수 temp;
        for(int y=1; y<temp; y++){      // y=1부터;
            int z = temp-y;             // z=temp-y;
            if(z-y < 2) break;          // 차이가 2보다 작으면 그만둔다;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
