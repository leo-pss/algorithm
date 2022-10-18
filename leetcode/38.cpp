#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev_count = countAndSay(n-1);
        string answer = "";
        int cnt = 0;
        char prev = 'a';
        for(int i = 0; i < prev_count.size(); i++){
            if(i != 0 && prev != prev_count[i]){
                answer += to_string(cnt);
                answer += prev;
                cnt = 0;
            }
            prev = prev_count[i];
            cnt++;
        }
        answer += to_string(cnt);
        answer += prev;
        
        return answer;
    }
};