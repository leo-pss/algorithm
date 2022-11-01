#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> d(n+1, vector<int>(m, 0));
        
        vector<int> answer(m, 0);
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (i == n) {
                    d[i][j] = j;
                    continue;
                }
                int next = j + grid[i][j];
                if (next < 0 || next > m - 1 || grid[i][j] != grid[i][next]) d[i][j] = -1;
                else d[i][j] = d[i + 1][next];
                
                if(i == 0) answer[j] = d[i][j];
            }
        }
        
        return answer;
    }
};