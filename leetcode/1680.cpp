class Solution {
    const int MOD = 1000000007;
public:
    int concatenatedBinary(int n) {
        long long answer = 0;
        int len = 0;
        for(int i = 1; i <= n; i++){
            if((i & (i-1)) ==0) ++len;
            answer = (answer << len) % MOD;
            answer = (answer + i) % MOD;
        }
        return answer;
    }
};