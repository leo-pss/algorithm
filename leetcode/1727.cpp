#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h(m, 0);
        int answer = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0) h[j] = 0;
                else h[j]++;
            }
            auto tmp = h;
            sort(tmp.begin(), tmp.end());
            for(int j = 0; j < m; j++){
                answer = max(answer, tmp[j] * (m - j));
            }
        }
        return answer;
    }
};