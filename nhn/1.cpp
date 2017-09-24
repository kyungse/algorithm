//
//  main.cpp
//  task
//
//  Created by 박경세 on 2017. 9. 23..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> budget;
int print_check = 0;

int main(int argc, const char * argv[]) {
    string sentence;
    getline(cin, sentence);
    for(int i=0; i<(int)sentence.size(); i+=2){
        int check = 0;
        for(int j=0; j<(int)budget.size(); j++){
            if(budget[j]==(sentence[i]-'0')){
                budget.erase(budget.begin()+j);
                budget.push_back(sentence[i]-'0');
                check = 1;
            }
        }
        if(!check){
            if((int)budget.size() >= 3){
                printf("%d\n", budget[0]);
                budget.erase(budget.begin());
                print_check = 1;
            }
            budget.push_back(sentence[i]-'0');
        }
    }
    if(!print_check) printf("%d\n", print_check);
    return 0;
}