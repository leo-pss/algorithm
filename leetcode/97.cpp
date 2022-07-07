#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n + m != s3.size()) return false;
        vector<vector<int>> d(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 && j == 0) d[i][j] = true;
                else if(i == 0) d[i][j] = d[i][j-1] && (s2[j-1] == s3[i+j-1]);
                else if(j == 0) d[i][j] = d[i-1][j] && (s1[i-1] == s3[i+j-1]);
                else d[i][j] = (d[i][j-1] && (s2[j-1] == s3[i+j-1])) || (d[i-1][j] && (s1[i-1] == s3[i+j-1]));
            }
        }
        return d[n][m];
    }
};