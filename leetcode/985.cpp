#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto num : nums){
            if(num % 2 == 0) sum += num;
        }
        vector<int> answer;
        for(auto query : queries){
            int val = query[0];
            int idx = query[1];
            if(nums[idx] % 2 == 0){
                if(val % 2 == 0){
                    nums[idx] += val;
                    sum += val;
                }
                else{
                    sum -= nums[idx];
                    nums[idx] += val;
                }
            }
            else{
                nums[idx] += val;
                if(val % 2) sum += nums[idx];
            }
            answer.push_back(sum);
        }
        return answer;
    }
};