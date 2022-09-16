#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> d(m+1, vector<int>(m+1, 0));
        // d[i][j] : i번째 operation 끝, j만큼 left
        
        for(int i = m - 1; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                d[i][j] = max(multipliers[i] * nums[j] + d[i+1][j+1], multipliers[i] * nums[n - 1 - i + j] + d[i+1][j]);
            }
        }
        return d[0][0];
    }
};