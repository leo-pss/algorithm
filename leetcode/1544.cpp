#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string answer;
        for(int i = 0; i < s.size(); i++){
            answer.push_back(s[i]);
            while(answer.size() && abs(answer.back() -  s[i+1]) == 32){
                answer.pop_back();
                i++;
            }
        }
        return answer;
    }
};