#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int size = (int)cities.size();
    vector<string> cache;
    for(int i=0; i<size; i++){
        int check  = 0;
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), (int(*)(int))toupper);
        for(int j=0; j<(int)cache.size(); j++){
            if(cache[j].compare(cities[i])==0){
                cache.erase(cache.begin()+j);
                cache.push_back(cities[i]);
                check = 1;
                answer++;
                break;
            }
        }
        if(!check){
            answer += 5;
            if(cacheSize > 0){
                if((int)cache.size() >= cacheSize) cache.erase(cache.begin());
                cache.push_back(cities[i]);
            }
        }
    }
    return answer;
}
