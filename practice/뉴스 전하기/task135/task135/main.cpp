//
//  main.cpp
//  task135
//
//  Created by 박경세 on 2018. 1. 5..
//  Copyright © 2018년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int N;
vector<int> child[51];

int recur(int index){
    int max = 0;
    int size = (int)child[index].size();
    int* list = new int[size+1];
    for(int i=0; i<size; i++) list[i] = recur(child[index][i]);
    sort(list, list+size, greater<int>());
    for(int i=0; i<size; i++){
        if(max < list[i] + (i+1)){
            max = list[i] + (i+1);
        }
    }
    delete[] list;
    return max;
}

int main(int argc, const char * argv[]) {
    int parent;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &parent);
        if(parent!=-1) child[parent].push_back(i);
    }
    printf("%d\n", recur(0));
    return 0;
}
