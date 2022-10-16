#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    const int INF = 1e9;
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        if(n < d) return -1;
        vector<vector<int>> dp(d+1, vector<int>(n+1, INF));
        vector<vector<int>> max_j(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            int max_job = -1;
            for(int j = i; j >= 0; j--){
                max_job = max(max_job, job[j]);
                max_j[j][i] = max_job;
                if(i == n-1) dp[1][j] = max_job;
            }
        }
        for(int i = 2; i <= d; i++){
            for(int j = 0; j <= n - i; j++){
                for(int k = j; k < n; k++){
                    dp[i][j] = min(dp[i][j], max_j[j][k] + dp[i-1][k+1]);
                }
            }
        }
        return dp[d][0];
    }
};