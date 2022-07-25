#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer(2, 0);
        auto left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(left == nums.size() || nums[left] != target) left = -1;
        answer[0] = left;
        auto right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        right--;
        if(left == -1) right = -1;
        answer[0] = left; answer[1] = right;        
        return answer;
    }
};