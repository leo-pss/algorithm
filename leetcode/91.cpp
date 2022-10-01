#include <vector>
#include <string>

using namespace std; 

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<vector<int>> d(n, vector<int>(2, 0));
        if(s[0] == '0') return 0;
        d[0][0] = 1;
        for(int i = 1; i < n; i++){
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')){
                if(i >= 2) d[i][1] = d[i-2][0] + d[i-2][1];
                else d[i][1] = 1;
            }
            if(s[i] != '0') d[i][0] = d[i-1][0] + d[i-1][1];
        }
        return d[n-1][0] + d[n-1][1];
    }
};