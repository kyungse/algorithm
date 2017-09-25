//
//  main.cpp
//  task103
//
//  Created by 박경세 on 2017. 8. 30..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#define max(a,b)((a) > (b) ? (a) : (b))

using namespace std;

stack<int> histogram;
long long int answer = 0;
long long int height[100001] = {0,};

int main(int argc, const char * argv[]) {
    int n;
    while(true){
        answer = 0;
        scanf("%d", &n);
        if(!n) break;
        for(int i=0; i<n; i++) scanf("%lld", &height[i]);
        for(int i=0; i<n;){
            if(histogram.empty() || height[histogram.top()] <= height[i]){
                histogram.push(i++);
            }
            else{
                int right = i-1;
                int left = 0;
                long long int temp = height[histogram.top()];
                histogram.pop();
                if(!histogram.empty()) left = histogram.top()+1;
                answer = max(answer, temp*(right-left+1));
            }
        }
        while(!histogram.empty()){
            int right = n-1;
            int left = 0;
            long long int temp = height[histogram.top()];
            histogram.pop();
            if(!histogram.empty()) left = histogram.top()+1;
            answer = max(answer, temp*(right-left+1));
        }
        printf("%lld\n", answer);
    }
    return 0;
}
