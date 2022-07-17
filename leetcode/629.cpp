#include <vector>
#define MOD 1000000007

using namespace std;

class Solution {
public:
    // d[n][k] : n개일때 페어 k개인 배열의 수. d[n+1][k] = d[n][k] + d[n][k-1] + ... + d[n][k-n+1];
    int kInversePairs(int n, int k) {
        vector<vector<int>> d(n+1, vector<int>(k+1, 0));
        vector<int> prev_sum(k+1, 0);
        
        if(k == 0) return 1;
        d[1][0] = 1;
        if(n==1) return d[n][k];
        d[2][0] = 1; 
        d[2][1] = 1;
        prev_sum[0] = d[2][0];
        for(int i = 1; i <= k; i++){
            prev_sum[i] = (prev_sum[i-1] + d[2][i]) % MOD;
        }

        for(int i = 3; i <= n; i++){
            for(int j = 0; j <= k; j++){
                if(j >= i) d[i][j] = (prev_sum[j] - prev_sum[j-i] + MOD) % MOD;
                else d[i][j] = prev_sum[j];
            }
            prev_sum.clear();
            prev_sum.resize(k+1);
            prev_sum[0] = d[i][0];
            for(int j = 1; j <= k; j++){
                prev_sum[j] = (prev_sum[j-1] + d[i][j]) % MOD;
            }
        }
        return d[n][k];
    }
};