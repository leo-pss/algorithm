#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int answer = 1;
        int n = nums.size();
        vector<int> down(n, 1);
        vector<int> up(n, 1);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    up[i] = max(up[i], down[j] + 1);
                }
                else if(nums[i] < nums[j]){
                    down[i] = max(down[i], up[j] + 1);
                }
            }
            answer = max(answer, up[i]);
            answer = max(answer, down[i]);
        }
        
        return answer;
    }
};