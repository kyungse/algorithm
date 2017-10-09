#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int index=0, point[3];
    char bonus[3], option[3];
    
    int size = (int)dartResult.length();
    for(int i=0; i<size; i++){
        if(dartResult[i]=='S'||dartResult[i]=='D'||dartResult[i]=='T'){
            if(i-2>=0 && dartResult[i-2]>'0' && dartResult[i-2]<='1'){
                point[index] = 10;
            }
            else point[index] = dartResult[i-1]-'0';
            bonus[index] = dartResult[i];
            if(dartResult[i+1]=='#'||dartResult[i+1]=='*'){
                option[index] = dartResult[i+1];
            }
            index++;
        }
    }
    for(int i=0; i<3; i++){
        if(bonus[i]=='D'){
            point[i] = point[i]*point[i];
        }
        else if(bonus[i]=='T'){
            point[i] = point[i]*point[i]*point[i];
        }
        if(option[i]=='#'){
            point[i] *= -1;
        }
        else if(option[i]=='*'){
            if(i-1>=0) for(int j=i; j>=i-1; j--) point[j] *= 2;
            else for(int j=i; j>=0; j--) point[j] *= 2;
        }
    }
    for(int i=0; i<3; i++) answer += point[i];
    return answer;
}
