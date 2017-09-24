//
//  main.cpp
//  task83
//
//  Created by 박경세 on 2017. 5. 15..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    char S[1001];
    vector<char> answer;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        answer.clear();
        scanf("%s", S);
        answer.push_back(S[0]);
        for(int i=1; i<(int)strlen(S); i++){
            if(S[i] >= answer[0]) answer.insert(answer.begin(), S[i]);      // 맨앞 글자보다 사전식으로 같거나 크면 앞에넣고;
            else answer.push_back(S[i]);                                    // 아닌경우에 맨뒤에 넣는다;
        }
        printf("Case #%d: ", t);
        for(int i=0; i<(int)strlen(S); i++) printf("%c", answer[i]);
        printf("\n");
    }
    return 0;
}
