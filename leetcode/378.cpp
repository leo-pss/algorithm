#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        for(int i = 0; i < min(m, k); i++){
            pq.push({matrix[i][0], i, 0});
        }
        int answer;
        for(int i = 1; i <= k; i++){
            auto tmp = pq.top(); pq.pop();
            int r = tmp[1], c = tmp[2];
            answer = tmp[0];
            if(c < n - 1) pq.push({matrix[r][c+1], r, c+1});
        }
        return answer;
    }
};