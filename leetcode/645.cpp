#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> cnt(nums.size()+1, 0);
        int miss = 1, dup = -1;
        for(int num : nums) cnt[num]++;
        for(int i = 1; i < cnt.size(); i++){
            if(cnt[i] == 0) miss = i;
            else if(cnt[i] == 2) dup = i;            
        }
        return {dup, miss};
    }
};