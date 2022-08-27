#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int answer = -1e9;
        
        for(int l = 0; l < n; l++){
            vector<int> sum(m);
            for(int r = l; r < n; r++){
                int kadane = 0, max_kadane = -1e9;
                for(int i = 0; i < m; i++){
                    sum[i] += matrix[r][i];
                    kadane = max(kadane + sum[i], sum[i]);
                    max_kadane = max(max_kadane, kadane);
                }
                if(max_kadane <= k){
                    answer = max(answer, max_kadane);
                    if(answer == k) return answer;
                    continue;
                }
                set<int> s;
                int row_sum = 0, row_max = -1e9;
                s.insert(0);
                for(int i = 0; i < m; i++){
                    row_sum += sum[i];
                    auto it = s.lower_bound(row_sum - k);
                    if(it != s.end()) answer = max(answer, row_sum - *it);
                    s.insert(row_sum);
                }
                if(answer == k) return answer;
            }
        }
        return answer;
    }
};