//
//  main.cpp
//  task
//
//  Created by 박경세 on 2017. 10. 1..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> A;
vector<string> B;
vector<string> common;
vector<string> sum;
int common_check[3000] = {0,};

int main(int argc, const char * argv[]) {
    string str1 = "FRANCE";
    string str2 = "french";
    transform(str1.begin(), str1.end(), str1.begin(), (int(*)(int))toupper);
    transform(str2.begin(), str2.end(), str2.begin(), (int(*)(int))toupper);
    int size1 = (int)str1.size();
    int size2 = (int)str2.size();
    for(int i=0; i<size1-1; i++){
        if(str1[i]>='A' && str1[i]<='Z' && str1[i+1]>='A' && str1[i+1]<='Z'){
            A.push_back(str1.substr(i, 2));
        }
    }
    for(int i=0; i<size2-1; i++){
        if(str2[i]>='A' && str2[i]<='Z' && str2[i+1]>='A' && str2[i+1]<='Z'){
            B.push_back(str2.substr(i, 2));
        }
    }
    for(int i=0; i<(int)A.size(); i++){
        for(int j=0; j<(int)B.size(); j++){
            if(A[i].compare(B[j])==0 && !common_check[j]){
                common.push_back(A[i]);
                common_check[j] = 1;
                break;
            }
        }
    }
    sum = A;
    for(int i=0; i<(int)B.size(); i++) if(!common_check[i]) sum.push_back(B[i]);
    double common_size = (double)((int)common.size());
    double sum_size = (double)((int)sum.size());
    if(!common_size || !sum_size) common_size = sum_size = 1;
    printf("%d\n", (int)(common_size/sum_size*65536));
    return 0;
}
