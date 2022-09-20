#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int> > d(n, vector<int>(m, 0));
        int answer = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0) d[i][j] = (nums1[i] == nums2[j]);
                else if(nums1[i] == nums2[j]) d[i][j] = max(d[i][j], d[i-1][j-1]+1);
                else d[i][j] = 0;
                answer = max(answer, d[i][j]);
            }
        }
        return answer;
    }
};