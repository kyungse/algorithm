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
#include <vector>
#include <string>

using namespace std;

int m, n;
int check_map[30][30] = {0,};
vector<vector<char> > board;
vector<vector<char> > linked_list;

int answer = 0;
void clear(){
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) check_map[i][j] = 0;
}
void check(int row, int col){
    char c = linked_list[row][col];
    if(row+1<n && col+1<m){
        if(linked_list[row+1][col]==c && linked_list[row][col+1]==c && linked_list[row+1][col+1]==c){
            check_map[row][col] = check_map[row+1][col] = check_map[row][col+1] = check_map[row+1][col+1] = 1;
        }
    }
}
int erase(){
    int erase_check = 0;
    for(int i=0; i<n; i++){
        vector<char> temp;
        for(int j=0; j<m; j++){
            if(check_map[i][j]){
                answer++;
                erase_check = 1;
            }
            else temp.push_back(linked_list[i][j]);
        }
        linked_list[i] = temp;
    }
    if(erase_check) return 1;
    else return 0;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d\n", &m, &n);
    for(int i=0; i<m; i++){
        char sentence[n];
        vector<char> temp;
        scanf("%s", sentence);
        for(int j=0; j<n; j++) temp.push_back(sentence[j]);
        board.push_back(temp);
    }
    for(int i=0; i<n; i++){
        vector<char> temp;
        for(int j=m-1; j>=0; j--) temp.push_back(board[j][i]);
        linked_list.push_back(temp);
    }
    while(true){
        int end = 0;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) check(i, j);
        if(erase()) end = 1;
        clear();
        if(!end) break;
    }
    printf("%d\n", answer);
    return 0;
}
