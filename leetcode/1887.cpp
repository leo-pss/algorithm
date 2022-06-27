#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int cnt = 0;
        int answer = 0;
        for(int i=1; i<n; i++){
            if(prev < nums[i]) cnt++;
            prev = nums[i];
            answer += cnt;
        }
        return answer;
    }
};