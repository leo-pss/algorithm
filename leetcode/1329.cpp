#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++){
            int size = min(n - i, m);
            vector<int> tmp(size);
            for(int j = 0; j < size; j++){
                tmp[j] = mat[i + j][j];
            }
            sort(tmp.begin(), tmp.end());
            for(int j = 0; j < size; j++){
                mat[i + j][j] = tmp[j];
            }
        }
        for(int i = 1; i < m; i++){
            int size = min(n, m - i);
            vector<int> tmp(size);
            for(int j = 0; j < size; j++){
                tmp[j] = mat[j][i+j];
            }
            sort(tmp.begin(), tmp.end());
            for(int j = 0; j < size; j++){
                mat[j][i+j] = tmp[j];
            }
        }
        return mat;
    }
};