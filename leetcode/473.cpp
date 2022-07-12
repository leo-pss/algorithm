#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int dp[5][32768];
    bool solve(vector<int> &ms, int &side, int curr, int cnt, int state){
        if(state == (1 << ms.size()) - 1){
            if(cnt == 4) return true;
            else return false;
        }
        if(cnt > 4) return false;
        if(dp[cnt][state] != -1) return dp[cnt][state];
        
        bool ret = false;
        for(int i = 0; i < ms.size(); i++){
            if((state & (1<<i)) == 0){
                state = state ^ (1<<i);
                if(curr + ms[i] < side){
                    ret = ret || solve(ms, side, curr + ms[i], cnt, state);
                }
                else if(curr + ms[i] == side){
                    ret = ret || solve(ms, side, 0, cnt + 1, state);
                }
                state = state ^ (1<<i);
            }
        }
        return dp[cnt][state] = ret;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        for(int match : matchsticks) sum += match;
        if(sum%4 != 0) return false;
        sum /= 4;
        return solve(matchsticks, sum, 0, 0, 0);
    }
};