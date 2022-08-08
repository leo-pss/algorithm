#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int* d = new int[n];
        
        int idx = 0;
        d[0] = nums[0];
        for(int i = 1; i < n; i++){
            if(d[idx] < nums[i]){
                d[++idx] = nums[i];
            }
            else{
                int idx2 = lower_bound(d, d+idx, nums[i]) - d;
                if(idx2 < n) d[idx2] = nums[i];
            }
        }
        return idx + 1;
    }
};