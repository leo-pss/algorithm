#include <vector>

using namespace std;

class Solution {
    const int MOD = 1000000007;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> d(n+1, vector<int>(target+1, 0));
        
        d[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                for(int l = j; l <= target; l++){
                    d[i][l] = (d[i][l] + d[i-1][l-j]) % MOD;
                }
            }
        }
        return d[n][target];
    }
};