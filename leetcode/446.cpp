#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        vector<unordered_map<long long, int>> d(n); 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long dif = (long long) nums[i] - nums[j];
                int cnt;
                if(d[j].find(dif) != d[j].end()) cnt = d[j][dif];
                else cnt = 0;
                d[i][dif] += (cnt + 1);
                answer += cnt;
            }
        }
        return answer;
    }
};