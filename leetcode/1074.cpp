#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int solve(vector<int>& sum, int target){
        unordered_map<int, int> umap;
        int cnt = 0;
        int ret = 0;
        for(int i = 0; i < sum.size(); i++){
            cnt += sum[i];
            if(cnt == target) ret++;
            if(umap.find(cnt-target) != umap.end()){
                ret += umap[cnt-target];
            }
            umap[cnt]++;
        }
        return ret;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            vector<int> sum(m, 0);
            for(int j = i; j < n; j++){
                for(int k = 0; k < m; k++){
                    sum[k] += matrix[j][k];
                }
                answer += solve(sum, target);
            }
        }
        return answer;
    }
};