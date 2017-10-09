//
//  main.cpp
//  task
//
//  Created by 박경세 on 2017. 10. 9..
//  Copyright © 2017년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> timetable;
int visit[2000] = {0,};

int main(int argc, const char * argv[]) {
    int N;
    int n, t, m;
    string time;
    string current_time = "09:00";
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        cin>>time;
        timetable.push_back(time);
    }
    int size = (int)timetable.size();
    sort(timetable.begin(), timetable.end());
    scanf("%d %d %d", &n, &t, &m);
    while(n--){
        vector<string> capacity;
        // 현재 기준시간에 들어갈 수 있는 크루들을 capacity에 넣는다;
        for(int i=0; i<size; i++){
            if(!visit[i] && current_time.compare(timetable[i]) >= 0 && (int)capacity.size() < m){
                visit[i] = 1;
                capacity.push_back(timetable[i]);
            }
        }
        // 가장 늦은시간에 타야하므로, 가장마지막 버스일때 계산을 통해 콘의 시간을 출력;
        if(n==0){
            // 만약 마지막에 탈자리가 남아있다면 기준시간에 도착하는게 가장 늦으므로 그 시간을 출력;
            if((int)capacity.size() < m){
                cout<<current_time<<endl;
            }
            // 그것이 아니라면, capacity에 있는 가장늦은 크루보다 1분 먼저 도착하도록 설정;
            else{
                if(capacity[m-1][4] > '0' && capacity[m-1][4] <= '9') capacity[m-1][4]--;
                else{
                    capacity[m-1][4] = '9';
                    if(capacity[m-1][3] > '0') capacity[m-1][3]--;
                    else{
                        capacity[m-1][3] = '5';
                        if(capacity[m-1][1] > '0') capacity[m-1][1]--;
                        else{
                            capacity[m-1][1] = '9';
                            capacity[m-1][0]--;
                        }
                    }
                }
                cout<<capacity[m-1]<<endl;
            }
            break;
        }
        // 아래부분은 기준시간을 setting해주는 부분 => t에 따라 기준시간을 바꿔준다;
        if(t==60){
            if(current_time[1] >= '9'){
                current_time[0] += 1;
                current_time[1] = '0';
            }
            else{
                current_time[1] += 1;
            }
        }
		// 60분인 경우와 그렇지 않은 경우로 나누어 생각해준다;
        else{
            int ten = t/10;
            int one = t%10;
            if(current_time[4]-'0'+one > 9){
                current_time[4] = '0' + ((current_time[4]-'0'+one) % 10);
                current_time[3] += 1;
            }
            else{
                current_time[4] += one;
            }
            if(current_time[3]-'0'+ten > 5){
                current_time[3] = '0' + ((current_time[3]-'0'+ten) % 6);
                if(current_time[1]-'0' >= 9){
                    current_time[0] += 1;
                    current_time[1] = '0';
                }
                else{
                    current_time[1] += 1;
                }
            }
            else{
                current_time[3] += ten;
            }
        }
    }
    return 0;
}
