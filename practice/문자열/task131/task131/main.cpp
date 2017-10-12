//
//  main.cpp
//  task131
//
//  Created by 박경세 on 2017. 10. 11..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#define min(a,b) ((a) > (b) ? (b) : (a))

using namespace std;

string A, B;
int answer = 987654321;

int main(int argc, const char * argv[]) {
    cin>>A;
    cin>>B;
    int Asize = (int)A.length();
    int Bsize = (int)B.length();
    for(int i=0; i<=Bsize-Asize; i++){
        int cnt = 0;
        for(int j=0; j<Asize; j++){
            if(A[j] != B[i+j]) cnt++;
        }
        answer = min(answer, cnt);
    }
    printf("%d\n", answer);
    return 0;
}
