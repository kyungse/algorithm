//
//  main.cpp
//  task121
//
//  Created by 박경세 on 2017. 9. 9..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <set>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

set<string> sentence;

int main(int argc, const char * argv[]) {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        string temp;
        cin>>temp;
        sentence.insert(temp);
    }
    vector<string> answer;
    for(int i=0; i<M; i++){
        string temp;
        cin>>temp;
        if(sentence.count(temp) > 0) answer.push_back(temp);
    }
    sort(answer.begin(), answer.end());
    int size = (int)answer.size();
    printf("%d\n", size);
    for(int i=0; i<size; i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}
