#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + nums[i];
        }
        long long answer = numeric_limits<int>::max();
        for(int i = 0; i < n; i++){
            long long left = (long long)nums[i] * (i+1) - sum[i];
            long long right = sum[n-1] - sum[i] - (n - i - 1) * (long long)nums[i];
            answer = min(answer, left + right);
        }
        return answer;
    }
};