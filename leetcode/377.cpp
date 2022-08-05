#include <algorithm>
#include <vector>

using namespace std;

const long long MOD = 2147483648;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> answer(target+1, 0);
        
        answer[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int num : nums){
                if(i >= num) answer[i] = (answer[i] + answer[i-num]) % MOD;
            }
        }
        return answer[target];
    }
};