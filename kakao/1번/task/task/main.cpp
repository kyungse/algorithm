//
//  main.cpp
//  task
//
//  Created by 박경세 on 2017. 10. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int arr1[16] = {0,};
int arr2[16] = {0,};
int result[16] = {0,};

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr1[i]);
    for(int i=0; i<n; i++) scanf("%d", &arr2[i]);
    for(int i=0; i<n; i++) result[i] = arr1[i] | arr2[i];
    for(int i=0; i<n; i++){
        int index = n-1;
        int temp = result[i];
        int sentence[n];
        for(int j=0; j<n; j++) sentence[j] = 0;
        while(temp){
            if(temp&1) sentence[index] = 1;
            index--;
            temp = temp>>1;
        }
        for(int j=0; j<n; j++){
            if(sentence[j]) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
