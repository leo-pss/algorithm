#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int min_sum[n];
        int max_sum[n];
        
        if(n==1) return nums[0];
        min_sum[0] = nums[0];
        max_sum[0] = nums[0];
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int answer = max(sum - min_sum[0], max_sum[0]);
        for(int i = 1; i < n; i++){
            min_sum[i] = min(0, min_sum[i-1]) + nums[i];
            max_sum[i] = max(0, max_sum[i-1]) + nums[i];
            if(i!=n-1) answer = max(answer, max(sum - min_sum[i], max_sum[i]));
            else answer = max(answer, max_sum[i]);
        }
        
        return answer;
    }
};