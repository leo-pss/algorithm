#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_map;
        for(int i = 0; i < nums.size(); i++){
            if(num_map.find(nums[i]) != num_map.end()){
                if(i - num_map[nums[i]] <= k) return true;
            }
            num_map[nums[i]] = i;
        }
        return false;
    }
};