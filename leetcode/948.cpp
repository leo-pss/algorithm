#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int l = 0, r = tokens.size() - 1;
        int answer = 0;
        sort(tokens.begin(), tokens.end());
        while(l <= r){
            if(power >= tokens[l]){
                power -= tokens[l];
                ++l;
                answer = max(answer, ++score);
            }
            else if(score > 0){
                --score;
                power += tokens[r];
                --r;
            }
            else break;
        }
        return answer;
    }
};