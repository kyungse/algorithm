//
//  main.cpp
//  task84
//
//  Created by 박경세 on 2017. 5. 15..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int T, K, C, S;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        scanf("%d %d %d", &K, &C, &S);
        printf("Case #%d: ", t);
        if(K!=S) printf("IMPOSSIBLE\n");
        else {
            for(int i=1; i<=K; i++) printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}
