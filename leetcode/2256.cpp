#include <vector>
#include <cmath>

using namespace std;

class Solution {
    const int INF = 1e9;
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) sum[i] = sum[i-1] + nums[i];
        int min_diff = INF, idx = -1;
        for(int i = 0; i < n - 1; i++){
            int left = sum[i] / (i + 1);
            int right = (sum[n-1] - sum[i]) / (n - i - 1);
            int diff = abs(left - right);
            if(min_diff > diff){
                min_diff = diff;
                idx = i;
            }
        }
        int diff = sum[n-1] / n;
        if(min_diff > diff) idx = n - 1;
        return idx;        
    }
};