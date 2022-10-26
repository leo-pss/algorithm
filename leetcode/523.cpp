#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> mod_k;
        int sum = 0;
        int prev_sum = 0;
        for(int num : nums){
            sum = (sum + num) % k;
            if(mod_k.find(sum) != mod_k.end()) return true;
            mod_k.insert(prev_sum);
            prev_sum = sum;
        }
        return false;
    }
};