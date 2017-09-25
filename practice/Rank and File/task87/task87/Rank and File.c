//
//  main.cpp
//  task87
//
//  Created by 박경세 on 2017. 5. 27..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int T, N, num;
    int visit[2501] = {0,};
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        for(int i=0; i<2501; i++) visit[i] = 0;
        scanf("%d", &N);
        for(int i=0; i<2*N-1; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &num);
                visit[num]++;
            }
        }
        printf("Case #%d: ", t);
        for(int i=0; i<2501; i++) if(visit[i] && visit[i]%2==1) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
