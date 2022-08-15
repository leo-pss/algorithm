#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'I'){
                if(i < n-1 && s[i+1] == 'V'){
                    i++;
                    answer += 4;
                }
                else if(i < n-1 && s[i+1] == 'X'){
                    i++;
                    answer += 9;
                }
                else answer += 1;
            }
            else if(s[i] == 'V'){
                answer += 5;                
            }
            else if(s[i] == 'X'){
                if(i < n-1 && s[i+1] == 'L'){
                    i++;
                    answer += 40;
                }
                else if(i < n-1 && s[i+1] == 'C'){
                    i++;
                    answer += 90;
                }
                else answer += 10;
            }
            else if(s[i] == 'L'){
                answer += 50;
            }
            else if(s[i] == 'C'){
                if(i < n-1 && s[i+1] == 'D'){
                    i++;
                    answer += 400;
                }
                else if(i < n-1 && s[i+1] == 'M'){
                    i++;
                    answer += 900;
                }
                else answer += 100;
            }
            else if(s[i] == 'D'){
                answer += 500;
            }
            else if(s[i] == 'M'){
                answer += 1000;
            }
        }
        return answer;
    }
};